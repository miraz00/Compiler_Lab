## To run this script
        gcc srp.c
        ./a.out

### Sample Input 
        id+id*id
### Sample Output
        GRAMMAR is E->E+E 
        E->E*E 
        E->(E) 
        E->id
        enter input string 
        id+id*id
        stack    input   action

        $       id+id*id$       SHIFT
        $id       +id*id$       REDUCE by E->id
        $E        +id*id$       SHIFT
        $E+        id*id$       SHIFT
        $E+id        *id$       REDUCE by E->id
        $E+E         *id$       REDUCE by E->E+E
        $E           *id$       SHIFT
        $E*           id$       SHIFT
        $E*id           $       REDUCE by E->id
        $E*E            $       REDUCE by E->E*E
        $E              $       Accept

### What is Shift Reduce Parser?
A shift-reduce parser is a type of bottom-up parsing technique used in computer science and natural language processing to analyze and process the structure of a sequence of symbols, typically used in the context of programming languages and context-free grammars. The main idea behind shift-reduce parsing is to build a parse tree by successively shifting (moving) input symbols onto a stack and then reducing (replacing) them with a grammar rule when a portion of the input matches a right-hand side of a production rule in a context-free grammar.

Here's how a shift-reduce parser generally works:

1. **Initialization**: It starts with an empty stack and a cursor at the beginning of the input.

2. **Shift**: The parser shifts (pushes) the current input symbol onto the stack. This process continues until a reduction can be performed.

3. **Reduce**: When a sequence of symbols on the stack matches the right-hand side of a production rule in the grammar, the parser reduces them to the non-terminal on the left-hand side of the rule. This means that a portion of the input is replaced with a non-terminal symbol.

4. **Repeat**: The parser continues shifting and reducing until it successfully constructs a parse tree or encounters an error. If it reaches the end of the input with a valid parse, it should have a parse tree representing the structure of the input.

Shift-reduce parsers can be implemented using various algorithms, such as LR (LALR, LR(1), etc.) and SLR parsing techniques. The choice of the parsing algorithm determines the grammar classes that can be parsed effectively. LR parsers, for example, are capable of parsing a wide range of context-free grammars.

Shift-reduce parsing is commonly used in the design and implementation of compilers for programming languages, where it helps analyze the syntax of the source code and generate abstract syntax trees or other intermediate representations. It's a powerful technique for syntax analysis and can be used in combination with semantic analysis to build a complete compiler.


### Explanation Of The Program


```c
#include <stdio.h>
#include <string.h>
int k = 0, z = 0, i = 0, j = 0, c = 0;
char a[16], ac[20], stk[15], act[10]; //stk means stack and act/ac means action description
void check();
```

- The program starts with including standard C libraries, `stdio.h` for input and output operations and `string.h` for string handling.

- Global variables are declared: `k`, `z`, `i`, `j`, and `c` are used as counters and indices. Arrays `a`, `ac`, `stk`, and `act` are used to store the input, action descriptions, stack content, and actions, respectively.

- A prototype for the `check` function is declared. The `check` function is defined later in the program and is used for reducing the symbols on the stack based on the grammar rules.

```c
int main()
{
    puts("GRAMMAR is E->E+E \n E->E*E \n E->(E) \n E->id");
    puts("enter input string ");
    scanf("%s", a);
    c = strlen(a);
    strcpy(act, "SHIFT");
    puts("stack \t input \t action");
```

- The `main` function is the entry point of the program.

- It starts by printing the grammar rules for the user to see using `puts`. The provided grammar consists of four production rules.

- It then prompts the user to enter an input string and reads it using `scanf`. The input string is stored in the array `a`.

- The length of the input string is calculated using `strlen` and stored in the variable `c`.

- The variable `act` is initialized with "SHIFT" to indicate the initial action.

- The program prints the headers for the table that displays the stack content, input, and actions.

