### Output 
s7cii@lab6:~/Compiler_Lab/YACC/Calculator$ yacc -d file.y
s7cii@lab6:~/Compiler_Lab/YACC/Calculator$ lex file.l
s7cii@lab6:~/Compiler_Lab/YACC/Calculator$ gcc lex.yy.c y.tab.c -w
s7cii@lab6:~/Compiler_Lab/YACC/Calculator$ ./a.out 
Enter Any Arithmetic Expression which can have operations Addition, Subtraction, Multiplication, Divison, Modulus and Round brackets:
5+4

Result=9

Entered arithmetic expression is Valid