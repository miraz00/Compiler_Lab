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