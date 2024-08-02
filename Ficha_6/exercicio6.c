#include <stdio.h>
int moreFrequent(int arr[], int n)
{

    int maxFreq = 0;
    int maxValue = -1;
    int freq[100] = {0};

    // count the frequency of each number
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    // find the number with more frequency
    for (int i = 0; i < 100; i++)
    {
        if (freq[i] > maxFreq)
        {
            maxFreq = freq[i];
            maxValue = i;
        }
    }

    // if there is no repeated numbers, return -1
    if (maxFreq == 1)
    {
        return -1;
    }
    return maxValue;
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 45, 2, 8, 9, 34, 7, 4, 23, 66, 22};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = moreFrequent(arr, size);

    (result == -1) ? printf("There is no repeated numbers\n") : printf("The number that appears more frequently is %d\n", result);

    return 0;
}
