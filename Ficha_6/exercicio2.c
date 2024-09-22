#include <stdio.h>

void fahrenheit()
{
    float celsius, result;

    printf("--------Celsius to Fahrenheit--------\nPlease insert a value:");
    scanf("%f", &celsius);

    result = (celsius * 9 / 5) + 32;
    printf("The value in Fahrenheit is: %.2fºF\n", result);
}

int main(int argc, char const *argv[])
{
    fahrenheit();
}