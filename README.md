# Compiler_Lab
Repo for Compiler Lab Semester 7 KTU

## The Map

    ├── Bottom_Up_Parsers
    │   ├── Operator Precedence
    │   │   ├── oppre2.c
    │   │   ├── output.txt
    │   │   ├── readme.md
    │   │   └── spam
    │   │       └── op_pre_par.c
    │   └── Shift_reduce_parser
    │       ├── output.txt
    │       ├── readme.md
    │       └── srp.c
    ├── Compiler Lab_Syllabus.pdf
    ├── Constant_propogation
    │   ├── a.out
    │   ├── cp.c
    │   ├── optimized.c
    │   └── readme.md
    ├── First_Follow
    │   ├── Data_structured.c
    │   ├── first_follow.c
    │   ├── output.txt
    │   └── readme.md
    ├── Intermediate_code_generator
    │   ├── a.out
    │   ├── icg.c
    │   ├── input.txt
    │   ├── output.txt
    │   └── readme.md
    ├── Lex
    │   ├── Email_Checker
    │   │   ├── file.txt
    │   │   ├── lex_checkmail.l
    │   │   ├── lex.yy.c
    │   │   └── output.txt
    │   ├── Lexical_Analyzer
    │   │   ├── Readme.md
    │   │   ├── Using C Program
    │   │   │   ├── filein.txt
    │   │   │   ├── fileout.txt
    │   │   │   ├── lex_analyzer.c
    │   │   │   └── readme.md
    │   │   └── Using Lex
    │   │       ├── file.c
    │   │       ├── lex_ar.l
    │   │       ├── lex.yy.c
    │   │       ├── output.txt
    │   │       ├── Readme.md
    │   │       └── Table_format_ouput
    │   │           ├── file.c
    │   │           ├── lex_tab.l
    │   │           ├── lex.yy.c
    │   │           └── output.txt
    │   └── vowel_counter
    │       ├── file.txt
    │       ├── lex.yy.c
    │       ├── output.txt
    │       └── vc.l
    ├── LICENSE
    ├── NFA to DFA
    │   ├── input.txt
    │   ├── nfadfa
    │   ├── nfadfa.c
    │   ├── nfatodfa2
    │   │   ├── output.txt
    │   │   ├── program
    │   │   └── program.c
    │   ├── nfatodfa3.c
    │   ├── nfatodfacorrect.c
    │   ├── output.txt
    │   └── readme.md
    ├── README.md
    ├── Top_Down_Parsers
    │   └── Recursive_descent__parser
    │       ├── rdp.c
    │       └── readme.md
    └── YACC
        ├── Calculator
        │   ├── file.l
        │   ├── file.y
        │   ├── lex.yy.c
        │   ├── readme.md
        │   ├── y.tab.c
        │   └── y.tab.h
        ├── readme.md
        ├── valid_expressions
        │   ├── file.l
        │   └── file.y
        └── valid_identifier
            ├── file.l
            └── file.y

    23 directories, 68 files


### SYLLABUS
    1. Implementation of lexical analyzer using the tool LEX.
    2. Implementation of Syntax analyzer using the tool YACC.
    3. Application problems using NFA and DFA.
    4. Implement Top-Down Parser.
    5. Implement Bottom-up parser.
    6. Simulation of code optimization Techniques.
    7. Implement Intermediate code generation for simple expressions.
    8. Implement the back end of the compiler.

### PRACTICE QUESTIONS
#### List of Exercises/Experiments:
    1. Design and implement a lexical analyzer using C language to recognize all valid tokens in the input program. The lexical analyzer should ignore redundant spaces, tabs and newlines. It should also ignore comments.
    2. Implement a Lexical Analyzer for a given program using Lex Tool.
    3. Write a lex program to display the number of lines, words and characters in an input text.
    4. Write a LEX Program to convert the substring abc to ABC from the given input string.
    5. Write a lex program to find out total number of vowels and consonants from the given input sting.
    6. Generate a YACC specification to recognize a valid arithmetic expression that uses operators +, – , *,/ and parenthesis.
    7. Generate a YACC specification to recognize a valid identifier which starts with a letter followed by any number of letters or digits.
    8. Implementation of Calculator using LEX and YACC
    9. Convert the BNF rules into YACC form and write code to generate abstract
        syntax tree.
    10. Write a program to find ε – closure of all states of any given NFA with ε transition.
    11. Write a program to convert NFA with ε transition to NFA without ε transition.
    12. Write a program to convert NFA to DFA.
    13. Write a program to minimize any given DFA.
    14. Write a program to find the First and Follow of any given grammar.
    15. Design and implement a recursive descent parser for a given grammar.
    16. Construct a Shift Reduce Parser for a given language.
    17. Write a program to perform constant propagation.
    18. Implement Intermediate code generation for simple expressions.
    19. Implement the back end of the compiler which takes the three address code and
     produces the 8086 assembly language instructions that can be assembled and run
     using an 8086 assembler. The target assembly instructions can be a simple move,
     add, sub, jump etc.


### Check the complete Syllabus [here](https://github.com/ashwin417/Compiler_Lab/blob/main/Compiler%20Lab.pdf) !!!

### FAQs

##### How to run lex programs?    
    1. Run example.l file using "lex example.l" to generate the "lex.yy.c" file
    2. Compile the lex.yy.c file using gcc 
    3. Run ./a.out
    



### Viva Help
 1. [Mindmajix](https://mindmajix.com/compiler-design-interview-questions)
 2. [Geeks for Geeks Notes](https://www.geeksforgeeks.org/last-minute-notes-compiler-design-gq/)
 3. [Coding Ninjas Interview Questions](https://www.codingninjas.com/studio/library/compiler-design-interview-questions)
 4. [CrowdForGeeks](https://crowdforgeeks.com/interview-questions/top-100-compiler-design-interview-questions-and-answers)



### Git and GitHub Version Control [Tutorial](https://www.freecodecamp.org/news/introduction-to-git-and-github/)
