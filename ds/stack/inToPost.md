# Infix to Postfix Conversion in C

This document explains how the provided C program converts an infix expression to a postfix expression using a stack. The code follows the **Allman style**, ensuring readability and proper indentation.

## Explanation of the Code

### 1. **Including Libraries**
```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
```
- `stdio.h`: Used for input and output functions.
- `stdlib.h`: Includes functions like `exit()`.
- `ctype.h`: Provides functions like `isalnum()` to check if a character is alphanumeric.
- `string.h`: Provides functions for string manipulation.

### 2. **Defining Constants**
```c
#define MAX 100
```
- Defines `MAX` as `100`, setting the maximum size of the stack.

### 3. **Stack Structure**
```c
typedef struct
{
    char items[MAX];
    int top;
} Stack;
```
- Creates a `Stack` structure with:
  - `items[MAX]`: Array to store characters.
  - `top`: Keeps track of the top element.

### 4. **Initializing the Stack**
```c
void initStack(Stack *s)
{
    s->top = -1;
}
```
- Sets `top` to `-1`, indicating an empty stack.

### 5. **Checking if the Stack is Empty**
```c
int isEmpty(Stack *s)
{
    return s->top == -1;
}
```
- Returns `1` (true) if the stack is empty, otherwise `0` (false).

### 6. **Checking if the Stack is Full**
```c
int isFull(Stack *s)
{
    return s->top == MAX - 1;
}
```
- Returns `1` (true) if the stack is full, otherwise `0` (false).

### 7. **Pushing an Element onto the Stack**
```c
void push(Stack *s, char c)
{
    if (!isFull(s))
    {
        s->items[++s->top] = c;
    }
}
```
- Increments `top` and stores `c` at the new `top` position.

### 8. **Popping an Element from the Stack**
```c
char pop(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->items[s->top--];
    }
    return '#';
}
```
- Returns the top element and decrements `top`. If the stack is empty, returns `#` as an error indicator.

### 9. **Peeking at the Top Element**
```c
char peek(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->items[s->top];
    }
    return '#';
}
```
- Returns the top element without removing it. Returns `#` if the stack is empty.

### 10. **Determining Operator Precedence**
```c
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
```
- Assigns precedence values to operators (`+`, `-`, `*`, `/`, `^`).

### 11. **Converting Infix to Postfix**
```c
void infixToPostfix(char *infix, char *postfix)
{
    Stack s;
    initStack(&s);
    int i, j = 0;
    
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(&s, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(&s) && peek(&s) != '(')
            {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove '('
        }
        else
        {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(infix[i]))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }
    
    while (!isEmpty(&s))
    {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}
```
- Iterates through the infix expression:
  - **Operands** are added directly to `postfix`.
  - **Opening parentheses** are pushed onto the stack.
  - **Closing parentheses** pop elements from the stack until `(` is found.
  - **Operators** pop elements based on precedence before pushing.
  - **Remaining stack elements** are added at the end.

### 12. **Main Function**
```c
int main()
{
    char infix[MAX], postfix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}
```
- Takes an **infix expression** from the user.
- Calls `infixToPostfix()`.
- Displays the **converted postfix expression**.

## Example Run
**Input:**
```
Enter infix expression: a+b*(c^d-e)^(f+g*h)-i
```
**Output:**
```
Postfix expression: abcd^e-fgh*+^*+i-
```

## Summary
- The program **implements a stack** to manage operators and parentheses.
- **Precedence rules** ensure the correct order of operations.
- The final **postfix expression** is printed.

This explanation should help you understand each part of the code in detail. 🚀
