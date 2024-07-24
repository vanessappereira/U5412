#include <stdio.h>
// 4. Elabore 3 algoritmos em C que utilizem ciclos encadeados para imprimir os seguintes resultados:

void ex4a()
{
    int i, j;
    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

void ex4b()
{
    int n = 5;
    for (int cont1 = 0; cont1 < n; cont1++)
    {
        for (int cont2 = 0; cont2 < n; cont2++)
        {
            if (cont1 == 0 || cont2 == 0 || cont2 == n - cont1 - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void ex4c()
{
    int i, j;

    for (i = 0; i < 4; i++)
    {
        // Imprimir espaços em branco
        for (j = 0; j < 4 - i - 1; j++)
        {
            printf("  ");
        }
        // Imprimir asteriscos
        for (j = 0; j < 2 * i + 1; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

int main()
{
    ex4b();
}
