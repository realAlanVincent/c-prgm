#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK 100

int stack[MAX_STACK];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char expr[100];
    printf("Enter postfix expression: ");
    fgets(expr, 100, stdin);
    expr[strcspn(expr, "\n")] = 0;

    char *token = strtok(expr, " ");
    while (token != NULL)
    {
        if (strcmp(token, "+") == 0)
        {
            int operand2 = pop();
            int operand1 = pop();
            push(operand1 + operand2);
        }
        else if (strcmp(token, "-") == 0)
        {
            int operand2 = pop();
            int operand1 = pop();
            push(operand1 - operand2);
        }
        else if (strcmp(token, "*") == 0)
        {
            int operand2 = pop();
            int operand1 = pop();
            push(operand1 * operand2);
        }
        else if (strcmp(token, "/") == 0)
        {
            int operand2 = pop();
            int operand1 = pop();
            push(operand1 / operand2);
        }
        else
        {
            push(atoi(token));
        }
        token = strtok(NULL, " ");
    }

    printf("Result: %d\n", pop());
    return 0;
}
