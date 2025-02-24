#include <stdio.h>

void insertion(int arr[], int *n)
{
    int pos, element;
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position (1 to %d): ", *n + 1);
    scanf("%d", &pos);
    
    if (pos < 1 || pos > *n + 1)
    {
        printf("Invalid position!\n");
        return;
    }
    
    // Shift elements to the right to make space
    for (int i = *n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    
    arr[pos - 1] = element;
    (*n)++;
    printf("After insertion:\n");
}

void deletion(int arr[], int *n)
{
    int pos;
    
    if (*n == 0)
    {
        printf("Array is empty, nothing to delete.\n");
        return;
    }
    
    printf("Enter the position to delete (1 to %d): ", *n);
    scanf("%d", &pos);
    
    if (pos < 1 || pos > *n)
    {
        printf("Invalid position!\n");
        return;
    }
    
    int deletedElement = arr[pos - 1];
    
    // Shift elements to the left to fill the gap
    for (int i = pos - 1; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    
    (*n)--;
    printf("Deleted element: %d\n", deletedElement);
    printf("After deletion:\n");
}

void merging(int arr[], int *n)
{
    int m;
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &m);
    
    if (m <= 0)
    {
        printf("No elements to merge.\n");
        return;
    }
    
    int temp[100];  // Temporary array to store second array elements
    printf("Enter %d elements for the second array:\n", m);
    
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &temp[i]);
    }
    
    // Check if merging exceeds the fixed array capacity (100)
    if (*n + m > 100)
    {
        printf("Merging would exceed array capacity. Operation aborted.\n");
        return;
    }
    
    // Append second array elements to the first array
    for (int i = 0; i < m; i++)
    {
        arr[*n + i] = temp[i];
    }
    
    *n += m;
    printf("After merging:\n");
}

void traversal(int arr[], int n)
{
    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    
    printf("Array elements: ");
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
}

int main()
{
    int arr[100];
    int n, choice;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    if (n > 100)
    {
        printf("Maximum capacity is 100. Setting number of elements to 100.\n");
        n = 100;
    }
    
    printf("Enter %d elements:\n", n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    while (1)
    {
        printf("\nArray Operations Menu:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Merging\n");
        printf("4. Traversal (Print Array)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                insertion(arr, &n);
                traversal(arr, n);
                break;
            
            case 2:
                deletion(arr, &n);
                traversal(arr, n);
                break;
            
            case 3:
                merging(arr, &n);
                traversal(arr, n);
                break;
            
            case 4:
                traversal(arr, n);
                break;
            
            case 5:
                printf("Exiting program.\n");
                return 0;
            
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
