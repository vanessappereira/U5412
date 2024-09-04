// Crie uma função que devolva um número aleatório entre dois números inteiros passados como argumentos.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomBetween(int min, int max)
{
    // Inicializar um número aleatório
    srand(time(NULL));

    // Gerar um número aleatório entre o min e max
    return min + rand() % (max - min + 1);
}

int main(int argc, char const *argv[])
{
    int min, max, randomNumber;

    // Solicitar 2 números ao utilizador
    printf("Insira o número mínimo: ");
    scanf("%d", &min);

    printf("Insira o número máximo: ");
    scanf("%d", &max);

    // Result
    randomNumber = randomBetween(min, max);
    printf("O número que saiu entre o %d e %d foi: %d\n", min, max, randomNumber);

    return 0;
}
