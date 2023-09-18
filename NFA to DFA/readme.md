#### How to run this program
        gcc nfadfa.c
        ./a.out

#### Algorithm

1. Initialize all data structures:

        Set all elements of Fa, states, and new_state to -1.
        Initialize max_inp to -1.
        Initialize no_stat to 0.

2. Read the NFA transitions and states from "input.txt":

        Open "input.txt" for reading (fopen).
        Parse the input line by line.
        Identify state transitions, final states, and input symbols.
        Populate Fa and states accordingly.
        Determine the maximum input symbol encountered.

3. Perform the NFA to DFA conversion using subset construction:

        Iterate through each state of the NFA.
        For each input symbol:
             Determine the epsilon-closure (all reachable states from the current state on epsilon transitions).
             Calculate the transition set for the current state and input symbol.
             Check if the resulting set of states is new or already seen in the DFA.
                   If new, create a new DFA state.
                      Otherwise, use the existing DFA state.
             Update the DFA transition table.

4. Print the resulting DFA:

        Display the DFA transition table, including input symbols and transitions.
        Output the total number of DFA states.
        List the final states of the DFA.

5. Close the input file.

#### Explanation

Certainly! Let's go through the provided C program line by line, explaining each part of it:

```c
#include <stdio.h>
```
- This line includes the standard input/output library, which is necessary for reading from and writing to files and for printing to the console.

```c
int Fa[10][10][10], states[2][10], row = 0, col = 0, sr = 0, sc = 0, th = 0, in, stat, new_state[10][10], max_inp = -1, no_stat;
FILE *fp;
```
- This declares several global variables and arrays. Here's what each of them represents:
  - `Fa[10][10][10]`: A 3D array used to represent the transitions of the finite automaton.
  - `states[2][10]`: A 2D array to store NFA states. The first row is used for temporary storage, and the second row is for storing final states.
  - `row`, `col`, `sr`, `sc`, `th`: Variables used for tracking various indices and counts.
  - `in`: A variable used to read integers from the input file.
  - `stat`: A variable used to track the number of states.
  - `new_state[10][10]`: A 2D array used for constructing new states during the NFA to DFA conversion.
  - `max_inp`: Tracks the maximum input symbol encountered.
  - `no_stat`: Stores the number of states.

```c
int search(int search_var)
{
    int i;
    for (i = 0; i < no_stat; i++)
        if (search_var == states[1][i])
            return 1;
    return 0;
}
```
- This is a function named `search` that takes an integer `search_var` as input. It searches for `search_var` in the second row (`states[1]`) of the `states` array, which contains final states. If it finds a match, it returns `1`, indicating that the state is a final state; otherwise, it returns `0`.

```c
int sort(int *arr, int count)
{
    int temp, i, j;
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (arr[i] >= arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return 0;
}
```
- This is a function named `sort` that takes an integer array `arr` and its size `count` as inputs. It sorts the array in ascending order using a simple bubble sort algorithm.

```c
int checkcon(int *arr, int *count)
{
    int i, temp, j, k, c, t, m;
    for (i = 0; i < *count; i++)
    {
        if (arr[i] > row)
        {
            // ...
        }
    }
    c = 0;
    for (i = 0; arr[i] != -1; i++)
        c++;
    *count = c;
    return 0;
}
```
- This is a function named `checkcon` that checks and updates a state set represented by an integer array `arr`. It ensures that there are no duplicates in the set and that it's sorted.

```c
int remove_duplicate(int *arr, int *count)
{
    int i, j = 0;
    for (i = 1; i < *count; i++)
    {
        if (arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }
    *count = j + 1;
    return 0;
}
```
- This is a function named `remove_duplicate` that removes duplicate elements from an integer array `arr` and updates the count accordingly.

```c
int check(int i, int j, int c, int *name)
{
    int t, l, f;
    for (l = 0; l <= stat; l++)
    {
        // ...
    }
    return 0;
}
```
- This is a function named `check` that checks whether a set of transitions is a new state or not during the NFA to DFA conversion.

```c
int trans(int i, int j, int t, int c, int *count, int *arr)
{
    int k = 0, co, temp;
    *count = 0;
    for (k = 0; k < c; k++)
    {
        temp = Fa[i][j][k];
        co = 0;
        while (Fa[temp][t][co] != -1)
        {
            arr[*count] = Fa[temp][t][co++];
            (*count)++;
        }
    }
    return 0;
}
```
- This is a function named `trans` that computes the transition output for a particular input on a set of states.

