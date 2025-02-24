#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[100];
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;

    char *tokens[100];
    int token_count = 0;
    char *token = strtok(input, " ");
    while (token != NULL)
    {
        tokens[token_count++] = token;
        token = strtok(NULL, " ");
    }

    int stack[100];
    int top = -1;
    for (int i = token_count - 1; i >= 0; i--)
    {
        if (isdigit(tokens[i][0]))
        {
            stack[++top] = tokens[i][0] - '0';
        }
        else
        {
            int op1 = stack[top--];
            int op2 = stack[top--];
            if (tokens[i][0] == '+')
            {
                stack[++top] = op1 + op2;
            }
            else if (tokens[i][0] == '-')
            {
                stack[++top] = op1 - op2;
            }
            else if (tokens[i][0] == '*')
            {
                stack[++top] = op1 * op2;
            }
            else if (tokens[i][0] == '/')
            {
                stack[++top] = op1 / op2;
            }
        }
    }

    printf("%d\n", stack[top]);
    return 0;
}
