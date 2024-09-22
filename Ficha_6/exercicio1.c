#include <stdio.h>
#define PI 3.14159265359
void circleArea()
{
    int r;
    float result;

    printf("--------Circle Area--------\nPlease insert a value:");
    scanf("%d", &r);

    result = PI * r * r;
    printf("The area of the circle is: %f\n", result);
}

int main(int argc, char const *argv[])
{
    circleArea();
}