#include <stdio.h>

int binarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid + 1; // Return position (1-based)
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1; // Element not found
}

int main(void)
{
    int arr[] = { 2, 4, 6, 8, 10, 12 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 8;
    int pos = binarySearch(arr, size, target);
    
    if (pos != -1)
    {
        printf("Element %d is at position %d\n", target, pos);
    }
    else
    {
        printf("Element %d is not found in the array.\n", target);
    }
    
    return 0;
}
