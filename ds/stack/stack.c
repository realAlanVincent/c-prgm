#include <stdio.h>

const int STACK_SIZE = 100;

int stack[100];
int top = -1;

void push(int value)
{
    if (top >= STACK_SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = value;
        printf("Pushed %d\n", value);
    }
}

void pop()
{
    if (top < 0)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int popped = stack[top];
        top--;
        printf("Popped %d\n", popped);
    }
}

void display()
{
    if (top < 0)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
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
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}
