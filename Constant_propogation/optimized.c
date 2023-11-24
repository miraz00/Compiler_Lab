#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR 10
#define MAX_STR_SIZE 10
    int n;


struct expr
{
    char op[2], op1[MAX_STR_SIZE], op2[MAX_STR_SIZE], res[MAX_STR_SIZE];
    int flag;
};

// Function prototypes
void input(struct expr *arr, int n);
void output(const struct expr *arr, int n);
void constant(struct expr *arr, int n);
void change(struct expr *arr, int p, const char *res);

int main()
{
    struct expr arr[MAX_EXPR];

    printf("\n\nEnter the maximum number of expressions: ");
    scanf("%d", &n);

    input(arr, n);
    constant(arr, n);
    output(arr, n);

    return 0;
}

void input(struct expr *arr, int n)
{
    int i;
    printf("\nEnter the input:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s %s %s %s", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
        arr[i].flag = 0;
    }
}

void constant(struct expr *arr, int n)
{
    int i, op1, op2, res;
    char op, res1[MAX_STR_SIZE];

    for (i = 0; i < n; i++)
    {
        if ((isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0])) || strcmp(arr[i].op, "=") == 0)
        {
            op1 = atoi(arr[i].op1);
            op2 = atoi(arr[i].op2);
            op = arr[i].op[0];

            switch (op)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                if (op2 != 0)
                    res = op1 / op2;
                else
                {
                    printf("Error: Division by zero.\n");
                    exit(EXIT_FAILURE);
                }
                break;
            case '=':
                res = op1;
                break;
            default:
                printf("Error: Unsupported operator.\n");
                exit(EXIT_FAILURE);
            }

            sprintf(res1, "%d", res);
            arr[i].flag = 1;
            change(arr, i, res1);
        }
    }
}

void output(const struct expr *arr, int n)
{
    int i;
    printf("\nOptimized code is:\n");
    for (i = 0; i < n; i++)
    {
        if (!arr[i].flag)
        {
            printf("%s %s %s %s\n", arr[i].op, arr[i].op1, arr[i].op2, arr[i].res);
        }
    }
}

void change(struct expr *arr, int p, const char *res)
{
    int i;
    for (i = p + 1; i < n; i++)
    {
        if (strcmp(arr[p].res, arr[i].op1) == 0)
        {
            strcpy(arr[i].op1, res);
        }
        else if (strcmp(arr[p].res, arr[i].op2) == 0)
        {
            strcpy(arr[i].op2, res);
        }
    }
}
