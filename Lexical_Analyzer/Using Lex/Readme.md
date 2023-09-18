# Lexical Analyser using Lex

#### How to run the program
 You can run the program using lex or flex tool
 flex lex_ar.l
 gcc lex.yy.c
 ./a.out

#### Algorithm for the program


1. Start
2. Initialize a variable COMMENT to 0 to track whether the program is inside a comment.

3. Define regular expressions for identifiers, keywords, preprocessor directives, comments, strings, digits, operators, character literals, and special symbols.

4. For each character in the input file:
    a. Check if the character matches any of the defined regular expressions.
    If it matches:
        Check if COMMENT is 0 (not inside a comment).
        If COMMENT is 0, print the token type and lexeme to the output, along with line and token numbers.

5. Whenever a newline character is encountered (\n), increment the line number.

6. Ignore spaces, tabs, and newlines ([ \t\n]+) by not processing them as tokens.

7. If none of the regular expressions match a character, print it as an "unrecognized token" along with line and token numbers.

8. In the main function:
    Open the input file (e.g., "file.c") for reading.
    If the file cannot be opened, print an error message and exit.
    Set yyin to the file pointer for Lex to read from.
    Call yylex() to start the tokenization process.
    Print a newline to separate the output from the rest of the program.
    In the yywrap function:
    Return 1 to signal the end of tokenization.
9. End of Algorithm

#### Explaination for the Program 

     Lexical Analyzer Program
     This Lexical Analyzer program is designed to tokenize and classify various elements within a C source code file (file.c). It recognizes and prints information about different types of tokens, including keywords, identifiers, operators, strings, digits, comments, special symbols, and character literals.
     
     Lex Program Structure
     Your Lex program is structured as follows:
     
     Initialization: The program starts with an initialization section enclosed in %{ and %}. In this section, you declare and initialize the COMMENT variable to help handle comments.
     
     Regular Expression Definitions: Following the initialization section, you define regular expressions and associate them with token names. For example, you define identifier to match valid C identifiers and [0-9]+ to match digits. These definitions help Lex recognize different types of tokens.
     
     Rules Section: This section contains a list of rules that specify what action to take when a specific regular expression pattern is matched. Each rule has the format:
         pattern { action }
     The actions are C code blocks enclosed in curly braces. When a pattern is matched, the associated action is executed.
     
     Token Recognition and Classification
     Now, let's break down the token recognition and classification in your program:
     
     Preprocessor Directives: Lines starting with # are recognized as preprocessor directives. The corresponding action prints these lines as "preprocessor directive."
     
     Keywords: C keywords like int, float, char, etc., are recognized and printed as "Keyword."
     
     Comments: Multi-line comments enclosed in /* and */ are recognized and printed as "comment."
     
     Identifiers: Recognizes and prints C identifiers (variable names, function names, etc.) as "Identifier."
     
     Strings: Recognizes and prints strings enclosed in double quotes as "String."
     
     Digits: Recognizes and prints numeric constants as "Digit."
     
     Operators: Recognizes and prints C operators (+, -, *, /, =, <, >, etc.) as "Operator."
     
     Character Literals: Recognizes and prints character literals enclosed in single quotes as "Character Literal."
     
     Special Symbols: Recognizes and prints special symbols (e.g., ,, {, }, (, ), [, ], ;, :, ", ') as "Special symbol."
     
     Spaces and Tabs: Ignores spaces, tabs, and newline characters.
     
     Unrecognized Tokens: If none of the above patterns match, it prints the token as "Unrecognized token."
     
     Main Function
     The main function of the program opens the C source code file file.c, sets the input stream yyin to read from this file, and then invokes the Lexical Analyzer by calling yylex(). The output is printed to the standard output.
     
     yywrap Function
     The yywrap function is used to indicate the end of input to the Lexical Analyzer. It returns 1 to signal the end of processing.
     
     Output
     The program produces output lines for each recognized token, indicating the line number, token number, token type, and lexeme. Unrecognized tokens are also reported.
     
     Overall, this Lex program serves as a basic Lexical Analyzer for C source code, tokenizing and classifying various elements to help in subsequent parsing or analysis.
  
