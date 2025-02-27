#include <stdio.h>

// Function to find the first occurrence of target using binary search
int findFirstOccurrence(int arr[], int size, int target)
{
    int left = 0, right = size - 1, result = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            result = mid;
            right = mid - 1; // Move left to find earlier occurrence
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return result;
}

// Function to find the last occurrence of target using binary search
int findLastOccurrence(int arr[], int size, int target)
{
    int left = 0, right = size - 1, result = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            result = mid;
            left = mid + 1; // Move right to find later occurrence
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return result;
}

// Function to find all occurrences of the target
void findAllOccurrences(int arr[], int size, int target)
{
    int first = findFirstOccurrence(arr, size, target);
    int last = findLastOccurrence(arr, size, target);

    if (first == -1)
    {
        printf("Element %d not found in the array.\n", target);
        return;
    }

    // Print all occurrences
    printf("Element %d found at positions: ", target);
    for (int i = first; i <= last; i++)
    {
        printf("%d ", i);
    }
    printf("\nTotal occurrences: %d\n", (last - first + 1));
}

// Main function
int main()
{
    int size, target;

    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    // Input sorted array elements
    printf("Enter %d sorted elements: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Input target element
    printf("Enter the target element: ");
    scanf("%d", &target);

    // Find and display occurrences
    findAllOccurrences(arr, size, target);

    return 0;
}
