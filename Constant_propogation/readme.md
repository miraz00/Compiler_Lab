## Constant Propogation

Constant Propagation is a local code optimization technique in Compiler Design. It can be defined as the process of replacing the constant value of variables in the expression. In simpler words, if some value is assigned a known constant, then we can simply replace that value by the constant.

This technique is executed using reaching definition analysis results in compilers. This means that if the reaching definition of all variables have the same assignment which assigns the same constant to the variable, then the variable has a constant value and can be substituted with the constant.

For example, consider the following pseudocode¹:

```python
a = 30
b = 20 - a / 2
c = b * (30 / a + 2) - a
```

We can rewrite the same code as¹:

```python
a = 30
b = 20 - 30 / 2
c = b * (30 / 30 + 2) - 30
```

This updated code is faster as compared to the previous code as the compiler does not need to again and again go back to the previous expressions looking up and copying the value of a variable in order to compute the current expressions. This saves a lot of time and thus, reducing time complexity and perform operations more efficiently.


                                                  
### How to Run? 
    prompt> gcc cp.c
    prompt> ./a.out

#### Sample Input
    Enter the maximum number of expressions: 4

    Enter the input:
    = 3 - a
    + a b t1
    + a c t2
    + t1 t2 t3

#### Sample Output
    Optimized code is:
    + 3 b t1
    + 3 c t2
    + t1 t2 t3