// Crie um algoritmo em C que receba uma string e imprima a contagem das palavras existentes na string.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void contarPalavras()
{
    char str[1000];
    int i, j, cont = 0;
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // remove o \n
    for (i = 0; i < strlen(str); i++)
    {
        if (isspace(str[i]))
        {
            cont++;
        }
    }
    printf("A string tem %d palavras.\n", cont + 1);
}

int main(int argc, char const *argv[])
{
    contarPalavras();
}
