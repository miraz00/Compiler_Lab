### Program 
#### Design and implement a lexical analyzer using C language to recognize all valid tokens in the input program. The lexical analyzer should ignore redundant spaces, tabs and newlines. It should also ignore comments.

### How to Run the Program
    1. Create the lex_analyzer.c file.
    2. Create the input text file "filein.txt" is the same folder and add a C program there
    3. Compile the Program in your terminal with "gcc lex_analyzer.c" and run "./a.out"

### Program Algorithm


1. **Start**
2. Declare and initialize variables:
   - `FILE *filein` for input file pointer, open "filein.txt" in "read" mode.
   - `FILE *fileout` for output file pointer, open "fileout.txt" in "write" mode.
   - `int lineno = 1` to count line numbers.
   - `int tokno = 0` to count token numbers.
   - `char ch` to store the current character read from the input file.
   - `char str[100]` to store the characters of a token being processed.
   - `char keyword[50][50]` with common C keywords.
   - Initialize `flag` as 0.
3. Print the header for the token table in `fileout`: "Line    Token no.    Token    Lexeme".
4. **While** not at the end of the input file (use `feof(filein)`):
   1. Initialize `i` as 0 and reset `flag` to 0.
   2. Read a character from `filein` and store it in `ch`.
   3. **If** `ch` is an operator (+, -, *, /):
      1. Print to `fileout`: "lineno    tokno    Operator    ch".
      2. Increment `tokno`.
   4. **Else If** `ch` is a special symbol (;, {, }, ?, |, [, ], %, :):
      1. Print to `fileout`: "lineno    tokno    Special Symbol    ch".
      2. Increment `tokno`.
   5. **Else If** `ch` is a digit (0-9):
      1. Print to `fileout`: "lineno    tokno    Digit    ch".
      2. Increment `tokno`.
   6. **Else If** `ch` is an alphabetic character (A-Z, a-z):
      1. Store `ch` in `str` and increment `i`.
      2. Read the next character `ch` from `filein` while it is an alphanumeric character and not a space:
         1. Store `ch` in `str` and increment `i`.
      3. Null-terminate `str` to create a C-style string.
      4. **For** `j` from 0 to 49:
         1. **If** `str` matches `keyword[j]`:
            1. Set `flag` to 1.
            2. **Break** the loop.
      5. **If** `flag` is 1:
         1. Print to `fileout`: "lineno    tokno    Keyword    str".
      6. **Else**:
         1. Print to `fileout`: "lineno    tokno    Identifier    str".
      7. Increment `tokno`.
   7. **Else If** `ch` is a newline character (\n):
      1. Increment `lineno` to track line numbers.
5. Close `fileout`.
6. Close `filein`.
7. **End**



### Program Explanation

This C program reads input from a file named "filein.txt" and processes the content to identify and classify different tokens (e.g., operators, special symbols, keywords, identifiers, digits) in the input. It then writes the results to an output file named "fileout.txt" in the form of a token table, including line numbers and token numbers.

Here's a step-by-step explanation of the program:

1. **Include Headers**: The program includes three standard C headers: `stdio.h` for file I/O, `ctype.h` for character handling functions, and `string.h` for string operations.

2. **Main Function**: The `main` function is where the program execution begins.

3. **File Pointers**: Two file pointers, `filein` and `fileout`, are declared to handle input and output files, respectively. `filein` is opened in "read" mode, and `fileout` is opened in "write" mode.

4. **Variables Initialization**: Several variables are declared to keep track of line numbers (`lineno`), token numbers (`tokno`), and other loop variables (`i` and `j`). A `flag` variable is used to determine if a word is a keyword or an identifier. An array `str` is used to store the characters of a token being processed. An array of C keywords is also declared for comparison.

5. **Table Header**: The program prints a header for the token table in the output file.

6. **Token Processing Loop**: The program enters a loop that continues until the end of the input file is reached (as determined by `feof(filein)`).

7. **Character Reading**: Inside the loop, a character `ch` is read from the input file using `fgetc(filein)`.

8. **Operator Handling**: If `ch` is one of the common operators (+, -, *, /), it is identified as an operator, and its details (line number, token number, type, and character) are printed to the output file. The `tokno` is incremented.

9. **Special Symbol Handling**: Similarly, if `ch` is one of the special symbols (;, {, }, ?, |, [, ], %, :), it is identified as a special symbol, and its details are printed to the output file. The `tokno` is incremented.

10. **Digit Handling**: If `ch` is a digit (0-9), it is identified as a digit, and its details are printed to the output file. The `tokno` is incremented.

11. **Alphanumeric Handling**: If `ch` is an alphabetic character, it is treated as the beginning of a potential keyword or identifier. The characters are collected into the `str` array until a non-alphanumeric character or space is encountered. The `str` array is null-terminated to create a C-style string.

12. **Keyword or Identifier Check**: The program then compares the collected string in `str` with a list of common C keywords. If a match is found, the `flag` is set to 1, indicating that it's a keyword; otherwise, it's an identifier.

13. **Printing Tokens**: Depending on whether the `flag` is 1 (keyword) or 0 (identifier), the program prints the details of the token (line number, token number, type, and lexeme) to the output file. The `tokno` is incremented.

14. **Newline Handling**: If `ch` is a newline character, the `lineno` is incremented to keep track of the line number in the input file.

15. **File Closure**: Finally, after processing the entire input file, both input and output files are closed using `fclose`.

The program reads characters from "filein.txt," classifies them into various token types, and writes the results to "fileout.txt" in a tabular format. The resulting "fileout.txt" will contain a list of tokens with their line numbers, token numbers, types (e.g., Keyword, Identifier, Operator), and lexemes (the actual words or characters in the input).
