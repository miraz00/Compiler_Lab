### To run this script
        gcc rdp.c
        ./a.out

#### Sample Input 1
    Enter an arithmetic expression: 5+(6*2

#### Sample Output 1
    Error: Missing closing parenthesis.

#### Sample Input 2
    Enter an arithmetic expression: 5+(6*2)

#### Sample Output 2
    Parsing successful. Result: 17

#### Sample Input 3
    Enter an arithmetic expression: 5/*6

#### Sample Output 3
    Error: Invalid operator.


### What is Recursive Descent Parser?
A recursive descent parser is a top-down parsing technique used in computer science and programming language processing to analyze and process the structure of a sequence of symbols, typically used in the context of programming languages and context-free grammars. It's called "recursive descent" because it recursively descends through the input, breaking it down into smaller components according to the grammar rules.

Here's how a recursive descent parser works:

1. **Grammar Rules**: Start with a set of grammar rules for the language you want to parse. These rules define the syntax of the language and how different language constructs are formed.

2. **Parser Functions**: Create a set of parser functions, each corresponding to a non-terminal symbol in the grammar. Each parser function is responsible for recognizing a specific language construct, such as expressions, statements, or declarations.

3. **Recursive Structure**: The key feature of a recursive descent parser is that these parser functions can call each other recursively to parse nested language constructs. For example, when parsing an expression, it might call the function for parsing sub-expressions.

4. **Matching Terminals**: To recognize terminals (e.g., keywords, operators, and literals), the parser functions may use lexical analysis components or simple logic to match the input against expected tokens.

5. **Backtracking**: Recursive descent parsers use backtracking when necessary. If a parser function starts to parse a construct and then realizes it's not the correct one, it backtracks and tries a different parser function. This allows it to explore different branches of the grammar.

6. **Error Handling**: Recursive descent parsers often include error-handling mechanisms. When a parsing function detects a syntax error, it reports the error and typically attempts to recover to continue parsing, which may involve discarding or inserting tokens to get back on track.

7. **Output Structure**: While parsing, the parser may construct an abstract syntax tree (AST) or perform other actions, such as type checking, symbol table management, or code generation, depending on the purpose of the parser.

Here's a simple example of a recursive descent parser for a simplified arithmetic expression grammar:

Grammar Rules:
- `expression -> term ( '+' term )*`
- `term -> factor ( '*' factor )*`
- `factor -> '(' expression ')' | number`

Parser Functions:
- `parseExpression()`: Parses an arithmetic expression.
- `parseTerm()`: Parses a term.
- `parseFactor()`: Parses a factor.

The parser functions are designed to recognize expressions, terms, and factors based on the grammar rules. They recursively call each other to handle nested expressions, sub-terms, and sub-factors. When a terminal symbol, such as a number or operator, is encountered, it's matched against the input.

Recursive descent parsers are often hand-written, making them easy to understand and modify. They are especially useful for parsing languages with relatively simple syntax. However, they can be less efficient than other parsing techniques for complex grammars, and they may require additional techniques to address issues like left recursion in the grammar.

### Explanation for the Script:


```c
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
```

- These are preprocessor directives to include necessary libraries.
- `<stdio.h>` is for standard input and output.
- `<ctype.h>` is for character classification and validation functions.
- `<stdlib.h>` is for standard library functions.
- `<string.h>` is for string manipulation functions.

```c
char input[100];
int pos = 0;
```

- Declares an array `input` of size 100 to store the input expression.
- Initializes an integer `pos` to 0, which is used to keep track of the current parsing position in the input string.

```c
int parseExpression();
int parseTerm();
int parseFactor();
int parseNumber();
```

- These are function prototypes for the parsing functions. Each function corresponds to a non-terminal in the grammar.

```c
int main() {
    printf("Enter an arithmetic expression: ");
    fgets(input, sizeof(input), stdin);
```

- The `main` function is the entry point of the program.
- It prompts the user to enter an arithmetic expression using `printf`.
- It reads the input using `fgets` and stores it in the `input` array. `sizeof(input)` specifies the maximum number of characters to read.

```c
    int result = parseExpression();
```

- Calls the `parseExpression` function to start parsing the input expression.

```c
    if (pos == strlen(input) - 1) {
        printf("Parsing successful. Result: %d\n", result);
    } else {
        printf("Parsing error at position %d.\n", pos);
    }
```

- Checks if the parsing position `pos` has reached the end of the input string (the newline character).
- If the parsing position is at the end, it indicates a successful parse and prints the result of the arithmetic expression.
- If the parsing position is not at the end, it reports a parsing error and displays the error position.

```c
    return 0;
}
```

- The `main` function returns 0 to indicate successful program execution.

The remaining parsing functions (`parseExpression`, `parseTerm`, `parseFactor`, and `parseNumber`) are defined below `main` and correspond to non-terminals in the grammar. These functions handle different aspects of parsing, such as addition, multiplication, parentheses, and numbers, and they are called recursively to parse the input expression.

The program evaluates arithmetic expressions following the provided grammar and reports whether the parsing was successful or if there was a parsing error.

Algorithm:

Here's a simple algorithm for a recursive descent parser for arithmetic expressions:

**Input**: An arithmetic expression as a string.

**Output**: A result if the expression is valid; otherwise, an error message.

1. Initialize a parsing position variable `pos` to 0.

2. Define parsing functions for the non-terminals in the grammar:
   - `parseExpression()`: Parses addition and subtraction.
   - `parseTerm()`: Parses multiplication and division.
   - `parseFactor()`: Parses parentheses and numbers.
   - `parseNumber()`: Parses numeric values.
   - `parseDigit()`: Checks for digits.

3. In the `parseExpression` function:
   - Call `parseTerm` to parse the left operand.
   - While the current character is '+':
     - Increment `pos`.
     - Call `parseTerm` to parse the right operand.
     - Update the left operand with the result of the addition or subtraction.
   - Return the result.

4. In the `parseTerm` function:
   - Call `parseFactor` to parse the left operand.
   - While the current character is '*':
     - Increment `pos`.
     - Call `parseFactor` to parse the right operand.
     - Update the left operand with the result of the multiplication or division.
   - Return the result.

5. In the `parseFactor` function:
   - If the current character is '(', increment `pos` and call `parseExpression`.
   - If the current character is not '(', call `parseNumber` to parse a number.
   - If a number is parsed, return the numeric value.

6. In the `parseNumber` function:
   - Initialize a variable `number` to 0.
   - While the current character is a digit, convert it to an integer and update `number`.
   - Return the numeric value.

7. In the `parseDigit` function, check if the current character is a digit and return a boolean value.

8. In the `main` function:
   - Prompt the user to enter an arithmetic expression.
   - Read the input into a string.
   - Call `parseExpression` to parse the input expression.
   - Check if the parsing position has reached the end of the input.
   - If parsing is successful and the position is at the end, display the result.
   - If parsing is unsuccessful or the position is not at the end, display an error message.

This algorithm outlines the steps for a simple recursive descent parser for arithmetic expressions. You can implement this algorithm in a programming language of your choice to create a working parser for arithmetic expressions.