```c
int nfa2dfa(int start, int end)
{
    int j, t, c, i, k, count, arr[10], name, l;
    for (i = start; i <= end; i++)
    {
        for (j = 0; j <= max_inp; j++)
        {
            c = 0;
            t = 0;
            while (Fa[i][j][t] >= 0)
            {
                t++;
                c++;
            }
            if (c > 1)
            {
                if (check(i, j, c, &name) == 0)
                {
                    // ...
                }
                else
                {
                    // ...
                }
            }
        }
    }
    return 0;
}
```
- This is the `nfa2dfa` function that performs the NFA to DFA conversion using the subset construction method. It operates on a range of NFA states specified by `start` and `end`.

```c
int main()
{
    int i, j, k, flag = 0, start, end;
    char c, ch;
    fp = fopen("input.txt", "r+");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 10; j++)
            states[i][j] = -1;
    // ...
    return 0;
}
```
- This is the `main` function, the entry point of the program.
- It opens a file named "input.txt" for reading and writing.
- It initializes the `states` array, `

new_state` array, and `Fa` array to -1.
- It reads input from the file and processes it to populate the arrays.
- Finally, it performs the NFA to DFA conversion using the `nfa2dfa` function and prints the resulting DFA.

The program is essentially a C implementation of the NFA to DFA conversion algorithm, which is used to convert a Non-Deterministic Finite Automaton (NFA) into a Deterministic Finite Automaton (DFA). It does so by reading the NFA's transition functions and states from an input file, constructing the DFA transition table, and printing the resulting DFA.

##### Theory

### What is NFA ?

NFA stands for "Nondeterministic Finite Automaton." It is a mathematical model or abstract machine used in computer science and theoretical computer science to describe and recognize patterns or sets of strings. NFAs are a type of finite automaton, which means they operate on an input alphabet and have a finite number of states.

Here are the key characteristics of an NFA:

1. **States:** An NFA has a finite set of states. These states represent different configurations or conditions that the machine can be in at any given time.

2. **Transitions:** For each state, an NFA can have multiple possible transitions based on the input symbol. Unlike a Deterministic Finite Automaton (DFA), where there is at most one transition for each input symbol from a given state, an NFA can have zero or more transitions for the same input symbol from the same state. This non-determinism allows for more flexibility in recognizing patterns.

3. **Epsilon Transitions:** An NFA can also have epsilon (ε) transitions, which are transitions that don't consume an input symbol. These transitions allow the machine to move from one state to another without reading an input symbol.

4. **Accept States:** Like DFAs, NFAs have designated accept states (or final states). When the machine reaches an accept state after processing the entire input string, it accepts the input string as part of the language it recognizes.

NFAs are often used in regular expressions and pattern matching algorithms because their non-deterministic nature makes it easier to describe certain patterns that are more complex to represent with DFAs. However, it's important to note that any NFA can be converted into an equivalent DFA (Deterministic Finite Automaton), which will recognize the same language. This conversion is done using algorithms like the subset construction method, as seen in your C program.

In summary, an NFA is a computational model used for recognizing patterns or sets of strings, and it allows for non-deterministic choices in the state transitions, which can simplify the expression of certain patterns.

### What is DFA ?

DFA stands for "Deterministic Finite Automaton." It is a mathematical model and a type of finite automaton used in computer science and theoretical computer science to recognize and process strings of symbols. DFAs are simpler and more constrained compared to non-deterministic finite automata (NFAs).

Here are the key characteristics of a DFA:

1. **States:** A DFA has a finite set of states. These states represent different configurations or conditions that the machine can be in at any given time.

2. **Alphabet:** It operates on an input alphabet, which is a finite set of symbols or characters. Each transition from one state to another is associated with a specific input symbol.

3. **Transitions:** For each state in the DFA, there is exactly one defined transition for each symbol in the alphabet. This means that, given the current state and an input symbol, the DFA will always move to a unique next state.

4. **Deterministic:** The term "deterministic" means that, at any step of processing, the DFA knows exactly which state to transition to based on the current state and the input symbol. There is no ambiguity or non-deterministic choice involved.

5. **Accept States:** DFAs have designated accept states (or final states). When the machine reaches an accept state after processing the entire input string, it accepts the input string as part of the language it recognizes. If it doesn't reach an accept state, the input string is rejected.

DFAs are used in various applications, including lexical analysis in compilers, pattern matching, and string recognition tasks. They are particularly efficient for recognizing regular languages, which are a class of languages that can be defined by regular expressions. Regular expressions and DFAs have a close relationship, and it's possible to convert a regular expression into an equivalent DFA and vice versa.

In summary, a DFA is a computational model that recognizes and processes strings of symbols in a deterministic manner, where each state transition is uniquely determined by the current state and the input symbol. This deterministic nature simplifies the design and analysis of the machine but may require more states than a non-deterministic counterpart to recognize certain languages.

### NFA Vs DFA 

