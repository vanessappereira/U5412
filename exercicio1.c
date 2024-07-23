#include <stdio.h>

// Escreva um programa que solicite dois números inteiros e imprima esses números.
void print2Numeros()
{
    int num1, num2;

    // Prompt user for input
    printf("Enter the first integer: ");
    if (scanf("%d", &num1) != 1)
    {
        printf("Invalid input. Exiting.\n");
        return;
    }

    printf("Enter the second integer: ");
    if (scanf("%d", &num2) != 1)
    {
        printf("Invalid input. Exiting.\n");
        return;
    }

    // Print the input values
    printf("The entered numbers are: %d and %d\n", num1, num2);
}
// Menu
int main()
{
    print2Numeros();
    return 0;
}