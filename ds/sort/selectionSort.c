#include <stdio.h>

// Optimized Selection Sort
void selectionSortOptimized(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) 
    {
        int minIndex = i;
        int swapped = 0;  // Flag to track if swap occurs

        for (int j = i + 1; j < size; j++) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
                swapped = 1;  // A swap is needed
            }
        }

        // Swap only if a smaller element was found
        if (swapped) 
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function to print an array
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

    // Taking input from the user
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, size);

    // Sorting the array
    selectionSortOptimized(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
