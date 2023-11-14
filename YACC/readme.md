### What is YACC?
YACC(Yet Another Compiler Compiler) is a general purpose parser genetor.


Yacc allows the user to specify a context-free grammar for a language using a simple language called BNF (Backus-Naur Form).

From this grammar specification, Yacc generates a C program that can act as a parser for that language.

The generated C code uses recursive descent parsing techniques to parse input according to the specified grammar rules.

Yacc is commonly used to build the front-end of compilers to parse source code written in a programming language and generate an intermediate representation.

### YACC and Lex: 
Yacc is a parser generator and Lex is a lexer/scanner generator. Together they provide a flexible framework for building translators like compilers by separating the lexical, syntactic and semantic analysis tasks. 

### How to run YACC and Lex programs?
