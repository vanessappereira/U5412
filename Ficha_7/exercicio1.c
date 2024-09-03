// Crie uma função que receba como argumentos dois arrays de números inteiros e que copie os valores de um para o outro

#include <stdio.h>

int size;

void copyArrays()
{
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arrSrc[size];
    int arrDst[size];

    printf("Enter the values for the first array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arrSrc[i]);
    }

    // Copy array 1 to array 2
    for (int i = 0; i < size; i++)
    {
        arrDst[i] = arrSrc[i];
    }

    printf("Array copiado: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arrDst[i]);
    }
}

int main(int argc, char const *argv[])
{
    copyArrays();
}