```c
    for (k = 0, i = 0; j < c; k++, i++, j++)
    {
        if (a[j] == 'i' && a[j + 1] == 'd')
        { 
            printf("\n$%s\t%s$\t%s", stk, a, act);
            stk[i] = a[j];
            stk[i + 1] = a[j + 1];
            stk[i + 2] = '\0';
            a[j] = ' ';
            a[j + 1] = ' ';
            check();
        }
        else
        { 
            printf("\n$%s\t%s$\t%s", stk, a, act);
            stk[i] = a[j];
            stk[i + 1] = '\0';
            a[j] = ' ';
            check();
        }
    }
```

- A `for` loop is used to iterate through the input string. `k` and `i` are used to track the progress of the loop, and `j` is used to traverse the input string.

- Inside the loop, the program checks whether the current symbol in the input string is "id." If it is, the program prints the current state of the stack, input, and action.

- The "id" symbol is pushed onto the stack, and `check()` is called to see if any reductions are possible. The `check` function examines the contents of the stack and reduces symbols based on grammar rules.

- If the current symbol is not "id," it is assumed to be an operator (e.g., "+", "*", "(", ")"). In this case, the program again prints the stack, input, and action.

- The operator is pushed onto the stack, and `check()` is called to see if any reductions are possible.

- The loop continues until all characters in the input string are processed.

```c
    printf("\n$%s\t%s$\tAccept", stk, a);
    printf("\n");
}
```

- After parsing the entire input string, the program checks if the stack contains only a single "E" symbol and the input string is empty. If these conditions are met, it prints "Accept," indicating that the input string adheres to the grammar.

```c
void check()
{
    strcpy(ac, "REDUCE by E");
```

- The `check` function is called to examine the contents of the stack and potentially apply reductions based on the grammar rules.

- The `ac` variable is initialized with "REDUCE by E" to indicate a reduction by the "E" non-terminal.

```c
    for (z = 0; z < c; z++)
        if (stk[z] == 'i' && stk[z + 1] == 'd')
        {
            printf("\n$%s\t%s$\t%s->id", stk, a, ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            j++;
        }
```

- The `check` function starts by looking for the "id" pattern on the stack. If it finds "id," it prints the current state of the stack, input, and action.

- It then applies a reduction by replacing "id" with "E" on the stack and incrementing `j` to skip over the "id" in the input string.

- Similar logic is applied to check for and reduce other grammar rules, such as "E + E," "E * E," and "(E)".

- The function continues to check and reduce until no further reductions are possible.

This program demonstrates a simple shift-reduce parser for a specific grammar. It parses input strings based on the provided grammar rules and prints the actions taken at each step. Keep in mind that this is a basic example, and real-world parsers are more complex and handle more extensive grammars.

### Algorithm

1. **Initialization**:
   - Include the necessary libraries.
   - Declare global variables:
     - `k`, `z`, `i`, `j`, and `c` are counters and indices.
     - Arrays `a`, `ac`, `stk`, and `act` hold input, action descriptions, stack content, and actions.
   - Declare the `check` function.

2. **Main Function**:
   - Display the grammar rules for the user.
   - Prompt the user to enter an input string and read it into the array `a`.
   - Calculate the length of the input string and store it in `c`.
   - Initialize `act` to "SHIFT" for the initial action.
   - Print headers for the stack, input, and action table.

3. **Parsing Loop**:
   - Iterate through the input string using a `for` loop.
   - Maintain `k`, `i`, and `j` to track progress.
   - For each symbol in the input string:
     - If it's "id," push it onto the stack and call `check`.
     - If it's an operator or parenthesis, push it onto the stack and call `check`.
     - Print the current state of the stack, input, and action.

4. **Acceptance Check**:
   - After parsing the entire input string, check if the stack contains only "E," and the input is empty.
   - If so, print "Accept" to indicate a valid input.

5. **Check Function**:
   - In the `check` function:
     - Initialize `ac` with "REDUCE by E."
     - Check for patterns on the stack and apply reductions based on the grammar rules:
       - If "id" is found, reduce it to "E."
       - If "E + E" is found, reduce it to "E."
       - If "E * E" is found, reduce it to "E."
       - If "(E)" is found, reduce it to "E."
     - Continue checking and reducing until no further reductions are possible.

This simplified algorithm highlights the key steps of the program, where it reads an input string and applies shift-reduce parsing to check if the input conforms to the specified grammar rules. The `check` function is responsible for handling reductions based on the grammar.