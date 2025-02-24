#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Reverse a string, optionally swapping parentheses
void reverse(char* str, char* result, int swap)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        char c = str[len - 1 - i];
        if (swap)
        {
            if (c == '(') c = ')';
            else if (c == ')') c = '(';
        }
        result[i] = c;
    }
    result[len] = '\0';
}

// Get operator precedence
int precedence(char op)
{
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Convert infix to postfix
void infix_to_postfix(char* infix, char* postfix)
{
    char stack[50];
    int top = -1;
    int j = 0;

    for (int i = 0; infix[i]; i++)
    {
        char c = infix[i];
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
            top--; // Pop '('
        }
        else
        {
            while (top >= 0 && precedence(stack[top]) >= precedence(c))
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
}

int main()
{
    char infix[50], reversed[50], postfix[50], prefix[50];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    // Step 1: Reverse infix and swap parentheses
    reverse(infix, reversed, 1);
    
    // Step 2: Convert reversed infix to postfix
    infix_to_postfix(reversed, postfix);
    
    // Step 3: Reverse postfix to get prefix
    reverse(postfix, prefix, 0);
    
    printf("Prefix expression: %s\n", prefix);
    
    return 0;
}
