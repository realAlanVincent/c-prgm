# Explanation of C Program (Insertion Sort)

## Introduction
This C program sorts an array using the **Insertion Sort** algorithm. Below is a line-by-line explanation of the code with an example.

---

## Code Breakdown

### Header File
```c
#include <stdio.h>
```
**Purpose**: Includes the standard input-output library to use functions like `printf` and `scanf`.

### Function: `insertionSort`
```c
void insertionSort(int arr[], int size)
```
**Purpose**: Sorts an array using **Insertion Sort**.

#### Looping through the array
```c
for (int i = 1; i < size; i++)
```
- Starts from index `1` because a single-element array is already sorted.
- Iterates through the array.

#### Key Element Selection
```c
int key = arr[i];
int j = i - 1;
```
- `key` holds the value to be inserted.
- `j` tracks elements before `key` that might need shifting.

#### Shifting Elements
```c
while (j >= 0 && arr[j] > key)
```
- Moves elements greater than `key` one position ahead.

```c
arr[j + 1] = arr[j];
j--;
```
- Shifts elements to the right until the correct position is found.

#### Placing the Key in Correct Position
```c
arr[j + 1] = key;
```
- Inserts `key` in its correct position.

---

### Function: `printArray`
```c
void printArray(int arr[], int size)
```
**Purpose**: Prints the array elements.

#### Looping through array
```c
for (int i = 0; i < size; i++)
```
- Iterates over the array and prints each element.

---

### `main` Function

#### Taking Input
```c
int size;
printf("Enter the number of elements: ");
scanf("%d", &size);
```
- User inputs the size of the array.

#### Declaring the Array
```c
int arr[size];
```
- Declares an array of `size` elements.

#### Taking Array Elements as Input
```c
printf("Enter %d elements: ", size);
for (int i = 0; i < size; i++)
{
    scanf("%d", &arr[i]);
}
```
- Takes user input for array elements.

#### Sorting and Printing the Sorted Array
```c
insertionSort(arr, size);
printf("Sorted array: ");
printArray(arr, size);
```
- Calls `insertionSort` to sort the array.
- Prints the sorted array using `printArray`.

---

## Example Execution
### Input
```
Enter the number of elements: 5
Enter 5 elements: 12 11 13 5 6
```

### Step-by-step Sorting
1. **Initial Array:** `[12, 11, 13, 5, 6]`
2. **Pass 1:** `[11, 12, 13, 5, 6]`
3. **Pass 2:** `[11, 12, 13, 5, 6]` (No change)
4. **Pass 3:** `[5, 11, 12, 13, 6]`
5. **Pass 4:** `[5, 6, 11, 12, 13]`

### Output
```
Sorted array: 5 6 11 12 13
```

---

## Conclusion
This program demonstrates the **Insertion Sort** algorithm effectively, explaining how elements are inserted in the correct order by shifting elements.
