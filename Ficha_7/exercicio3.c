/*
Crie um array para armazenar os dados referentes aos 30 aeroportos públicos de Portugal. O array deve utilizar a seguinte estrutura, e criar as seguintes funções para gestão do array
    inserir ( )
    listar ( )
    procurar ( )
    alterar ( )
*/
#include <stdio.h>
#include <string.h>

// Definição de constantes
#define MAX_IATA 3
#define MAX_ICAO 4
#define MAX_NOME 50
#define MAX_MUNICIPIO 50
#define MAX_AEROPORTOS 30

// Definição da estrutura Aeroporto
typedef struct
{
    char municipio[MAX_MUNICIPIO + 1];
    char ICAO[MAX_ICAO + 1];
    char IATA[MAX_IATA + 1];
    char nome[MAX_NOME + 1];
} Aeroporto;

Aeroporto aeroportos[MAX_AEROPORTOS];

// Inserir Aeroportos
void inserirAeroporto(Aeroporto *aeroportos, int *quantidadeAeroportos)
{
    // Confirmar se vai exceder a quantidade limite de Aeroportos
    if (*quantidadeAeroportos < MAX_AEROPORTOS)
    {
        printf("Introduza o nome do aeroporto: ");
        fgets(aeroportos[*quantidadeAeroportos].nome, MAX_NOME, stdin);
        aeroportos[*quantidadeAeroportos].nome[strcspn(aeroportos[*quantidadeAeroportos].nome, "\n")] = 0;

        printf("Introduza o código ICAO do aeroporto: ");
        fgets(aeroportos[*quantidadeAeroportos].ICAO, MAX_ICAO, stdin);
        aeroportos[*quantidadeAeroportos].ICAO[strcspn(aeroportos[*quantidadeAeroportos].ICAO, "\n")] = 0;

        printf("Introduza o código IATA do Aeroporto: ");
        fgets(aeroportos[*quantidadeAeroportos].IATA, MAX_IATA, stdin);
        aeroportos[*quantidadeAeroportos].IATA[strcspn(aeroportos[*quantidadeAeroportos].IATA, "\n")] = 0;

        printf("Introduza o Municipio do aeroporto: ");
        fgets(aeroportos[*quantidadeAeroportos].municipio, MAX_MUNICIPIO, stdin);
        aeroportos[*quantidadeAeroportos].municipio[strcspn(aeroportos[*quantidadeAeroportos].municipio, "\n")] = 0;

        // Adicionar +1 qnt de aeroportos
        (*quantidadeAeroportos)++;
    }
    else
    {
        printf("Limite de Aeroportos atingido!\n");
    }
}
// Imprimir Aeroporto
void imprimirAeroporto(Aeroporto aeroportos[], int *quantidadeAeroportos)
{
    for (int i = 0; i < *quantidadeAeroportos; i++)
    {
        printf("Aeroporto %d:\n", i + 1);
        printf("Nome: %s\n", aeroportos[i].nome);
    }
}

// Listar Aeroporto
void listarAeroportos(Aeroporto *aeroportos, int *quantidadeAeroportos)
{
    // Verificar se tem aeroportos
    if (*quantidadeAeroportos == 0)
    {
        printf("Não existem aeroportos!\n");
    }
    for (int i = 0; i < *quantidadeAeroportos; i++)
    {
        printf("Aeroporto %d: \n", i + 1);
        printf("Nome: %s\n", aeroportos[i].nome);
        printf("Municipio: %s\n", aeroportos[i].municipio);
        printf("ICAO: %s\n", aeroportos[i].ICAO);
        printf("IATA: %s\n", aeroportos[i].IATA);
    }
}

// Procurar Aeroportos
void procurarAeroportos(Aeroporto *aeroportos, int *quantidadeAeroportos)
{
    char procurarNome[MAX_NOME];

    // Verificar se tem aeroportos
    if (*quantidadeAeroportos > 0)
    {
        printf("Introduza o nome do aeroporto que deseja procurar: ");

        if (fgets(procurarNome, MAX_NOME, stdin) == NULL)
        {
            // Trata erro de leitura
            printf("Erro ao ler o nome do aeroporto.\n");
            return;
        }

        // Remove o caractere de nova linha do final da string
        procurarNome[strcspn(procurarNome, "\n")] = 0;

        // Procura o aeroporto
        for (int i = 0; i < *quantidadeAeroportos; i++)
        {
            if (strcmp(aeroportos[i].nome, procurarNome) == 0)
            {
                // Aeroporto encontrado, imprime informações
                printf("Aeroporto encontrado:\n");
                printf("Nome: %s\n", aeroportos[i].nome);
                printf("Municipio: %s\n", aeroportos[i].municipio);
                printf("ICAO: %s\n", aeroportos[i].ICAO);
                printf("IATA: %s\n", aeroportos[i].IATA);
                return;
            }
        }
    }
    printf("Não existem aeroportos!\n");
}
// Alterar Aeroportos
void alterarAeroportos(Aeroporto *aeroportos, int *quantidadeAeroportos)
{
    char alterarNome[MAX_NOME];
    if (*quantidadeAeroportos > 0)
    {
        printf("Introduza o nome do aeroporto que deseja alterar: ");
        if (fgets(alterarNome, MAX_NOME, stdin) != NULL)
        {
            alterarNome[strcspn(alterarNome, "\n")] = '\0';

            // Procurar o aeroporto com base na variável anterior
            for (int i = 0; i < *quantidadeAeroportos; i++)
            {
                if (strcmp(aeroportos[i].nome, alterarNome) == 0)
                {
                    // Solicitação de aLterar o nome
                    printf("Introduza o novo nome do aeroporto: ");
                    fgets(aeroportos[i].nome, MAX_NOME, stdin);
                    aeroportos[i].nome[strcspn(aeroportos[i].nome, "\n")] = '\0';

                    // Confirmação do nome alterado e imprimir a modificação
                    printf("Alterado com sucesso!\n");
                    printf("Nome do aeroporto alterado: %s\n", aeroportos[i].nome);
                    printf("Municipio: %s\n", aeroportos[i].municipio);
                    printf("ICAO: %s\n", aeroportos[i].ICAO);
                    printf("IATA: %s\n", aeroportos[i].IATA);
                    return;
                }
            }
        }
    }
    printf("Não existem aeroportos!\n");
}

int main(int argc, char const *argv[])
{
    int opcao;
    int qntAeroportos = 0;
    while (1)
    {
        printf("----- Menu -----\n");
        printf("1. Inserir Aeroporto\n");
        printf("2. Listar Aeroportos\n");
        printf("3. Procurar Aeroporto\n");
        printf("4. Alterar Aeroporto\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            inserirAeroporto(aeroportos, &qntAeroportos);
            break;
        case 2:
            listarAeroportos(aeroportos, &qntAeroportos);
            break;
        case 3:
            procurarAeroportos(aeroportos, &qntAeroportos);
            break;
        case 4:
            alterarAeroportos(aeroportos, &qntAeroportos);
            break;
        case 0:
            printf("Obrigado por utilizar o programa!\nSaindo...\n");
            return 0;
        default:
            printf("Opção inválida. Por favor, tente novamente.\n");
        }
    }
    return 0;
}
