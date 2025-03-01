# Infix to Postfix Converter in C

## Introduction

This C program converts mathematical expressions from infix notation (the standard form we use, like `3 + 4 * 2`) to postfix notation (also known as Reverse Polish Notation, like `3 4 2 * +`). Postfix notation is useful in computing because it eliminates the need for parentheses and makes expression evaluation more straightforward.

## Core Concepts

Before diving into the code, let's understand some key concepts:

1. **Infix Notation**: The conventional way to write expressions (e.g., `A + B * C`)
2. **Postfix Notation**: Operators come after their operands (e.g., `A B C * +`)
3. **Stack**: A Last-In-First-Out (LIFO) data structure used in the conversion algorithm

## The Program Structure

The program is organized into the following parts:

1. Header files and definitions
2. Stack data structure
3. Stack operations (init, isEmpty, push, pop, peek)
4. Operator precedence function
5. Conversion algorithm (infixToPostfix)
6. Main function

Let's examine each part in detail.

## Header Files and Definitions

```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
```

- **stdio.h**: Provides input/output functions like `printf()` and `fgets()`
- **stdlib.h**: Contains utility functions (though not explicitly used in this code)
- **ctype.h**: Provides character handling functions like `isalnum()`
- **string.h**: Provides string manipulation functions like `strcspn()`
- **MAX**: A constant defining the maximum size of our stack and input strings (100 characters)

## Stack Data Structure

```c
// Stack structure
typedef struct
{
    char items[MAX];
    int top;
} Stack;
```

This creates a new type called `Stack` that contains:
- An array `items` to store characters (our stack elements)
- An integer `top` to keep track of the top position in the stack

## Function Prototypes

```c
// Function prototypes
void init(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, char ch);
char pop(Stack *s);
char peek(Stack *s);
int precedence(char ch);
void infixToPostfix(const char *infix, char *postfix);
```

These declare the functions before they're defined, allowing them to be used in any order in the code.

## Main Function

```c
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
```

The main function:
1. Declares two character arrays: `infix` to store the input expression and `postfix` to store the converted result
2. Prompts the user to enter an infix expression
3. Reads the input using `fgets()` 
4. Removes the newline character from the input using `strcspn()`
5. Calls `infixToPostfix()` to convert the expression
6. Prints the resulting postfix expression
7. Returns 0 to indicate successful execution

## Stack Operations

### Initialize Stack

```c
// Initialize stack
void init(Stack *s)
{
    s->top = -1;
}
```

This function initializes a stack by setting its `top` value to -1, indicating an empty stack. The `-1` value means there are no elements in the stack yet.

### Check if Stack is Empty

```c
// Check if stack is empty
int isEmpty(Stack *s)
{
    return s->top == -1;
}
```

This function checks if the stack is empty by testing if `top` is still -1. It returns 1 (true) if empty, 0 (false) otherwise.

### Push Element onto Stack

```c
// Push element onto stack
void push(Stack *s, char ch)
{
    if (s->top < MAX - 1)
    {
        s->items[++(s->top)] = ch;
    }
}
```

This function adds a character to the top of the stack:
1. First checks if there's room in the stack (if `top` is less than `MAX - 1`)
2. If there's room, increments `top` and assigns the character to that position

### Pop Element from Stack

```c
// Pop element from stack
char pop(Stack *s)
{
    return isEmpty(s) ? '\0' : s->items[(s->top)--];
}
```

This function removes and returns the top element from the stack:
1. First checks if the stack is empty using the `isEmpty()` function
2. If empty, returns the null character `'\0'`
3. If not empty, returns the character at the current `top` position and then decrements `top`

### Peek Top Element of Stack

```c
// Peek top element of stack
char peek(Stack *s)
{
    return isEmpty(s) ? '\0' : s->items[s->top];
}
```

This function returns the top element without removing it:
1. Checks if the stack is empty
2. If empty, returns `'\0'`
3. If not empty, returns the character at the current `top` position (without changing `top`)

## Operator Precedence

```c
// Get precedence of operator
int precedence(char ch)
{
    switch (ch)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}
```

This function determines the precedence (priority) of an operator:
- Addition and subtraction have precedence 1
- Multiplication and division have precedence 2
- Exponentiation has precedence 3
- Other characters (including parentheses) have precedence 0

This is crucial for the conversion algorithm to decide which operators to process first.

## Infix to Postfix Conversion

```c
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
```

This is the core algorithm for converting infix to postfix notation:

1. Creates and initializes a stack to hold operators temporarily
2. Sets a counter `j` to keep track of the current position in the postfix output string
3. Iterates through each character of the infix string:
   - If the character is alphanumeric (a letter or number), adds it directly to the postfix output
   - If the character is an opening parenthesis '(', pushes it onto the stack
   - If the character is a closing parenthesis ')', pops operators from the stack and adds them to the postfix output until an opening parenthesis is found, then discards the opening parenthesis
   - If the character is an operator, pops operators from the stack and adds them to the postfix output as long as they have higher or equal precedence, then pushes the current operator onto the stack
4. After processing all input characters, pops any remaining operators from the stack and adds them to the postfix output
5. Adds a null terminator '\0' to the end of the postfix string to mark its end

## Step-by-Step Example

Let's walk through the conversion of the expression `a+b*c` to postfix:

### Initial State:
- infix: "a+b*c"
- postfix: "" (empty)
- stack: [] (empty)

### Processing:

1. Read 'a' (alphanumeric):
   - Add to postfix: "a"
   - Stack: []

2. Read '+' (operator):
   - No higher precedence operators on stack
   - Push '+' onto stack
   - Stack: ['+']
   - Postfix: "a"

3. Read 'b' (alphanumeric):
   - Add to postfix: "ab"
   - Stack: ['+']

4. Read '*' (operator):
   - '*' has higher precedence than '+'
   - Push '*' onto stack
   - Stack: ['+', '*']
   - Postfix: "ab"

5. Read 'c' (alphanumeric):
   - Add to postfix: "abc"
   - Stack: ['+', '*']

6. No more input characters, empty the stack:
   - Pop '*': Postfix: "abc*"
   - Pop '+': Postfix: "abc*+"

### Final Result:
- Postfix: "abc*+"

This means "take a, take b, take c, multiply b and c, then add a to the result" - which is equivalent to our original expression "a+b*c".

## Important C Functions Used

### fgets()

```c
fgets(infix, MAX, stdin);
```

This function reads a line from the specified input stream (in this case, `stdin` which is standard input) into the string pointed to by the first argument (`infix`). It stops when either a newline is read, the end-of-file is reached, or n-1 (`MAX-1`) characters have been read.

### strcspn()

```c
infix[strcspn(infix, "\n")] = '\0';
```

The `strcspn()` function calculates the length of the initial segment of a string that does not contain any characters from a specified set. Here, it finds the position of the first newline character in `infix`. Then, that position is replaced with a null terminator to effectively remove the newline character.

### isalnum()

```c
if (isalnum(ch))
```

This function checks if the character is alphanumeric (a letter or a digit). It returns non-zero (true) if the character is alphanumeric and 0 (false) otherwise.

## Conclusion

This program demonstrates a classic algorithm for converting infix expressions to postfix using a stack. The key insight is that postfix notation eliminates the need for parentheses and operator precedence rules during evaluation, making it easier for computers to parse and calculate.

The stack is used to temporarily hold operators and ensure they appear in the correct order in the final postfix expression, based on their precedence and the presence of parentheses.

This implementation handles basic arithmetic expressions with parentheses and the operators +, -, *, /, and ^. It could be extended to handle more complex expressions or additional operators.
