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

// Function prototypes
void init(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, char ch);
char pop(Stack *s);
char peek(Stack *s);
int precedence(char ch);
int isRightAssociative(char ch);
void infixToPostfix(const char *infix, char *postfix);

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove newline character

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

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

// Check if stack is full
int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

// Push element onto stack with overflow handling
void push(Stack *s, char ch)
{
    if (!isFull(s))
    {
        s->items[++(s->top)] = ch;
    }
    else
    {
        printf("Stack Overflow! Cannot push '%c'.\n", ch);
    }
}

// Pop element from stack with underflow handling
char pop(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->items[(s->top)--];
    }
    printf("Stack Underflow! Returning '\\0'.\n");
    return '\0';
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
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3; // Highest precedence
        default: return 0;
    }
}

// Check if an operator is right-associative (only '^' in most cases)
int isRightAssociative(char ch)
{
    return ch == '^';
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

        // Handle multi-digit numbers and variables
        if (isalnum(ch))
        {
            postfix[j++] = ch;
            while (isalnum(infix[i + 1])) // Continue for multi-char operands
            {
                postfix[j++] = infix[++i];
            }
            postfix[j++] = ' '; // Separator for clarity
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
                postfix[j++] = ' ';
            }
            if (!isEmpty(&s))
            {
                pop(&s); // Remove '('
            }
        }
        else // Operator
        {
            while (!isEmpty(&s) &&
                   ((isRightAssociative(ch) && precedence(peek(&s)) > precedence(ch)) ||
                    (!isRightAssociative(ch) && precedence(peek(&s)) >= precedence(ch))))
            {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            push(&s, ch);
        }
    }

    // Pop remaining operators from stack
    while (!isEmpty(&s))
    {
        postfix[j++] = pop(&s);
        postfix[j++] = ' ';
    }

    postfix[j - 1] = '\0'; // Remove trailing space and null-terminate string
}
