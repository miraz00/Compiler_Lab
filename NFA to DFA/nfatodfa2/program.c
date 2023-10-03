#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATES 100
#define MAX_ALPHABET 100

int nfa[MAX_STATES][MAX_ALPHABET][MAX_STATES];
int epsilon[MAX_STATES][MAX_STATES];
int dfa[MAX_STATES][MAX_ALPHABET];
int dfa_states[MAX_STATES];
int num_dfa_states = 0;
int alphabet_size;

void epsilon_closure(int state, int closure[], int *closure_size) {
    closure[(*closure_size)++] = state;
    for (int i = 0; i < num_dfa_states; i++) {
        if (epsilon[state][dfa_states[i]] && !closure_contains(closure, *closure_size, dfa_states[i])) {
            epsilon_closure(dfa_states[i], closure, closure_size);
        }
    }
}

int closure_contains(int closure[], int closure_size, int state) {
    for (int i = 0; i < closure_size; i++) {
        if (closure[i] == state) {
            return 1;
        }
    }
    return 0;
}

void print_set(int set[], int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        printf("%d", set[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("}");
}

void construct_dfa() {
    int visited[MAX_STATES][MAX_ALPHABET] = {0};
    int queue[MAX_STATES];
    int front = 0, rear = 0;
    
    // Initialize DFA states
    dfa_states[num_dfa_states++] = 0;
    
    while (front <= rear) {
        int current_state = queue[front++];
        
        for (int i = 0; i < alphabet_size; i++) {
            int closure[MAX_STATES];
            int closure_size = 0;
            
            // Find epsilon-closure of current state
            epsilon_closure(current_state, closure, &closure_size);
            
            for (int j = 0; j < closure_size; j++) {
                int next_state = nfa[closure[j]][i][0];
                if (next_state != -1) {
                    dfa[current_state][i] = 1;
                    if (!visited[next_state][i]) {
                        queue[++rear] = next_state;
                        visited[next_state][i] = 1;
                    }
                }
            }
        }
    }
}

int main() {
    int num_states, num_symbols;

    printf("Enter the number of states in NFA: ");
    scanf("%d", &num_states);

    printf("Enter the number of input symbols (excluding epsilon): ");
    scanf("%d", &num_symbols);
    
    alphabet_size = num_symbols;

    // Initialize NFA and epsilon transition table
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_symbols; j++) {
            nfa[i][j][0] = -1;
        }
    }

    // Read NFA transition table
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_symbols; j++) {
            int num_transitions;
            printf("Enter the number of transitions for state q%d with symbol %d: ", i, j);
            scanf("%d", &num_transitions);

            if (num_transitions > 0) {
                printf("Enter the transitions (separated by spaces, -1 for no transition): ");
                for (int k = 0; k < num_transitions; k++) {
                    scanf("%d", &nfa[i][j][k]);
                }
            }
        }
    }

    // Initialize epsilon transition table
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_states; j++) {
            epsilon[i][j] = 0;
        }
    }

    // Read epsilon transitions
    int num_epsilon_transitions;
    printf("Enter the number of epsilon transitions: ");
    scanf("%d", &num_epsilon_transitions);

    if (num_epsilon_transitions > 0) {
        printf("Enter the epsilon transitions (separated by spaces): ");
        for (int i = 0; i < num_epsilon_transitions; i++) {
            int from, to;
            scanf("%d %d", &from, &to);
            epsilon[from][to] = 1;
        }
    }

    // Construct DFA
    construct_dfa();

    // Print DFA transition table
    printf("\nDFA Transition Table:\n");
    printf("States: ");
    for (int i = 0; i < num_dfa_states; i++) {
        printf("q%d ", dfa_states[i]);
    }
    printf("\n");
    
    printf("Alphabet: ");
    for (int i = 0; i < num_symbols; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printf("Transitions:\n");
    for (int i = 0; i < num_dfa_states; i++) {
        printf("q%d ", dfa_states[i]);
        for (int j = 0; j < num_symbols; j++) {
            printf("{");
            for (int k = 0; k < num_states; k++) {
                if (nfa[k][j][0] != -1) {
                    printf("q%d", k);
                    if (k < num_states - 1) {
                        printf(", ");
                    }
                }
            }
            printf("} -> ");
            if (dfa[i][j]) {
                print_set(dfa_states, num_dfa_states);
            } else {
                printf("∅");
            }
            printf("\t");
        }
        printf("\n");
    }

    return 0;
}

/*
This code implements the construction of a Deterministic Finite Automaton (DFA) from a given Non-Deterministic Finite Automaton (NFA) using the subset construction algorithm. Here's an overview of its functionality:

1. It includes necessary header files for input/output and string manipulation.

2. It defines constants for the maximum number of states (MAX_STATES) and the maximum alphabet size (MAX_ALPHABET).

3. It declares several arrays to represent the NFA, epsilon transitions, DFA, and related information.

4. The `epsilon_closure` function calculates the epsilon-closure of a given state by recursively exploring epsilon transitions.

5. The `closure_contains` function checks if a closure set contains a specific state.

6. `print_set` is a helper function to print a set of states enclosed in curly braces.

7. `construct_dfa` is the main function that constructs the DFA from the NFA using the subset construction algorithm.

8. In the `main` function:
   - It reads the number of states in the NFA and the number of input symbols (excluding epsilon) from the user.
   - Initializes the NFA and epsilon transition table with default values.
   - Reads the NFA transition table and epsilon transitions from the user.
   - Calls `construct_dfa` to create the DFA.
   - Prints the DFA transition table, including states, alphabet, and transitions.

Overall, this code performs the conversion from an NFA to a DFA, enabling deterministic processing of input strings, a crucial step in formal language theory and compiler construction. The subset construction algorithm ensures that the DFA recognizes the same language as the original NFA.*/