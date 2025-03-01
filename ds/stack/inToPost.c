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

// Initialize stack
void init(Stack *s)
{
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s)
{
    return s->top == -1;
}

// Push element onto stack
void push(Stack *s, char ch)
{
    if (s->top < MAX - 1)
    {
        s->items[++(s->top)] = ch;
    }
}

// Pop element from stack
char pop(Stack *s)
{
    return isEmpty(s) ? '\0' : s->items[(s->top)--];
}

// Peek top element of stack
char peek(Stack *s)
{
    return isEmpty(s) ? '\0' : s->items[s->top];
}

// Get precedence of operator
int precedence(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Convert infix to postfix
void infixToPostfix(const char *infix, char *postfix)
{
    Stack s;
    init(&s);
    int j = 0;
    
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];
        
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(&s, ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty(&s) && peek(&s) != '(')
            {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove '('
        }
        else // Operator
        {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    
    while (!isEmpty(&s))
    {
        postfix[j++] = pop(&s);
    }
    
    postfix[j] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];
    
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}
