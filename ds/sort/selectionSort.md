# Selection Sort in C - Explanation

## Introduction
Selection Sort is a simple and efficient sorting algorithm that works by repeatedly selecting the smallest element from the unsorted part of the array and swapping it with the first element of the unsorted part. This process continues until the entire array is sorted.

## C Program (Allman Style)
```c
#include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        // Find the index of the smallest element in the unsorted part
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int size;
    
    // Taking array size from the user
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    // Handle invalid sizes
    if (size <= 0)
    {
        printf("Invalid array size! Please enter a positive number.\n");
        return 1;
    }

    int arr[size];

    // Taking array elements from the user
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Sorting the array
    selectionSort(arr, size);

    // Printing the sorted array
    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
```

## Explanation (Line by Line)

1. **Header Inclusion:**
   ```c
   #include <stdio.h>
   ```
   - Includes the standard input-output library to use `printf` and `scanf` functions.

2. **Selection Sort Function:**
   ```c
   void selectionSort(int arr[], int size)
   ```
   - Accepts an array and its size as parameters.
   - Iterates through the array and selects the smallest element to move to its correct position.

3. **Finding the Minimum Element:**
   ```c
   for (int j = i + 1; j < size; j++)
   {
       if (arr[j] < arr[minIndex])
       {
           minIndex = j;
       }
   }
   ```
   - A nested loop runs through the unsorted part of the array to find the smallest element.

4. **Swapping Elements:**
   ```c
   if (minIndex != i)
   {
       int temp = arr[i];
       arr[i] = arr[minIndex];
       arr[minIndex] = temp;
   }
   ```
   - If a smaller element is found, it is swapped with the current element.

5. **Printing the Array:**
   ```c
   void printArray(int arr[], int size)
   ```
   - Iterates through the array and prints each element.

6. **Main Function:**
   ```c
   int main()
   ```
   - Takes user input for array size and elements.
   - Calls `selectionSort()` to sort the array.
   - Prints the sorted array.

## Example Execution
### Input:
```
Enter the number of elements: 5
Enter 5 elements: 64 25 12 22 11
```

### Sorting Process:
1. Selects `11` as the smallest and swaps with `64`
2. Selects `12` as the smallest and swaps with `25`
3. Selects `22` as the smallest and swaps with `64`
4. Selects `25` as the smallest and swaps with `64`

### Output:
```
Sorted array: 11 12 22 25 64
```

## Time Complexity
- **Best Case (Already Sorted):** O(n²)
- **Worst Case (Reversed Order):** O(n²)
- **Average Case:** O(n²)

## Space Complexity
- O(1) (In-place sorting algorithm, no extra space required)

## Conclusion
Selection Sort is a straightforward algorithm that works well for small datasets. However, it is inefficient for large datasets compared to more advanced algorithms like Quick Sort or Merge Sort.
