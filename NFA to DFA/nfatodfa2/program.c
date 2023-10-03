#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an NFA state.
typedef struct {
  char name;
  char** transitions;
  int num_transitions;
} NfaState;

// Structure to represent a DFA state.
typedef struct {
  char name;
  char** transitions;
  int num_transitions;
  int is_final;
} DfaState;

// Creates a new NFA state.
NfaState* create_nfa_state(char name) {
  NfaState* state = malloc(sizeof(NfaState));
  state->name = name;
  state->transitions = NULL;
  state->num_transitions = 0;
  return state;
}

// Adds a transition to an NFA state.
void add_nfa_transition(NfaState* state, char* input, char* next_state_name) {
  state->transitions = realloc(state->transitions, (state->num_transitions + 1) * sizeof(char*));
  state->transitions[state->num_transitions] = malloc(sizeof(char) * (strlen(input) + 1));
  strcpy(state->transitions[state->num_transitions], input);
  state->num_transitions++;

  state->transitions = realloc(state->transitions, (state->num_transitions + 1) * sizeof(char*));
  state->transitions[state->num_transitions] = malloc(sizeof(char) * (strlen(next_state_name) + 1));
  strcpy(state->transitions[state->num_transitions], next_state_name);
  state->num_transitions++;
}

// Creates a new DFA state.
DfaState* create_dfa_state(char name) {
  DfaState* state = malloc(sizeof(DfaState));
  state->name = name;
  state->transitions = NULL;
  state->num_transitions = 0;
  state->is_final = 0;
  return state;
}

// Adds a transition to a DFA state.
void add_dfa_transition(DfaState* state, char* input, char* next_state_name) {
  state->transitions = realloc(state->transitions, (state->num_transitions + 1) * sizeof(char*));
  state->transitions[state->num_transitions] = malloc(sizeof(char) * (strlen(input) + 1));
  strcpy(state->transitions[state->num_transitions], input);
  state->num_transitions++;

  state->transitions = realloc(state->transitions, (state->num_transitions + 1) * sizeof(char*));
  state->transitions[state->num_transitions] = malloc(sizeof(char) * (strlen(next_state_name) + 1));
  strcpy(state->transitions[state->num_transitions], next_state_name);
  state->num_transitions++;
}

