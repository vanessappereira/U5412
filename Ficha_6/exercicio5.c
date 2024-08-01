#include <stdio.h>

// swap array elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Separate odd in left side and even in right
void separateOddAndEven(int arr[], int n)
{
    int left = 0;      // Index for odd numbers
    int right = n - 1; // Index for even numbers

    while (left < right)
    {
        if (arr[left] % 2 == 0)
        {
            // If left element is even, swap it with right element
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            right--;
        }
        else
        {
            left++;
        }
    }
    // sort ascending left
    for (int i = 0; i < left; i++)
    {
        for (int j = i + 1; j < left; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
    // sort ascending right
    for (int i = left; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
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
    int arr[] = {12, 44, 10, 23, 45, 14, 55, 65, 77};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Original Array
    printf("Original array: ");
    printArray(arr, n);

    // Separate odd in left side and even in right
    separateOddAndEven(arr, n);

    // Print the modified array
    printf("Modified array: ");
    printArray(arr, n);

    return 0;
}
