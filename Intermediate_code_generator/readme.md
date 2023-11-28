## Intermediate Code Generator

The Intermediate Code Generator is a part of the compiler that produces an intermediate code, which is a representation of the source code that is easier for subsequent stages of the compiler to work with. This intermediate code lies between the high-level language and the machine language.

The Intermediate Code Generator receives input from its predecessor phase and semantic analyzer phase. It takes input in the form of an annotated syntax tree. Using the intermediate code, the second phase of the compiler synthesis phase is changed according to the target machine.

### How to Run?

    prompt> gcc icg.c
    prompt> ./a.out
Be sure you have given the input as a file as in *input.txt* in this directory.
Output will be generated in *output.txt* in the same directory.
