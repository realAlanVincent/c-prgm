# Explanation of C Program (Array Operations: Insertion, Deletion, Merging, Traversal)

## Introduction
This C program performs various operations on an **array**, including:
- **Insertion**: Adding an element at a specified position.
- **Deletion**: Removing an element from a specified position.
- **Merging**: Combining two arrays.
- **Traversal**: Displaying the array elements.

The program uses a **menu-driven approach**, allowing users to select operations dynamically.

---

## Code Breakdown

### Header File
```c
#include <stdio.h>
```
**Purpose**: Includes the standard input-output library for functions like `printf` and `scanf`.

---

## Functions

### 1. Function: `insertion`
```c
void insertion(int arr[], int *n)
```
**Purpose**: Inserts an element at a user-specified position.

#### Steps:
1. Take **element and position** input.
2. Validate position (`1 to *n + 1`).
3. **Shift elements right** to create space.
4. Insert the new element.
5. **Increment array size**.

```c
for (int i = *n; i >= pos; i--)
{
    arr[i] = arr[i - 1];
}
```
- **Shifts elements right** starting from `*n` to `pos`.

---

### 2. Function: `deletion`
```c
void deletion(int arr[], int *n)
```
**Purpose**: Deletes an element at a specified position.

#### Steps:
1. Validate **array is not empty**.
2. Take **position input**.
3. Validate position (`1 to *n`).
4. Store deleted element for display.
5. **Shift elements left** to fill the gap.
6. **Decrement array size**.

```c
for (int i = pos - 1; i < *n - 1; i++)
{
    arr[i] = arr[i + 1];
}
```
- **Shifts elements left** to remove the deleted element.

---

### 3. Function: `merging`
```c
void merging(int arr[], int *n)
```
**Purpose**: Merges another array into the existing one.

#### Steps:
1. Take **size of second array (m)**.
2. Validate input (`m > 0`).
3. Store **second array elements** in a temporary array.
4. Validate **array capacity** (`*n + m ≤ 100`).
5. **Append** second array elements to the first array.
6. **Update size** (`*n += m`).

```c
for (int i = 0; i < m; i++)
{
    arr[*n + i] = temp[i];
}
```
- **Copies second array elements** into the first array.

---

### 4. Function: `traversal`
```c
void traversal(int arr[], int n)
```
**Purpose**: Displays all elements in the array.

#### Steps:
1. Validate **array is not empty**.
2. Print all elements using a loop.

```c
for (int i = 0; i < n; i++)
{
    printf("%d ", arr[i]);
}
```
- **Iterates through array** and prints elements.

---

## `main` Function

### Initial Setup
```c
int arr[100];
int n, choice;
```
- **Declares array** with a **fixed size of 100**.
- **`n` stores the number of elements**.
- **`choice` stores menu selection**.

### Taking Input
```c
printf("Enter the number of elements in the array: ");
scanf("%d", &n);
```
- **Gets array size from user**.
- **Limits maximum size to 100**.

```c
for (int i = 0; i < n; i++)
{
    scanf("%d", &arr[i]);
}
```
- **Takes `n` elements** as input.

---

### Menu-driven Operations

```c
while (1)
{
    printf("\nArray Operations Menu:\n");
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Merging\n");
    printf("4. Traversal (Print Array)\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
```
- **Loops until user exits**.
- **Displays menu** with options.
- **Takes choice input**.

#### Switch Case Handling

```c
switch (choice)
{
    case 1:
        insertion(arr, &n);
        traversal(arr, n);
        break;
    case 2:
        deletion(arr, &n);
        traversal(arr, n);
        break;
    case 3:
        merging(arr, &n);
        traversal(arr, n);
        break;
    case 4:
        traversal(arr, n);
        break;
    case 5:
        printf("Exiting program.\n");
        return 0;
    default:
        printf("Invalid choice. Please try again.\n");
}
```
- **Executes the chosen operation**.
- **Calls corresponding function**.
- **Handles invalid input**.
- **Exits if choice is `5`**.

---

## Example Execution

### **Input**
```
Enter the number of elements in the array: 5
Enter 5 elements:
1 2 3 4 5
```

### **Operations**
#### Insertion at position 3
```
Enter the element to insert: 10
Enter the position (1 to 6): 3
After insertion:
Array elements: 1 2 10 3 4 5
```

#### Deletion at position 2
```
Enter the position to delete (1 to 6): 2
Deleted element: 2
After deletion:
Array elements: 1 10 3 4 5
```

#### Merging with another array
```
Enter the number of elements in the second array: 3
Enter 3 elements for the second array:
7 8 9
After merging:
Array elements: 1 10 3 4 5 7 8 9
```

#### Traversal (Printing)
```
Array elements: 1 10 3 4 5 7 8 9
```

### **Exiting**
```
Enter your choice: 5
Exiting program.
```

---

## Conclusion
This program efficiently performs **array operations** using **shifting techniques** for insertion and deletion, and **concatenation for merging**. It provides a **user-friendly menu** for interactive execution.

- **Insertion Complexity**: O(N) (due to shifting elements)
- **Deletion Complexity**: O(N) (due to shifting elements)
- **Merging Complexity**: O(M) (copying elements)
- **Traversal Complexity**: O(N) (printing elements)

This approach ensures **dynamic and efficient array manipulation**!
