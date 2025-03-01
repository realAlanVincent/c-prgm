# Explanation of the C Program

## Overview
This C program converts an infix expression (e.g., `A+B`) to a prefix expression (e.g., `+AB`). It uses a stack-based approach to achieve the conversion.

## Code Breakdown

### Header Files
```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
```
- `stdio.h` – Provides functions like `printf()` and `scanf()` for input and output.
- `stdlib.h` – Includes functions like `exit()` (not used here but useful for stack handling).
- `ctype.h` – Provides functions like `isalnum()` to check if a character is alphanumeric.
- `string.h` – Contains functions like `strlen()` and `strcpy()` for string manipulation.

### Constants and Stack Structure
```c
#define MAX 100

typedef struct
{
    char items[MAX];
    int top;
} Stack;
```
- Defines a constant `MAX` as 100 to limit stack size.
- Defines a `Stack` structure with an array `items` to store elements and an integer `top` to track the top of the stack.

### Stack Operations
#### Initialization
```c
void initStack(Stack *s)
{
    s->top = -1;
}
```
- Initializes an empty stack by setting `top` to `-1`.

#### Checking Empty and Full Conditions
```c
int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX - 1;
}
```
- `isEmpty()` returns `1` if the stack is empty.
- `isFull()` returns `1` if the stack is full.

#### Pushing and Popping Elements
```c
void push(Stack *s, char c)
{
    if (!isFull(s))
    {
        s->items[++s->top] = c;
    }
}
```
- `push()` adds an element to the stack if it’s not full.

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
- `pop()` removes and returns the top element from the stack.
- Returns `#` if the stack is empty (error indicator).

#### Peeking the Top Element
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
- `peek()` returns the top element without removing it.

### Operator Precedence Function
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
- Assigns precedence to operators (`+` and `-` have lowest, `*` and `/` are higher, `^` is highest).

### Reversing a String
```c
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
```
- Reverses a given string by swapping characters from both ends.

### Replacing Brackets
```c
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
```
- Swaps `(` with `)` and vice versa, which is necessary for prefix conversion.

### Infix to Prefix Conversion
```c
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
```
- Reverses the infix expression.
- Replaces brackets.
- Iterates through characters:
  - If alphanumeric, adds to prefix string.
  - If `(`, pushes to stack.
  - If `)`, pops stack until `(` is found.
  - If operator, pops higher precedence operators before pushing.
- Pops remaining stack contents.
- Reverses final string to get the correct prefix expression.

### Main Function
```c
int main()
{
    char infix[MAX], prefix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPrefix(infix, prefix);
    
    printf("Prefix expression: %s\n", prefix);
    
    return 0;
}
```
- Takes user input for an infix expression.
- Converts it to prefix notation using `infixToPrefix()`.
- Prints the prefix expression.

## Example Execution
**Input:**
```
(A+B)*C
```
**Processing:**
1. Reverse: `C*(B+A)`
2. Replace brackets: `C*(B+A)` → `C*(B+A)`
3. Convert to postfix: `CBA+*`
4. Reverse again: `*+ABC`

**Output:**
```
*+ABC
```

## Summary
- Uses stacks to handle operator precedence and associativity.
- Reverses the input, processes it as a postfix conversion, then reverses again.
- Efficient for converting infix to prefix notation.
