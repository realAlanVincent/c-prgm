#include <stdio.h>
#include <stdbool.h>

// Swap function for better readability
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Optimized Bubble Sort
void bubbleSort(int arr[], int n) 
{
    bool swapped;
    
    for (int i = 0; i < n - 1; i++) 
    {
        swapped = false;
        
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        
        // Break if no swaps were made
        if (!swapped) 
        {
            break;
        }
    }
}

// Function to print the array
void printArray(const int *arr, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int n;
    
    // Taking input for the array size
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0) 
    {
        printf("Invalid input! Number of elements should be positive.\n");
        return 1;
    }

    int arr[n]; // Variable-Length Array (VLA)

    // Taking input for the array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    // Sorting the array
    bubbleSort(arr, n);
    
    // Printing the sorted array
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
