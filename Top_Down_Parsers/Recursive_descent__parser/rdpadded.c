/* 
Grammar used here is:
E -> E + T | E - T | T
T -> T * F | T / F | F
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

    while (input[pos] == '+' || input[pos] == '-') {
        char op = input[pos];
        pos++;
        if (input[pos] == '*' || input[pos] == '/' || input[pos] == '+' || input[pos] == '-') {
            printf("Error: Invalid operations.\n");
            exit(1);
        }
        int right = parseTerm();
        if (op == '+') {
            left += right;
        } else {
            left -= right;
        }
    }

    return left;
}


int parseTerm() {
    int left = parseFactor();

    while (input[pos] == '*' || input[pos] == '/') {
        char op = input[pos];
        pos++;
        if (input[pos] == '*' || input[pos] == '/' || input[pos] == '+' || input[pos] == '-') {
            printf("Error: Invalid operations.\n");
            exit(1);
        }
        int right = parseFactor();
        if (op == '*') {
            left *= right;
        } else {
            if (right != 0) {
                left /= right;
            } else {
                printf("Error: Division by zero.\n");
                exit(1);
            }
        }
    }

    return left;
}


int parseFactor() {
    while (isspace(input[pos])) {
        pos++;
    }

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
