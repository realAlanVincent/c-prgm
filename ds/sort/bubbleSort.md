# Explanation of C Program (Bubble Sort)

## Introduction
This C program sorts an array using the **Optimized Bubble Sort** algorithm. Below is a line-by-line explanation of the code with an example.

---

## Code Breakdown

### Header Files
```c
#include <stdio.h>
#include <stdbool.h>
```
**Purpose**: Includes the standard input-output library (`stdio.h`) and the boolean library (`stdbool.h`) for using `true` and `false`.

### Function: `swap`
```c
void swap(int *a, int *b)
```
**Purpose**: Swaps two integer values using pointers for better readability and efficiency.

#### Swapping Logic
```c
int temp = *a;
*a = *b;
*b = temp;
```
- Uses a temporary variable `temp` to hold `*a` while swapping.

---

### Function: `bubbleSort`
```c
void bubbleSort(int arr[], int n)
```
**Purpose**: Sorts an array using **Optimized Bubble Sort**.

#### Outer Loop
```c
for (int i = 0; i < n - 1; i++)
```
- Iterates through the array `n-1` times.

#### Inner Loop
```c
for (int j = 0; j < n - i - 1; j++)
```
- Compares adjacent elements and swaps if needed.
- Reduces the range (`n - i - 1`) since the last `i` elements are already sorted.

#### Swapping Condition
```c
if (arr[j] > arr[j + 1])
```
- Swaps elements if they are out of order.

#### Optimization: Early Exit
```c
if (!swapped)
{
    break;
}
```
- If no swaps occurred in an iteration, the array is already sorted, so it exits early.

---

### Function: `printArray`
```c
void printArray(const int *arr, int n)
```
**Purpose**: Prints the elements of the array.

#### Looping through the array
```c
for (int i = 0; i < n; i++)
```
- Iterates over the array and prints each element.

---

### `main` Function

#### Taking Input
```c
int n;
printf("Enter number of elements: ");
scanf("%d", &n);
```
- User inputs the size of the array.

#### Handling Invalid Input
```c
if (n <= 0)
{
    printf("Invalid input! Number of elements should be positive.\n");
    return 1;
}
```
- Ensures the user enters a positive integer.

#### Declaring the Array
```c
int arr[n];
```
- Uses a **Variable-Length Array (VLA)** for dynamic sizing.

#### Taking Array Elements as Input
```c
printf("Enter %d elements: ", n);
for (int i = 0; i < n; i++)
{
    scanf("%d", &arr[i]);
}
```
- Takes user input for array elements.

#### Sorting and Printing the Sorted Array
```c
bubbleSort(arr, n);
printf("Sorted array: ");
printArray(arr, n);
```
- Calls `bubbleSort` to sort the array.
- Prints the sorted array using `printArray`.

---

## Example Execution
### Input
```
Enter number of elements: 5
Enter 5 elements: 64 34 25 12 22
```

### Step-by-step Sorting
1. **Initial Array:** `[64, 34, 25, 12, 22]`
2. **Pass 1:** `[34, 25, 12, 22, 64]`
3. **Pass 2:** `[25, 12, 22, 34, 64]`
4. **Pass 3:** `[12, 22, 25, 34, 64]`
5. **Pass 4:** `[12, 22, 25, 34, 64]` (No swaps, exit early)

### Output
```
Sorted array: 12 22 25 34 64
```

---

## Conclusion
This program demonstrates an **Optimized Bubble Sort**, which reduces unnecessary comparisons when the array becomes sorted early.
