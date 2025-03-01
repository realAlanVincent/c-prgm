# Stack Implementation in C (Line-by-Line Explanation)

## Introduction
This C program implements a stack using an array and provides basic operations like push, pop, and display. Below is a detailed explanation of the code along with an example.

---

## Code Breakdown

### **1. Header File Inclusion**
```c
#include <stdio.h>
```
This includes the standard input-output library, which allows us to use functions like `printf()` and `scanf()`.

---

### **2. Constant Stack Size Definition**
```c
const int STACK_SIZE = 100;
```
This defines a constant integer `STACK_SIZE` with a value of `100`. This represents the maximum capacity of the stack.

---

### **3. Stack and Top Variable Declaration**
```c
int stack[100];
int top = -1;
```
- `stack[100]` is an array used to store stack elements.
- `top` is an integer variable that keeps track of the topmost element. Initially, it is set to `-1`, meaning the stack is empty.

---

### **4. Push Function (Adding an Element)**
```c
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
```
- This function takes an integer `value` as input and pushes it onto the stack.
- If `top` is equal to `STACK_SIZE - 1`, it prints "Stack Overflow", meaning the stack is full.
- Otherwise, `top` is incremented, and the value is stored in the stack at position `top`.

#### **Example:**
```c
push(5); // Stack: [5], top = 0
push(10); // Stack: [5, 10], top = 1
```

---

### **5. Pop Function (Removing an Element)**
```c
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
```
- This function removes the topmost element from the stack.
- If `top < 0`, it prints "Stack Underflow", meaning the stack is empty.
- Otherwise, it stores the top element in `popped`, decrements `top`, and prints the popped value.

#### **Example:**
```c
push(5);
push(10);
pop(); // Removes 10, Stack: [5], top = 0
```

---

### **6. Display Function (Printing Stack Elements)**
```c
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
```
- If `top < 0`, it prints "Stack is empty".
- Otherwise, it prints all elements from `top` to `0`.

#### **Example:**
```c
push(5);
push(10);
display(); // Output: 10, 5
```

---

### **7. Main Function (Menu-Driven Program)**
```c
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
```
- The program runs in an infinite loop using `while (1)`, allowing repeated stack operations until the user chooses to exit.
- It presents a menu with options:
  - `1`: Push a value onto the stack.
  - `2`: Pop the top value.
  - `3`: Display stack elements.
  - `4`: Exit the program.
- The user enters a choice, and `switch` executes the corresponding function.

#### **Example Execution:**
```
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter value to push: 10
Pushed 10

Enter your choice: 1
Enter value to push: 20
Pushed 20

Enter your choice: 3
Stack elements (top to bottom):
20
10

Enter your choice: 2
Popped 20

Enter your choice: 4
```

---

## **Conclusion**
This program implements a simple stack using an array and provides basic operations like push, pop, and display. The menu-driven approach makes it easy for users to interact with the stack.

This is an example of a Last In, First Out (LIFO) data structure.
