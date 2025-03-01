# Infix to Postfix Conversion in C: A Detailed Explanation

This document provides a comprehensive explanation of a C program that converts infix expressions (like `a+b*c`) to postfix expressions (like `abc*+`). The program demonstrates fundamental concepts of data structures, particularly stacks, and their application in expression parsing.

## Table of Contents
1. [Introduction to Infix and Postfix Notations](#introduction)
2. [Understanding the Stack Data Structure](#stack-data-structure)
3. [Line-by-Line Code Explanation](#code-explanation)
4. [Tracing Through an Example](#example-trace)
5. [Summary](#summary)

<a id="introduction"></a>
## 1. Introduction to Infix and Postfix Notations

Before diving into the code, let's understand what infix and postfix notations are:

- **Infix notation**: This is the conventional way we write expressions, with operators placed between operands. For example: `A + B * C`.
- **Postfix notation** (also known as Reverse Polish Notation): In this format, operators follow their operands. For example, the infix expression `A + B * C` becomes `A B C * +` in postfix.

The advantage of postfix notation is that it eliminates the need for parentheses and rules of operator precedence, making it easier for computers to evaluate expressions.

<a id="stack-data-structure"></a>
## 2. Understanding the Stack Data Structure

The core data structure used in this program is a **stack**, which follows the Last-In-First-Out (LIFO) principle. In this implementation:

- The stack is used to store operators temporarily during the conversion process.
- The program implements basic stack operations: initialization, push, pop, peek, and isEmpty.
- The stack is implemented using an array with a maximum size defined by `MAX`.

<a id="code-explanation"></a>
## 3. Line-by-Line Code Explanation

Let's break down the code section by section:

### Header Files and Constant Definition

```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
```

- `stdio.h`: Provides functions for input and output operations like `printf()` and `fgets()`.
- `stdlib.h`: Contains general-purpose functions including memory allocation.
- `ctype.h`: Provides functions for testing and converting characters, specifically `isalnum()` in this code.
- `string.h`: Contains functions for string manipulation, specifically `strcspn()` in this code.
- `MAX`: A constant that defines the maximum size for the stack and input strings (100 characters).

### Stack Structure Definition

```c
typedef struct
{
    char items[MAX];
    int top;
} Stack;
```

This defines a structure called `Stack` with two members:
- `items`: An array of characters with size `MAX` to store the stack elements.
- `top`: An integer that points to the top element of the stack.

### Stack Initialization Function

```c
void init(Stack *s)
{
    s->top = -1;
}
```

This function initializes a stack by setting its `top` index to -1, indicating an empty stack. The function takes a pointer to a Stack as its parameter.

### Empty Stack Check Function

```c
int isEmpty(Stack *s)
{
    return s->top == -1;
}
```

This function checks if the stack is empty by testing if the `top` index is -1. It returns 1 (true) if the stack is empty and 0 (false) otherwise.

### Push Function

```c
void push(Stack *s, char ch)
{
    if (s->top < MAX - 1)
    {
        s->items[++(s->top)] = ch;
    }
}
```

This function adds a character to the top of the stack:
- It first checks if the stack has room for more elements by ensuring `top` is less than `MAX - 1`.
- If there's room, it increments `top` and then assigns the character to that position in the array.
- Note that `++(s->top)` increments `top` before accessing the array element.

### Pop Function

```c
char pop(Stack *s)
{
    return isEmpty(s) ? '\0' : s->items[(s->top)--];
}
```

This function removes and returns the top element from the stack:
- It uses the ternary operator to first check if the stack is empty using the `isEmpty()` function.
- If the stack is empty, it returns `'\0'` (null character).
- Otherwise, it returns the character at the current `top` position and then decrements `top`.
- Note that `(s->top)--` decrements `top` after accessing the array element.

### Peek Function

```c
char peek(Stack *s)
{
    return isEmpty(s) ? '\0' : s->items[s->top];
}
```

This function returns the top element of the stack without removing it:
- Similar to `pop()`, it first checks if the stack is empty.
- If empty, it returns `'\0'`.
- Otherwise, it returns the character at the current `top` position without modifying `top`.

### Operator Precedence Function

```c
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
```

This function determines the precedence level of an operator:
- Addition and subtraction have the lowest precedence (1).
- Multiplication and division have medium precedence (2).
- Exponentiation has the highest precedence (3).
- Any other character is assigned a precedence of 0.

This hierarchy ensures that operations are performed in the correct order during expression evaluation.

### Infix to Postfix Conversion Function

```c
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

This is the core function that converts an infix expression to postfix. It processes the input string character by character following these rules:

1. Operands (`isalnum(ch)` checks if a character is alphanumeric):
   - If the character is an operand (letter or digit), it is directly added to the postfix expression.

2. Opening parenthesis '(':
   - Push it onto the stack.

3. Closing parenthesis ')':
   - Pop and add operators from the stack to the postfix expression until an opening parenthesis is encountered.
   - Discard both parentheses.

4. Operators (+, -, *, /, ^):
   - While there are operators on the stack with greater or equal precedence, pop them and add to the postfix expression.
   - Push the current operator onto the stack.

5. After processing the entire expression:
   - Pop any remaining operators from the stack and add them to the postfix expression.

6. Finally, add a null character to mark the end of the postfix expression string.

### Main Function

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
1. Declares two character arrays `infix` and `postfix` to store the input and output expressions.
2. Prompts the user to enter an infix expression.
3. Reads the expression using `fgets()`.
4. Removes the newline character from the input using `strcspn()`.
5. Calls the `infixToPostfix()` function to convert the expression.
6. Displays the resulting postfix expression.
7. Returns 0 to indicate successful execution.

<a id="example-trace"></a>
## 4. Tracing Through an Example

Let's trace through the conversion of the infix expression `a+b*c` to postfix:

1. Initialize an empty stack and an empty postfix string.
2. Process 'a': It's an operand, so add it directly to the postfix string. Postfix: "a"
3. Process '+': Push it onto the stack since the stack is empty. Stack: "+"
4. Process 'b': It's an operand, so add it to the postfix string. Postfix: "ab"
5. Process '*': 
   - Compare precedence: '*' (2) > '+' (1), so push '*' onto the stack.
   - Stack: "+*"
6. Process 'c': It's an operand, so add it to the postfix string. Postfix: "abc"
7. End of input: Pop all operators from the stack and add them to the postfix string.
   - Pop '*': Postfix: "abc*"
   - Pop '+': Postfix: "abc*+"

Final postfix expression: "abc*+"

Let's verify: 
- In "abc*+", first 'b' and 'c' are multiplied, and then 'a' is added to the result.
- This preserves the original meaning of "a+b*c" where multiplication has higher precedence than addition.

Let's trace another example, this time with parentheses: `(a+b)*(c-d)`

1. Process '(': Push onto the stack. Stack: "("
2. Process 'a': Add to postfix. Postfix: "a"
3. Process '+': Push onto the stack. Stack: "(+"
4. Process 'b': Add to postfix. Postfix: "ab"
5. Process ')': Pop operators until '('. Pop '+' and add to postfix. Pop '(' and discard. 
   - Postfix: "ab+"
   - Stack: empty
6. Process '*': Push onto the stack. Stack: "*"
7. Process '(': Push onto the stack. Stack: "*("
8. Process 'c': Add to postfix. Postfix: "ab+c"
9. Process '-': Push onto the stack. Stack: "*(-"
10. Process 'd': Add to postfix. Postfix: "ab+cd"
11. Process ')': Pop operators until '('. Pop '-' and add to postfix. Pop '(' and discard.
    - Postfix: "ab+cd-"
    - Stack: "*"
12. End of input: Pop all operators. Pop '*' and add to postfix. 
    - Postfix: "ab+cd-*"

Final postfix expression: "ab+cd-*"

<a id="summary"></a>
## 5. Summary

This program demonstrates several important programming concepts:

1. **Data Structures**: Implementation of a stack and its operations.
2. **Algorithm Implementation**: The shunting yard algorithm for infix to postfix conversion.
3. **Character Processing**: Using functions from `ctype.h` to identify different types of characters.
4. **String Handling**: Working with strings and using functions from `string.h`.
5. **Input/Output Operations**: Reading user input and displaying results.

The infix to postfix conversion is a classic example of how stacks can be used to solve seemingly complex problems by breaking them down into a series of simpler operations. The algorithm leverages the LIFO nature of stacks to ensure that operators are processed in the correct order according to their precedence.

This implementation is efficient with a time complexity of O(n), where n is the length of the input expression, as it processes each character exactly once.
