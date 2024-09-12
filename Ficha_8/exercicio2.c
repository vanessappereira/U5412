/*
Crie um algoritmo que redimensione a string para guardar um nome à dimensão do nome inserido.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMES 10 // Limite máximo de nomes

int main()
{
    char *nomes[MAX_NOMES];
    int num_nomes = 0;

    for (int i = 0; i < MAX_NOMES; i++)
    {
        char buffer[100];

        printf("Digite o nome %d (ou deixe em branco para parar): ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);

        // Verificar se o usuário pressionou apenas Enter
        if (buffer[0] == '\n')
        {
            break;
        }

        // Remover o caractere de nova linha
        buffer[strcspn(buffer, "\n")] = '\0';

        // Alocar memória para o nome
        nomes[i] = (char *)malloc(strlen(buffer) + 1);
        if (nomes[i] == NULL)
        {
            printf("Erro ao alocar memória.\n");
            // Libertar a memória alocada até o momento (opcional)
            for (int j = 0; j < i; j++)
            {
                free(nomes[j]);
            }
            return 1;
        }

        // Copiar o nome para a nova área de memória
        strcpy(nomes[i], buffer);
        num_nomes++;
    }

    // Imprimir os nomes
    printf("\nNomes digitados:\n");
    for (int i = 0; i < num_nomes; i++)
    {
        printf("%s\n", nomes[i]);
    }

    // Libertar a memória alocada
    for (int i = 0; i < num_nomes; i++)
    {
        free(nomes[i]);
    }

    return 0;
}