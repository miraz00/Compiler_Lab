//This is not correct, check the other program oppre2.c
#include<stdio.h>
#include<string.h>

#define MAX 100

char stack[MAX];
char ip[MAX];
char opt[MAX][MAX][2]; // Increase size to 2 for operators like '<' and '='
char ter[MAX];

int top = -1; // Initialize top to -1

int main() {
  int i, j, k, n, col, row;

  // Initialize arrays
  for (i = 0; i < MAX; i++) {
    stack[i] = '\0';
    ip[i] = '\0';
    ter[i] = '\0';
    for (j = 0; j < MAX; j++) {
      opt[i][j][0] = '\0';
      opt[i][j][1] = '\0';
    }
  }

  printf("Enter the no.of terminals :\n");
  scanf("%d", &n);

  printf("\nEnter the terminals :\n");
  scanf("%s", ter);

  printf("\nEnter the table values :\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("Enter the value for %c %c:", ter[i], ter[j]);
      scanf("%s", opt[i][j]);
    }
  }

  printf("\n**** OPERATOR PRECEDENCE TABLE ****\n");
  for (i = 0; i < n; i++) {
    printf("\t%c", ter[i]);
  }
  printf("\n");
  for (i = 0; i < n; i++) {
    printf("\n%c", ter[i]);
    for (j = 0; j < n; j++) {
      printf("\t%s", opt[i][j]);
    }
  }

  stack[++top] = '$'; // Initialize stack with '$'
  printf("\nEnter the input string:");
  scanf("%s", ip);

  i = 0;
  printf("\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n");
  printf("\n%s\t\t\t%s\t\t\t", stack, ip);

  while (i < strlen(ip)) { // Change to "<" from "<=" to prevent buffer overflow
    col = -1;
    row = -1;

    for (k = 0; k < n; k++) {
      if (stack[top] == ter[k]) {
        col = k;
      }
      if (ip[i] == ter[k]) {
        row = k;
      }
    }

    if (col == -1 || row == -1) {
      printf("\nString is not accepted");
      break;
    }

    if ((stack[top] == '$') && (ip[i] == '$')) {
      printf("String is accepted\n");
      break;
    } else if ((opt[col][row][0] == '<') || (opt[col][row][0] == '=')) {
      stack[++top] = opt[col][row][0];
      stack[++top] = ip[i];
      printf("Shift %c", ip[i]);
      i++;
    } else {
      if (opt[col][row][0] == '>') {
        while (stack[top] != '<') {
          top--;
        }
        top--;
        printf("Reduce");
      } else {
        printf("\nString is not accepted");
        break;
      }
    }

    printf("\n");
    printf("%s\t\t\t", stack);
    printf("%s\t\t\t", ip + i);
  }

  return 0;
}
