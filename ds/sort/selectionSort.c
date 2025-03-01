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
