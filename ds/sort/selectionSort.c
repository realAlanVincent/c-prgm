#include <stdio.h>

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) 
    {
        int small = i;

        for (int j = i + 1; j < size; j++) 
        {
            if (arr[j] < arr[small]) 
            {
                small = j;
            }
        }

        if (small != i) // Only swap if needed
        {
            int temp = arr[i];
            arr[i] = arr[small];
            arr[small] = temp;
        }
    }
}

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

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size]; // Variable Length Array (VLA)

    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    
    selectionSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
