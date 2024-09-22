#include <stdio.h>
// 1. Construa um programa em C que preencha um array de 10 números inteiros. O programa deve movimentar para a esquerda do array os números ímpares e para a direita os números pares.
void arraySeparador()
{
    int array[10], i, j, aux;

    // Solicitar 10 numeros ao utilizador, e adicionar no array
    for (i = 0; i < 10; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &array[i]);
    }

    // verificar se o número é divisivel por 2
    for (i = 0; i < 10; i++)
    {
        if (array[i] % 2 != 0)
        {
            // se o número for ímpar, mover para a esquerda
            for (j = i; j > 0; j--)
            {
                aux = array[j];
                array[j] = array[j - 1];
                array[j - 1] = aux;
            }
        }
    }

    // Imprimir o array
    printf("O seu novo array é: \n");
    for (i = 0; i < 10; i++)
    {

        printf("%d ", array[i]);
    }
}

int main()
{
    arraySeparador();
}