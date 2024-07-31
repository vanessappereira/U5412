#include <stdio.h>

// swap array elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Separate odd in left side and even in right
void separate(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        // if number in the left side is odd, move to next position
        if (arr[left] % 2 != 0)
        {
            left++;
        }
        // if number in the right side is even, move to previous position
        else if (arr[right] % 2 == 0)
        {
            right--;
        }
        // if number in the left side is even and number in the right side is odd, swap
        else
        {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int arr[] = {12, 44, 1, 23, 45, 13, 55, 65, 77};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Original Array
    printf("Original array: ");
    printArray(arr, n);
    
    // Separate odd in left side and even in right
    separate(arr, n);
    
    // Print the modified array
    printf("Modified array: ");
    printArray(arr, n);
    
    return 0;
}
