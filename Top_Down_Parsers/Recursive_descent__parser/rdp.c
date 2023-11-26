/* 
Grammar Followed in this program is: 
E -> E + T | T
T -> T * F | F
F -> ( E ) | num 
*/

#include <stdio.h>
#include <ctype.h>
#include<stdlib.h>
#include<string.h>

char input[100];
int pos = 0;

int parseExpression();
int parseTerm();
int parseFactor();
int parseNumber();

int main() {
    printf("Enter an arithmetic expression: ");
    fgets(input, sizeof(input), stdin);

    int result = parseExpression();

    if (pos == strlen(input) - 1) {
        printf("Parsing successful. Result: %d\n", result);
    } else {
        printf("Parsing error at position %d.\n", pos);
    }

    return 0;
}

int parseExpression() {
    int left = parseTerm();

    while (input[pos] == '+') {
        pos++;
        int right = parseTerm();
        left += right;
    }

    return left;
}

int parseTerm() {
    int left = parseFactor();

    while (input[pos] == '*') {
        pos++;
        int right = parseFactor();
        left *= right;
    }

    return left;
}

int parseFactor() {
    if (input[pos] == '(') {
        pos++;
        int result = parseExpression();
        if (input[pos] == ')') {
            pos++;
            return result;
        } else {
            printf("Error: Missing closing parenthesis.\n");
            exit(1);
        }
    } else {
        return parseNumber();
    }
}

int parseNumber() {
    int number = 0;

    while (isdigit(input[pos])) {
        number = number * 10 + (input[pos] - '0');
        pos++;
    }

    return number;
}
