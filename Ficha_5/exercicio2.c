// Crie um algoritmo em C que receba uma string e faça a substituição dos espaços em branco por underscore ‘_’.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void goingUnder(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            str[i] = '_';
        }
        i++;
    }
}

int main(int argc, char const *argv[])
{
    char str[100];

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    goingUnder(str);

    printf("String convertida: %s", str);
}
