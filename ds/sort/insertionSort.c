#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements that are greater than key one position ahead
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    
    int arr[size];
    
    // Taking array elements from the user
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    // Sorting the array
    insertionSort(arr, size);
    
    // Printing the sorted array
    printf("Sorted array: ");
    printArray(arr, size);
    
    return 0;
}
