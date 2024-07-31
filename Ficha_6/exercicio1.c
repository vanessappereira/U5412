#include <stdio.h>

void circleArea()
{
    int r;
    float result;

    printf("--------Circle Area--------\nPlease insert a value:");
    scanf("%d", &r);
    
    result = 3.14 * r * r;
    printf("The area of the circle is: %f\n", result);
}

int main(int argc, char const *argv[])
{
    circleArea();
}