// Converts an NFA to a DFA.
DfaState* nfa_to_dfa(NfaState* nfa_start_state) {
  // Create a new DFA state to represent the start state.
  DfaState* dfa_start_state = create_dfa_state(nfa_start_state->name);

  // Add a transition to the DFA start state for each input symbol.
  for (int i = 0; i < nfa_start_state->num_transitions; i++) {
    add_dfa_transition(dfa_start_state, nfa_start_state->transitions[i], nfa_start_state->transitions[i + 1]);
  }

  // Create a queue to store the DFA states that need to be explored.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Add this line to include the header file directory
#include "path/to/header/directory/queue.h"

// Structure to represent an NFA state.
typedef struct {
    char name;
    char** transitions;
    int num_transitions;
} NfaState;

// Structure to represent a DFA state.
typedef struct {
    char name;
    char** transitions;
    int num_transitions;
    int is_final;
} DfaState;

// Creates a new NFA state.
NfaState* create_nfa_state(char name) {
    NfaState* state = malloc(sizeof(NfaState));
    state->name = name;
    state->transitions = NULL;
    state->num_transitions = 0;
    return state;
}

// Adds a transition to an NFA state.
void add_nfa_transition(NfaState* state, char* input, char* next_state_name) {
    state->transitions = realloc(state->transitions, (state->num_transitions + 1) * sizeof(char*));
    state->transitions[state->num_transitions] = malloc(sizeof(char) * (strlen(input) + 1));
    strcpy(state->transitions[state->num_transitions], input);
    state->num_transitions++;

    state->transitions = realloc(state->transitions, (state->num_transitions + 1) * sizeof(char*));
    state->transitions[state->num_transitions] = malloc(sizeof(char) * (strlen(next_state_name) + 1));
    strcpy(state->transitions[state->num_transitions], next_state_name);
    state->num_transitions++;
}

// Creates a new DFA state.
DfaState* create_dfa_state(char name) {
    DfaState* state = malloc(sizeof(DfaState));
    state->name = name;
    state->transitions = NULL;
    state->num_transitions = 0;
    state->is_final = 0;
    return state;
}

// Adds a transition to a DFA state.
void add_dfa_transition(DfaState* state, char* input, char* next_state_name) {
    state->transitions = realloc(state->transitions, (state->num_transitions + 1) * sizeof(char*));
    state->transitions[state->num_transitions] = malloc(sizeof(char) * (strlen(input) + 1));
    strcpy(state->transitions[state->num_transitions], input);
    state->num_transitions++;

    state->transitions = realloc(state->transitions, (state->num_transitions + 1) * sizeof(char*));
    state->transitions[state->num_transitions] = malloc(sizeof(char) * (strlen(next_state_name) + 1));
    strcpy(state->transitions[state->num_transitions], next_state_name);
    state->num_transitions++;
}

// Converts an NFA to a DFA.
DfaState* nfa_to_dfa(NfaState* nfa_start_state) {
    // Create a new DFA state to represent the start state.
    DfaState* dfa_start_state = create_dfa_state(nfa_start_state->name);

    // Add a transition to the DFA start state for each input symbol.
    for (int i = 0; i < nfa_start_state->num_transitions; i++) {
        add_dfa_transition(dfa_start_state, nfa_start_state->transitions[i], nfa_start_state->transitions[i + 1]);
    }

    // Create a queue to store the DFA states that need to be explored.
    enqueue(queue, dfa_start_state);

    // While there are still DFA states to be explored:
    while (!is_queue_empty(queue)) {
        // Dequeue the current DFA state.
        DfaState* current_dfa_state = dequeue(queue);

        // For each input symbol:
        #define ALPHABET_SIZE 26
            // Find the set of DFA states that the NFA can transition to from the
            // current DFA state on the given input symbol.

        DfaState* next_dfa_states = create_dfa_state(' ');
for (int i = 0; i < current_dfa_state->num_transitions; i++) {
    if (current_dfa_state->transitions[i][0] == alphabet[i]) {
        add_to_set(next_dfa_states, current_dfa_state->transitions[i][1]);
    }
}

// If the set of next DFA states is not already in the DFA, create a new DFA
// state for it.
// Define a set to keep track of the DFA states that have been explored.
Set* dfa_states = create_set();
if (next_dfa_state == NULL) {
    next_dfa_state = create_dfa_state(get_new_state_name());
  enqueue(queue, dfa_start_state);

  // While there are still DFA states to be explored:
  while (!is_queue_empty(queue)) {
    // Dequeue the current DFA state.
    DfaState* current_dfa_state = dequeue(queue);

    // For each input symbol:
    #define ALPHABET_SIZE 26
      // Find the set of DFA states that the NFA can transition to from the
      // current DFA state on the given input symbol.

    DfaState* next_dfa_states = create_dfa_state(' ');
for (int i = 0; i < current_dfa_state->num_transitions; i++) {
  if (current_dfa_state->transitions[i][0] == alphabet[i]) {
    add_to_set(next_dfa_states, current_dfa_state->transitions[i][1]);
  }
}

// If the set of next DFA states is not already in the DFA, create a new DFA
// state for it.
// Define a set to keep track of the DFA states that have been explored.
Set* dfa_states = create_set();
if (next_dfa_state == NULL) {
  next_dfa_state = create_dfa_state(get_new_state_name());
  add_to_set(dfa_states, next_dfa_state);
}

// Add a transition to the current DFA state to the next DFA state on the
// given input symbol.
add_dfa_transition(current_dfa_state, alphabet[i], next_dfa_state->name);

// If any of the next DFA states are final states, mark the current DFA state
// as a final state.
for (int i = 0; i < next_dfa_state->num_transitions; i++) {
  if (next_dfa_state->transitions[i][1] == 'f') {
    current_dfa_state->is_final = 1;
  }
}

// Add the next DFA state to the queue if it has not already been explored.
if (!is_set_member(queue->states, next_dfa_state)) {
  enqueue(queue, next_dfa_state);
}
  }

  return dfa_start_state;
}

// Prints the DFA to the console.
void print_dfa(DfaState* dfa_start_state) {
  printf("DFA:\n");
  printf("Start state: %c\n", dfa_start_state->name);
  printf("Final states: ");
  for (int i = 0; i < dfa_states->size; i++) {
    DfaState* dfa_state = dfa_states->states[i];
    if (dfa_state->is_final) {
      printf("%c ", dfa_state->name);
    }
  }
  printf("\n");
  printf("Transitions:\n");
  for (int i = 0; i < dfa_states->size; i++) {
    DfaState* dfa_state = dfa_states->states[i];
    for (int j = 0; j < dfa_state->num_transitions; j++) {
      printf("%c -> %c on %c\n", dfa_state->name, dfa_state->transitions[j][1], dfa_state->transitions[j][0]);
    }
  }
}

// Main function.
int main() {
  // Get the NFA from the user.
  NfaState* nfa_start_state = create_nfa_state('q0');

  char input[100];
  printf("Enter the NFA transitions (e.g., q0 0 q1): ");
  scanf("%s", input);

  while (strlen(input) > 0) {
    char* state_name = strtok(input, " ");
    char* input_symbol = strtok(NULL, " ");
    char* next_state_name = strtok(NULL, " ");

    add_nfa_transition(nfa_start_state, input_symbol, next_state_name);

    printf("Enter the next NFA transition (or leave blank to finish): ");
    scanf("%s", input);
  }

  // Convert the NFA to a DFA.
  DfaState* dfa_start_state = nfa_to_dfa(nfa_start_state);

  // Print the DFA to the console.
  print_dfa(dfa_start_state);

  return 0;
}