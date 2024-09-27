/* Praias Base */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "praias.h"
#include "localidades.h"

/* Praias */

// Criar ficheiro de praias
void criarFicheiroPraias()
{
    const char *filename = "praias.txt";
    FILE *fpPraias = fopen(filename, "wb");
    if (fpPraias == NULL)
    {
        fprintf(stderr, "Erro ao criar ficheiro de praias: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    if (fclose(fpPraias) == EOF)
    {
        fprintf(stderr, "Erro ao fechar ficheiro de praias: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}
int obterProximoIdPraia()
{
    const char *filename = "praias.txt";
    Praia praia;
    int maxId = 0;

    FILE *fpPraias = fopen(filename, "rb");

    if (fpPraias == NULL)
    {
        // Se o ficheiro não existir, retorne 1 como o primeiro ID
        return 1;
    }

    // Ler todas as praias do ficheiro e encontrar o ID máximo
    while (fread(&praia, sizeof(Praia), 1, fpPraias))
    {
        if (praia.idPraia > maxId)
        {
            maxId = praia.idPraia;
        }
    }

    fclose(fpPraias);
    return maxId + 1; // Retorna o próximo ID
}

// Registar praia
void registarPraia()
{
    const char *filenamePraias = "praias.txt";
    const char *filenameLocalidades = "localidades.txt";

    Praia novaPraia;
    Localidade novaLocalidade;

    FILE *fpPraias = fopen(filenamePraias, "ab");
    FILE *fpLocalidades = fopen(filenameLocalidades, "ab");

    if (fpPraias == NULL || fpLocalidades == NULL)
    {
        fprintf(stderr, "Erro ao abrir ficheiro de praias ou localidades: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    novaPraia.idPraia = obterProximoIdPraia(); // Obtém o próximo ID

    // Solicitar o nome da praia
    printf("Introduza o nome da praia: ");
    scanf("%99s", novaPraia.nomePraia);

    // Solicitar o tipo de praia
    do
    {
        getchar(); // Limpa buffer após ler o inteiro

        printf("Introduza o tipo de praia (1 - Oceânica, 2 - Fluvial): ");
        int tipo;

        scanf("%d", &tipo);

        if (tipo == OCEANICA || tipo == FLUVIAL)
        {
            novaPraia.tipoPraia = tipo;
        }
        else
        {
            printf("Tipo inválido. Por favor, insira 1 ou 2.\n");
        }
    } while (!(novaPraia.tipoPraia == OCEANICA || novaPraia.tipoPraia == FLUVIAL));

    // Solicitar a localidade da praia, funcção registarLocalidade de localidades.h
    registarLocalidade(&novaLocalidade);

    strcpy(&novaPraia.localidadePraia, novaLocalidade.nomeLocalidade);

    fseek(fpPraias, 0, SEEK_END);
    fseek(fpLocalidades, 0, SEEK_END);
    
    fwrite(&novaLocalidade, sizeof(Localidade), 1, fpLocalidades);
    fwrite(&novaPraia, sizeof(Praia), 1, fpPraias);

    fclose(fpPraias);
    fclose(fpLocalidades);

    // Mensagem
    printf("Praia registada com sucesso!\n");
}

// Listar praias
void listarPraias()
{
    Praia praia;
    const char *filename = "praias.txt";

    FILE *fpPraias = fopen(filename, "rb");

    if (fpPraias == NULL)
    {
        fprintf(stderr, "Erro ao abrir ficheiro de praias: %s\n", strerror(errno));
        return;
    }

    printf("Lista de Praias:\n");

    while (fread(&praia, sizeof(Praia), 1, fpPraias))
    {
        printf("ID: %d | Nome: %s | Localidade: %c | Tipo: %s\n",
               praia.idPraia,
               praia.nomePraia,
               praia.localidadePraia,
               (praia.tipoPraia == OCEANICA ? "Oceânica" : "Fluvial"));
        break;
    }

    fclose(fpPraias);
}

// Listar praias com idLocalidade
void listarPraiasIdLocalidade()
{
    const char *filename = "praias.txt";
    int idLocalidade, found = 0;
    Praia praia;

    FILE *fpPraias = fopen(filename, "rb");

    if (fpPraias == NULL)
    {
        fprintf(stderr, "Erro ao abrir ficheiro de praias: %s\n", strerror(errno));
        return;
    }

    printf("Digite o ID da localidade: ");
    scanf("%d", &idLocalidade);

    while (fread(&praia, sizeof(Praia), SEEK_CUR, fpPraias))
    {
        if (praia.localidadePraia == idLocalidade)
        {
            found = 1;
            printf("Listagem de praias da localidade %d:\n", idLocalidade);
            printf("ID: %d | Nome: %s | Tipo: %s\n",
                   praia.idPraia,
                   praia.nomePraia,
                   (praia.tipoPraia == OCEANICA ? "Oceânica" : "Fluvial"));
        }
    }
    if (!found)
    {
        printf("Nenhuma praia encontrada para a localidade %d.\n", idLocalidade);
    }
    fclose(fpPraias);
}

// Procurar praia (Nome)
void procurarPraiaNome()
{
    const char *filename = "praias.txt";
    char nome_Praia[100];
    int found = 0;
    Praia praia;

    FILE *fpPraias = fopen(filename, "rb");

    if (fpPraias == NULL)
    {
        fprintf(stderr, "Erro ao abrir ficheiro de praias: %s\n", strerror(errno));
        return;
    }

    printf("Digite o nome da praia: ");
    scanf("%99s", nome_Praia);

    // Ler uma Praia de cada vez
    while (fread(&praia, sizeof(Praia), 1, fpPraias) == 1)
    {
        // Usar strcmp para comparação
        if (strcmp(praia.nomePraia, nome_Praia) == 0)
        {
            found = 1;
            printf("Listagem de praias com o nome %s:\n", nome_Praia);
            printf("ID: %d | Nome: %s | Localidade: %d | Tipo: %s\n",
                   praia.idPraia,
                   praia.nomePraia,
                   praia.localidadePraia,
                   (praia.tipoPraia == OCEANICA ? "Oceânica" : "Fluvial"));
        }
    }

    if (!found)
    {
        printf("Nenhuma praia encontrada com o nome %s.\n", nome_Praia);
    }
    fclose(fpPraias);
}

// Alterar praia (idPraia)
void alterarPraiaId()
{
    const char *filename = "praias.txt";
    Praia praia;
    int id_Praia, localidadePraia, tipoPraia;
    char nomePraia[MAX_PRAIA_NOME_SIZE];
    int found = 0;
    long int offset = 0;

    FILE *fpPraias = fopen(filename, "rb+");

    if (fpPraias == NULL)
    {
        fprintf(stderr, "Erro ao abrir ficheiro de praias: %s\n", strerror(errno));
        return;
    }

    listarPraias();

    // Solicitar o id da praia para alteração
    printf("Digite o ID da praia a alterar: ");
    while (scanf("%d", &id_Praia) != 1)
    {
        printf("Input inválido. Tente novamente.\n");
        while (getchar() != '\n')
            ; // Limpa buffer
    }

    // Ler uma Praia de cada vez
    while (fread(&praia, sizeof(Praia), 1, fpPraias) == 1)
    {
        if (praia.idPraia == id_Praia)
        {
            found = 1;
            break;
        }
        offset += sizeof(Praia);
    }

    if (!found)
    {
        printf("Praia não encontrada.\n");
        fclose(fpPraias);
        return;
    }

    // Solicitar os dados da praia
    printf("Digite o nome da praia: ");
    while (scanf("%99s", nomePraia) != 1)
    {
        printf("Input inválido. Tente novamente.\n");
        while (getchar() != '\n')
            ; // Limpa buffer
    }

    printf("Digite a localidade da praia: ");
    while (scanf("%d", &localidadePraia) != 1)
    {
        printf("Input inválido. Tente novamente.\n");
        while (getchar() != '\n')
            ; // Limpa buffer
    }

    printf("Digite o tipo da praia (1 - Oceânica, 2 - Fluvial): ");
    while (scanf("%d", &tipoPraia) != 1 || (tipoPraia != OCEANICA && tipoPraia != FLUVIAL))
    {
        printf("Input inválido. Tente novamente.\n");
        while (getchar() != '\n')
            ; // Limpa buffer
    }

    // Alterar os dados da praia
    strcpy(praia.nomePraia, nomePraia);
    praia.localidadePraia = localidadePraia;
    praia.tipoPraia = tipoPraia;

    // Gravar os dados da praia, confirmar se há algum erro de atualizar os dados ou de gravar no ficheiro
    if (fseek(fpPraias, offset, SEEK_SET) != 0)
    {
        printf("Erro a atualizar a praia no ficheiro.\nOs dados estão no estado original\n");
        fclose(fpPraias);
        return;
    }

    if (fwrite(&praia, sizeof(Praia), 1, fpPraias) != 1)
    {
        printf("Erro a gravar no ficheiro.\n");
        fclose(fpPraias);
        return;
    }

    printf("Praia alterada com sucesso!\n");
    fclose(fpPraias);
}

void exportarPraias()
{
    Praia praia;

    const char *filename = "praias.txt";
    const char *exportFilename = "Lista de Praias.csv";

    FILE *fpPraias = fopen(filename, "rb");
    FILE *fpExport = fopen(exportFilename, "w+");

    // Leitura de ficheiro praias.txt
    if (fpPraias == NULL)
    {
        fprintf(stderr, "Erro ao abrir ficheiro de praias: %s\n", strerror(errno));
        return;
    }

    // Leitura de ficheiro Lista de Praias.csv
    if (fpExport == NULL)
    {
        fprintf(stderr, "Erro ao criar ficheiro de exportação: %s\n", strerror(errno));
        fclose(fpPraias);
        return;
    }

    // Cabeçalho
    fprintf(fpExport, "Nome Localidade;Nome Praia;Tipo Praia\n");

    while (fread(&praia, sizeof(Praia), 1, fpPraias) == 1)
    {
        // Adicionar o nome da localidade em vez do localidadePraia
        fprintf(fpExport, "%d;%s;%s\n",
                praia.localidadePraia,
                praia.nomePraia,
                praia.tipoPraia == OCEANICA ? "Oceânica" : "Fluvial");
    }

    fclose(fpPraias);
    fclose(fpExport);

    // Mensagem
    printf("Praias exportadas com sucesso para %s!\n", exportFilename);
}
