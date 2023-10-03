# Operator Precedence Parser

This code is an implementation of an operator precedence parser in C, which is used to parse and evaluate expressions based on the precedence of operators.

## How to Run

To compile and run the code, follow these steps:

1. Open your terminal.
2. Compile the C program using the `gcc` compiler:
gcc programname.c
Replace `programname.c` with the actual name of your C source code file.

3. Run the compiled program:


## Explanation

1. **Initialization**:
- The code initializes variables and arrays, including `stack`, `ip` (input string), `opt` (operator precedence table), and `ter` (terminals).

2. **Input**:
- It takes input from the user, including the number of terminals (`n`) and the terminal symbols (`ter`).
- The user is prompted to enter the operator precedence table values for each pair of terminals, which are stored in the `opt` array.

3. **Operator Precedence Table**:
- The code displays the operator precedence table, which shows the relationships between different terminals based on their precedence.
- The table is displayed with terminal symbols as headers, and the values from the `opt` array are printed to show the precedence relationships.

4. **Stack Initialization**:
- The `stack` is initialized with a single '$' character, representing the bottom of the stack.

5. **Parsing Input String**:
- The code takes an input string `ip` and begins parsing it.

6. **Parsing Loop**:
- It enters a parsing loop that continues until the end of the input string is reached.

7. **Finding Column and Row**:
- For each character in the input string and the character on top of the stack, it determines the column and row in the operator precedence table based on their positions in the `ter` array.

8. **Shift Operation**:
- If the precedence of the character on top of the stack is less than or equal to the precedence of the current input character, it performs a "Shift" operation.
- This involves pushing the input character onto the stack and moving to the next character in the input string.

9. **Reduce Operation**:
- If the precedence of the character on top of the stack is greater than the current input character, it performs a "Reduce" operation.
- This operation involves removing characters from the top of the stack until a certain condition is met (typically until a specific symbol like '<' is encountered in the table).
- It simulates the reduction of parts of the expression according to the rules in the operator precedence table.

10. **String Acceptance or Rejection**:

 - If both the stack and input string contain only '$' at this point, the string is accepted, and the program indicates that.
 - If any other condition is met, the string is rejected.

11. **Displaying Actions**:

 - Throughout the parsing process, the program displays the current state of the stack and input string, along with the action taken (Shift or Reduce).

12. **Loop Termination**:
 - The loop continues until the end of the input string is reached or until the string is rejected.

This code is a basic example of an operator precedence parser and doesn't perform actual expression evaluation. Instead, it demonstrates the parsing process based on operator precedence rules defined in the `opt` array. The parser works by shifting characters onto the stack or reducing parts of the expression until a final decision is made on whether the input string is accepted or rejected.

