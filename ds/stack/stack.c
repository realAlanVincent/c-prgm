#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push (int value)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        stack[++top] = value;
        printf("%d pushed to stack\n", value);
    }
}

void pop (void)
{
    if (top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("%d popped from stack\n", stack[top--]);
    }
}

void display (void)
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main (void)
{
    int choice, value;
    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                return 0;
            }
            default:
            {
                printf("Invalid choice\n");
            }
        }
    }
    return 0;
}
