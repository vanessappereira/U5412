#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constants
#define LOCALIDADE_NOME_SIZE 100
#define LOCALIDADE_LINHA_SIZE 100
#define PRAIA_NOME_SIZE 100
#define PRAIA_TIPO_SIZE 10

// Struct definitions
typedef struct
{
    int IDLocalidade;
    char nomeLocalidade[LOCALIDADE_NOME_SIZE];
} Localidade;

typedef struct
{
    int IDPraia;
    int IDLocalidade;
    char nomePraia[PRAIA_NOME_SIZE];
    char tipo[PRAIA_TIPO_SIZE]; // "oceânica" ou "fluvial"
} Praia;

/* Praias */
// Criar ficheiro de praias
void criarFicheiroPraias()
{
    FILE *fpPraias = fopen("praias.txt", "wb");
    if (fpPraias == NULL)
    {
        printf("Erro ao criar ficheiro de praias\n");
        exit(1);
    }
    fclose(fpPraias);
}
// Registar Praia
void registarPraia()
{
    Praia novaPraia;

    FILE *fpPraias = fopen("praias.txt", "ab");
    FILE *fpLocalidade = fopen("localidades.txt", "ab");

    // Registar a nova praia
    printf("Introduza o nome da praia: ");
    fgets(novaPraia.nomePraia, sizeof(novaPraia.nomePraia), stdin);
    novaPraia.nomePraia[strlen(novaPraia.nomePraia) - 1] = '\0';
    // Discard any remaining characters in the input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    // Adicionar o tipo de praia
    printf("Introduza o tipo de praia: (oceânica/fluvial)");
    fgets(novaPraia.tipo, sizeof(novaPraia.tipo), stdin);
    novaPraia.tipo[strlen(novaPraia.tipo) - 1] = '\0';


    // Adicionar a localidade da praia
    printf("Introduza o ID da localidade da praia: ");
    scanf("%d", &novaPraia.IDLocalidade);
    getchar();

    // Gerar ID automático
    novaPraia.IDPraia = 1;
    if (fseek(fpPraias, 0, SEEK_END) == 0)
    {
        fseek(fpPraias, -sizeof(Praia), SEEK_END);
        fread(&novaPraia.IDPraia, sizeof(int), 1, fpPraias);
        novaPraia.IDPraia++;
    }
    fwrite(&novaPraia, sizeof(Praia), 1, fpPraias);

    fclose(fpPraias);
}
// Listar Praia
void listarPraias()
{
    Praia praia;
    FILE *fp = fopen("praias.txt", "rb");
    if (fp == NULL)
    {
        printf("Erro ao abrir ficheiro de praias\n");
        exit(1);
    }

    printf("Listagem de praias:\n");
    while (fread(&praia, sizeof(Praia), 1, fp) == 1)
    {
        printf("ID: %d\n", praia.IDPraia);
        printf("Nome: %s\n", praia.nomePraia);
        printf("Tipo: %s\n", praia.tipo);
        printf("ID Localidade: %d\n\n", praia.IDLocalidade);
    }

    fclose(fp);
}
// Listar Praias por Localidade através do IDLocalidade
void listarPraiasPorLocalidade()
{
    int idLocalidade;
    Praia praia;
    FILE *fp = fopen("praias.txt", "rb");
    if (fp == NULL)
    {
        printf("Erro ao abrir ficheiro de praias\n");
        exit(1);
    }

    printf("Digite o ID da localidade: ");
    scanf("%d", &idLocalidade);
    getchar();

    printf("Listagem de praias da localidade %d:\n", idLocalidade);
    while (fread(&praia, sizeof(Praia), 1, fp) == 1)
    {
        if (praia.IDLocalidade == idLocalidade)
        {
            printf("ID: %d\n", praia.IDPraia);
            printf("Nome: %s\n", praia.nomePraia);
            printf("Tipo: %s\n\n", praia.tipo);
        }
    }

    fclose(fp);
}

