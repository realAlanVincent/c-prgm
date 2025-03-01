# Explanation of C Program (Finding All Occurrences Using Binary Search)

## Introduction
This C program finds all occurrences of a target element in a **sorted array** using **Binary Search**. The program efficiently finds the **first and last occurrence** of the target and prints all its positions.

---

## Code Breakdown

### Header File
```c
#include <stdio.h>
```
**Purpose**: Includes the standard input-output library for functions like `printf` and `scanf`.

---

### Function: `findFirstOccurrence`
```c
int findFirstOccurrence(int arr[], int size, int target)
```
**Purpose**: Uses **Binary Search** to find the first occurrence of `target` in the sorted array.

#### Binary Search Logic
```c
int left = 0, right = size - 1, result = -1;
```
- Initializes search boundaries (`left`, `right`) and `result` to store the first occurrence index.

```c
while (left <= right)
```
- Standard **Binary Search** loop runs until `left` exceeds `right`.

```c
int mid = left + (right - left) / 2;
```
- Computes **midpoint** to prevent integer overflow.

```c
if (arr[mid] == target)
```
- If `target` is found at `mid`, update `result` and **move left** to find an earlier occurrence.

```c
else if (arr[mid] < target)
```
- If `target` is greater, **search right half** (`left = mid + 1`).

```c
else
```
- If `target` is smaller, **search left half** (`right = mid - 1`).

---

### Function: `findLastOccurrence`
```c
int findLastOccurrence(int arr[], int size, int target)
```
**Purpose**: Similar to `findFirstOccurrence`, but finds the **last occurrence** of `target`.

#### Key Difference
```c
if (arr[mid] == target)
{
    result = mid;
    left = mid + 1; // Move right to find later occurrence
}
```
- Moves **right** instead of **left** after finding `target` to get the last occurrence.

---

### Function: `findAllOccurrences`
```c
void findAllOccurrences(int arr[], int size, int target)
```
**Purpose**: Finds and prints **all occurrences** of `target` using `findFirstOccurrence` and `findLastOccurrence`.

#### Handling No Occurrence
```c
if (first == -1)
```
- If `first` remains `-1`, `target` is not in the array.

#### Printing Positions
```c
for (int i = first; i <= last; i++)
```
- Iterates from `first` to `last`, printing **all occurrences**.

#### Printing Count
```c
printf("Total occurrences: %d\n", (last - first + 1));
```
- Computes and prints the total count.

---

### `main` Function

#### Taking Input
```c
int size, target;
printf("Enter the number of elements: ");
scanf("%d", &size);
```
- User inputs **size** of array.

#### Declaring the Array
```c
int arr[size];
```
- Uses a **Variable-Length Array (VLA)**.

#### Taking Sorted Array Input
```c
printf("Enter %d sorted elements: ", size);
for (int i = 0; i < size; i++)
{
    scanf("%d", &arr[i]);
}
```
- Accepts sorted input from user.

#### Taking Target Input
```c
printf("Enter the target element: ");
scanf("%d", &target);
```
- Accepts `target` to search for.

#### Finding and Displaying Occurrences
```c
findAllOccurrences(arr, size, target);
```
- Calls `findAllOccurrences` to process and print results.

---

## Example Execution
### Input
```
Enter the number of elements: 10
Enter 10 sorted elements: 1 2 2 2 3 4 5 5 6 6
Enter the target element: 2
```

### Binary Search Steps
1. **Find First Occurrence of 2**
   - Mid = 4 → `arr[4] = 3` (move left)
   - Mid = 1 → `arr[1] = 2` (store index, move left)
   - Mid = 0 → `arr[0] = 1` (move right)
   - **First Occurrence at index 1**

2. **Find Last Occurrence of 2**
   - Mid = 4 → `arr[4] = 3` (move left)
   - Mid = 1 → `arr[1] = 2` (store index, move right)
   - Mid = 2 → `arr[2] = 2` (store index, move right)
   - Mid = 3 → `arr[3] = 2` (store index, move right)
   - **Last Occurrence at index 3**

### Output
```
Element 2 found at positions: 2 3 4
Total occurrences: 3
```

---

## Conclusion
This program efficiently finds all occurrences of an element in a sorted array using **Binary Search**, making it much faster than a linear search approach. The time complexity is **O(log N) for search and O(K) for output (where K is occurrences count)**.
