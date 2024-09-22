#include <stdio.h>

/* 1. Elabore um algoritmo em C que preencha uma matriz de inteiros com 5 linhas e 5 colunas.
Faça as trocas necessárias para que as linhas se transformem em colunas (1ª linha → 1ª coluna, 2ª linha → 2ª coluna, … , 5ª
linha → 5ª coluna) utilizando obrigatoriamente ciclos. */

#include <stdio.h>

void matriz()
{
    int SIZE = 5;
    int matriz[SIZE][SIZE];
    int transposicao[SIZE][SIZE];

    // Inicializa e imprime a matriz original
    printf("Matriz original:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matriz[i][j] = i * SIZE + j + 1;
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Transpõe a matriz
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            transposicao[j][i] = matriz[i][j];
        }
    }

    // Imprime a matriz transposta
    printf("\nMatriz transposta:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%3d ", transposicao[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    matriz();
}
