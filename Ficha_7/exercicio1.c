// Crie uma função que receba como argumentos dois arrays de números inteiros e que copie os valores de um para o outro

#include <stdio.h>
#include <stdlib.h>

// 1. Ler os valores de um array
void readArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

// 2. Função para copiar os valores de um array para o outro
void copyArray(int *arrSrc, int *arrDst, int sizeArr)
{
    for (int j = 0; j < sizeArr; j++)
    {
        arrDst[j] = arrSrc[j];
    }
}

// 3. Função para imprimir os valores de um array
void printArray(int *arr, int sizeArr)
{
    for (int i = 0; i < sizeArr; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int size;

    // Inserção tamanho array
    printf("Insira o tamanho do array: ");
    scanf("%d", &size);
    /*
        int arrSrc[size];
        int arrDst[size];

        Line 41 & 42: expression must have a constant value
        in C, the size of an array must be a constant expression. In this case, is a variable, and not a constant.
        A possible solution: use dynamic memory allocation using malloc and free to allocate memory for the arrays at runtime.
    */

    // Alocação dinâmica de memória para os arrays
    int *arrSrc = (int *)malloc(size * sizeof(int));
    int *arrDst = (int *)malloc(size * sizeof(int));

    if (arrSrc == NULL || arrDst == NULL)
    {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    // Inserção de valores
    printf("Insira os valores para o array: ");
    readArray(arrSrc, size);

    // Copiar array 1 para 2
    copyArray(arrSrc, arrDst, size);

    // Impressão do array 2
    printf("Array copiado: ");
    printArray(arrDst, size);

    return 0;
}
