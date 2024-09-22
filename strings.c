#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int aleatorio;
    srand(time(NULL));
    aleatorio = rand();
    printf("Aleatorio Maximo: [%i]\n", RAND_MAX);
    printf("Aleatorio: [%i]\n", aleatorio);
    printf("Aleatorio entre 0 E 99: [%i]\n", aleatorio % 100);
    printf("Aleatorio entre 1 E 100: [%i]\n", aleatorio % 100 + 1);

    return 0;
}
