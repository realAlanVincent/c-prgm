#include <stdio.h>
#include <string.h>
#include <ctype.h>

int precedence(char op)
{
    return op == '+' || op == '-' ? 1 : op == '*' || op == '/' ? 2 : op == '^' ? 3 : 0;
}

int main()
{
    char infix[100], postfix[100], stack[100];
    int top = -1;
    int i, j = 0, len;
    char c;

    printf("Enter infix expression: ");
    scanf("%s", infix);
    len = strlen(infix);

    for (i = 0; i < len; i++)
    {
        c = infix[i];
        if (isalnum(c))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            stack[++top] = c;
        }
        else if (c == ')')
        {
            while (top >= 0 && stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(')
            {
                top--;
            }
        }
        else
        {
            while (top >= 0 && stack[top] != '(' && precedence(stack[top]) >= precedence(c))
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }

    while (top >= 0)
    {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
    printf("Postfix: %s\n", postfix);

    return 0;
}