// Procurar Praia (Procurar através do Nome)
void procurarPraia()
{
    char nome[50];
    Praia praia;
    FILE *fp = fopen("praias.txt", "rb");
    if (fp == NULL)
    {
        printf("Erro ao abrir ficheiro de praias\n");
        exit(1);
    }

    printf("Digite o nome da praia: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = '\0';

    printf("Resultados da procura:\n");
    while (fread(&praia, sizeof(Praia), 1, fp) == 1)
    {
        if (strcmp(praia.nomePraia, nome) == 0)
        {
            printf("ID: %d\n", praia.IDPraia);
            printf("Nome: %s\n", praia.nomePraia);
            printf("Tipo: %s\n", praia.tipo);
            printf("ID Localidade: %d\n\n", praia.IDLocalidade);
        }
    }

    fclose(fp);
}

// Alterar Praia (Alterar utilizando o IDPraia para procurar)
void alterarPraia()
{
    int idPraia;
    Praia praia;

    FILE *fp = fopen("praias.txt", "rb+");
    if (fp == NULL)
    {
        printf("Erro ao abrir ficheiro de praias\n");
        exit(1);
    }

    printf("Digite o ID da praia a alterar: ");
    scanf("%d", &idPraia);
    getchar();

    while (fread(&praia, sizeof(Praia), 1, fp) == 1)
    {
        if (praia.IDPraia == idPraia)
        {
            printf("Digite o novo nome da praia: ");
            fgets(praia.nomePraia, sizeof(praia.nomePraia), stdin);
            praia.nomePraia[strlen(praia.nomePraia) - 1] = '\0';

            printf("Digite o novo tipo da praia (oceânica/fluvial): ");
            fgets(praia.tipo, sizeof(praia.tipo), stdin);
            praia.tipo[strlen(praia.tipo) - 1] = '\0';

            printf("Digite o novo ID da localidade: ");
            scanf("%d", &praia.IDLocalidade);
            getchar();

            fseek(fp, -sizeof(Praia), SEEK_CUR);
            fwrite(&praia, sizeof(Praia), 1, fp);
            fclose(fp);
            return;
        }
    }

    printf("Praia não encontrada, por favor tente novamente.\n");
    fclose(fp);
}

// Exportar Praias para CSV - Nome Localidade;Nome Praia;Tipo Praia
void exportarPraiasParaCSV()
{
    Praia praia;
    FILE *fp = fopen("praias.txt", "rb");
    FILE *fpCSV = fopen("praia.csv", "w");
    if (fp == NULL || fpCSV == NULL)
    {
        printf("Erro ao abrir ficheiro de praias ou ficheiro CSV\n");
        exit(1);
    }

    fprintf(fpCSV, "Nome Localidade;Nome Praia;Tipo Praia\n");
    while (fread(&praia, sizeof(Praia), 1, fp) == 1)
    {
        Localidade localidade;
        FILE *fpLocalidade = fopen("localidades.txt", "rb");
        if (fpLocalidade == NULL)
        {
            printf("Erro ao abrir ficheiro de localidades\n");
            exit(1);
        }

        while (fread(&localidade, sizeof(Localidade), 1, fpLocalidade) == 1)
        {
            if (localidade.IDLocalidade == praia.IDPraia)
            {
                fprintf(fpCSV, "%s;%s;%s\n", localidade.nomeLocalidade, praia.nomePraia, praia.tipo);
                break;
            }
        }

        fclose(fpLocalidade);
    }

    fclose(fp);
    fclose(fpCSV);
}

/* Localidades */
// Criar ficheiro de localidades
void criarFicheiroLocalidades()
{
    FILE *fp = fopen("localidades.txt", "wb");
    if (fp == NULL)
    {
        printf("Erro ao criar ficheiro de localidades\n");
        exit(1);
    }
    fclose(fp);
}
// Registar Localidade
void registarLocalidade()
{
    Localidade localidade;
    FILE *fp = fopen("localidades.txt", "ab");
    if (fp == NULL)
    {
        printf("Erro ao abrir ficheiro de localidades\n");
        exit(1);
    }

    printf("Digite o nome da localidade: ");
    fgets(localidade.nomeLocalidade, sizeof(localidade.nomeLocalidade), stdin);
    localidade.nomeLocalidade[strlen(localidade.nomeLocalidade) - 1] = '\0';

    // gerar ID automático
    localidade.IDLocalidade = 1;
    if (fseek(fp, 0, SEEK_END) == 0)
    {
        fseek(fp, -sizeof(Localidade), SEEK_END);
        fread(&localidade.IDLocalidade, sizeof(int), 1, fp);
        localidade.IDLocalidade++;
    }

    fwrite(&localidade, sizeof(Localidade), 1, fp);
    fclose(fp);
}
// Listar Localidades
void listarLocalidades()
{
    Localidade localidade;
    FILE *fp = fopen("localidades.txt", "rb");
    if (fp == NULL)
    {
        printf("Erro ao abrir ficheiro de localidades\n");
        exit(1);
    }

    printf("Listagem de localidades:\n");
    while (fread(&localidade, sizeof(Localidade), 1, fp) == 1)
    {
        printf("ID: %d\n", localidade.IDLocalidade);
        printf("Nome: %s\n\n", localidade.nomeLocalidade);
    }

    fclose(fp);
}
// Alterar Localidades utilizando o IDLocalidade para procurar
void alterarLocalidade()
{
    int idLocalidade;
    Localidade localidade;
    FILE *fp = fopen("localidades.txt", "rb+");
    if (fp == NULL)
    {
        printf("Erro ao abrir ficheiro de localidades\n");
        exit(1);
    }

    printf("Digite o ID da localidade a alterar: ");
    scanf("%d", &idLocalidade);
    getchar();

    while (fread(&localidade, sizeof(Localidade), 1, fp) == 1)
    {
        if (localidade.IDLocalidade == idLocalidade)
        {
            printf("Digite o novo nome da localidade: ");
            fgets(localidade.nomeLocalidade, sizeof(localidade.nomeLocalidade), stdin);
            localidade.nomeLocalidade[strlen(localidade.nomeLocalidade) - 1] = '\0';

            fseek(fp, -sizeof(Localidade), SEEK_CUR);
            fwrite(&localidade, sizeof(Localidade), 1, fp);
            fclose(fp);
            return;
        }
    }

    printf("Localidade não encontrada\n");
    fclose(fp);
}
/* Menu */
int main(int argc, char const *argv[])
{
    criarFicheiroPraias();
    criarFicheiroLocalidades();

    int opcao;
    do
    {
        printf("1. Registar Praia\n");
        printf("2. Registar Localidade\n");
        printf("3. Listar Praias\n");
        printf("4. Listar Localidades\n");
        printf("5. Procurar Praia\n");
        printf("6. Procurar Praia por Localidade\n");
        printf("7. Alterar Praia\n");
        printf("8. Alterar Localidade\n");
        printf("9. Exportar Praias para CSV\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            registarPraia();
            break;
        case 2:
            registarLocalidade();
            break;
        case 3:
            listarPraias();
            break;
        case 4:
            listarLocalidades();
            break;
        case 5:
            procurarPraia();
            break;
        case 6:
            listarPraiasPorLocalidade();
            break;
        case 7:
            alterarPraia();
            break;
        case 8:
            alterarLocalidade();
            break;
        case 9:
            exportarPraiasParaCSV();
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);
    return 0;
}