#include <stdio.h>

#define NUM_STUDENTS 2
#define NUM_SUBJECTS 5

int main()
{
    /* TODO: declare the 2D array grades here */
    float average;
    float grades[NUM_STUDENTS][NUM_SUBJECTS] = {
        {80, 70, 65, 89, 90},
        {85, 80, 80, 82, 87}};

    int i;
    int j;

    /* TODO: complete the for loop with appropriate terminating conditions */
    for (i = 0; i < NUM_STUDENTS; i++)
    {
        average = 0;
        for (j = 0; j < NUM_SUBJECTS; j++)
        {
            average += grades[i][j];
        }

        /* TODO: compute the average marks for subject i */
        average /= NUM_SUBJECTS;
        printf("The average marks obtained in subject %d is: %.2f\n", i, average);
    }

    return 0;
}