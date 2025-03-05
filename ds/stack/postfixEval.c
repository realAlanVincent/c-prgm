#include <stdio.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct
{
    int items[MAX];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

void push(Stack *s, int value)
{
    s->items[++s->top] = value;
}

int pop(Stack *s)
{
    return s->items[s->top--];
}

int evaluatePostfix(char *postfix)
{
    Stack s;
    initStack(&s);
    int i, op1, op2;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            push(&s, postfix[i] - '0'); // Convert char to int
        }
        else
        {
            op2 = pop(&s);
            op1 = pop(&s);

            switch (postfix[i])
            {
                case '+': push(&s, op1 + op2); break;
                case '-': push(&s, op1 - op2); break;
                case '*': push(&s, op1 * op2); break;
                case '/': push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}

int main()
{
    char postfix[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    printf("Result: %d\n", evaluatePostfix(postfix));

    return 0;
}
