#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct
{
    char items[MAX];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

void push(Stack *s, char c)
{
    if (!isFull(s))
    {
        s->items[++s->top] = c;
    }
}

char pop(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->items[s->top--];
    }
    return '#';
}

char peek(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->items[s->top];
    }
    return '#';
}

int precedence(char op)
{
    switch (op)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return 0;
}

void reverseString(char *str)
{
    int i, j;
    char temp;
    int len = strlen(str);
    
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void replaceBrackets(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            str[i] = ')';
        }
        else if (str[i] == ')')
        {
            str[i] = '(';
        }
    }
}

void infixToPrefix(char *infix, char *prefix)
{
    Stack s;
    initStack(&s);
    int i, j = 0;
    
    reverseString(infix);
    replaceBrackets(infix);
    
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (isalnum(infix[i]))
        {
            prefix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(&s, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(&s) && peek(&s) != '(')
            {
                prefix[j++] = pop(&s);
            }
            pop(&s);
        }
        else
        {
            while (!isEmpty(&s) && precedence(peek(&s)) > precedence(infix[i]))
            {
                prefix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }
    
    while (!isEmpty(&s))
    {
        prefix[j++] = pop(&s);
    }
    prefix[j] = '\0';
    
    reverseString(prefix);
}

int main()
{
    char infix[MAX], prefix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPrefix(infix, prefix);
    
    printf("Prefix expression: %s\n", prefix);
    
    return 0;
}