NFA (Non-deterministic Finite Automaton) and DFA (Deterministic Finite Automaton) are two types of finite automata used in computer science and theoretical computer science to recognize and process strings of symbols. They have several differences in terms of their characteristics and capabilities:

1. **Determinism:**
   - **DFA:** Deterministic Finite Automata are deterministic, meaning that for a given state and input symbol, there is exactly one transition to the next state.
   - **NFA:** Non-deterministic Finite Automata are non-deterministic, allowing multiple possible transitions for a given state and input symbol.

2. **Transitions:**
   - **DFA:** DFA has a single, unique transition for each state and input symbol in its alphabet.
   - **NFA:** NFA can have multiple transitions for a state and input symbol, or it can have epsilon (ε) transitions, which are transitions that occur without consuming any input symbol.

3. **Acceptance:**
   - **DFA:** DFA accepts an input string if it ends up in an accept state after processing the entire string.
   - **NFA:** NFA accepts an input string if there exists at least one path (sequence of transitions) that leads to an accept state after processing the entire string.

4. **Size:**
   - **DFA:** DFAs typically have more states than equivalent NFAs for the same language. This can make them larger and less space-efficient.
   - **NFA:** NFAs are often more compact than equivalent DFAs due to their non-deterministic nature.

5. **Language Recognition:**
   - **DFA:** DFAs recognize exactly the class of regular languages. They are suitable for recognizing simple patterns and regular expressions.
   - **NFA:** NFAs can recognize the same class of regular languages as DFAs but may require fewer states for certain languages. They are more expressive due to their non-determinism.

6. **Conversion:**
   - **DFA to NFA:** It is straightforward to convert a DFA into an equivalent NFA.
   - **NFA to DFA:** Converting an NFA into an equivalent DFA can be more complex and may result in a larger DFA due to state explosion.

7. **Design Complexity:**
   - **DFA:** Designing a DFA can be simpler and more intuitive for certain regular languages.
   - **NFA:** NFAs can be more convenient for representing languages with optional or non-sequential elements.

8. **Applications:**
   - **DFA:** DFAs are commonly used in lexical analysis (e.g., parsing programming languages), simple pattern matching, and tasks involving regular expressions.
   - **NFA:** NFAs are used in various applications, including regular expression engines, lexical analyzers, and certain parsing tasks.

In summary, DFAs are deterministic and have unique transitions, making them simpler to analyze and potentially larger in size. NFAs are non-deterministic, allowing for more compact representations but requiring additional mechanisms to determine acceptance. Both have their advantages and are used in different contexts depending on the complexity of the language to be recognized and processed.

### NFA to DFA 

Converting a Non-deterministic Finite Automaton (NFA) to a Deterministic Finite Automaton (DFA) involves several steps. The goal of this process is to create an equivalent DFA that recognizes the same language as the original NFA. Here are the general steps to convert an NFA to a DFA:

**Step 1: Understand the NFA**
Before you start the conversion process, make sure you have a clear understanding of the NFA's states, transitions, start state, and accept states.

**Step 2: Create the DFA States**
In a DFA, each state represents a unique subset of states from the NFA. The power set (set of all subsets) of the NFA's states will be used to create the DFA states.

- Start with the ε-closure (epsilon closure) of the NFA's start state. This ε-closure represents the initial state of the DFA.
- Create a table or a mapping to keep track of the DFA states and their corresponding NFA subsets.

**Step 3: Determine Transitions**
For each DFA state that you create, determine the transitions for each input symbol in the alphabet. Follow these sub-steps:

- For each input symbol 'a' in the alphabet:
  - Calculate the ε-closure of the NFA states that can be reached from the current DFA state using 'a' as input.
  - This ε-closure represents the next state in the DFA for input 'a'.
- Add these transitions to the DFA transition table or mapping.

**Step 4: Identify Accept States**
An accept state in the DFA corresponds to a subset of NFA states that contains at least one accept state. Identify which DFA states are accept states based on this criterion.

**Step 5: Complete the DFA**
Continue steps 3 and 4 for all DFA states until you have determined transitions for every state in the DFA.

**Step 6: Minimize the DFA (Optional)**
After creating the DFA, you can optionally minimize it to remove redundant states and transitions, resulting in a more efficient DFA. Minimization techniques like state equivalence and table filling can be applied.

**Step 7: Define the Final DFA**
Once you have completed the DFA construction, you will have a clear definition of the DFA's states, transitions, start state, accept states, and alphabet.

**Step 8: Example Testing**
To ensure the correctness of your conversion, test the DFA with various input strings to confirm that it accepts the same language as the original NFA.

It's important to note that the conversion from NFA to DFA may result in a larger DFA with more states than the original NFA, but it will recognize the same language. The use of ε-closures is a key concept in this process to track transitions and states.