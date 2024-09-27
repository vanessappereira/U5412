/* Localidades Base */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "localidades.h"
#include <errno.h>

/* Localidades */

// Criar ficheiro de localidades
void criarFicheiroLocalidades()
{
    const char *filename = "localidades.txt";
    FILE *fpLocalidades = fopen(filename, "wb");
    if (fpLocalidades == NULL)
    {
        fprintf(stderr, "Erro ao criar ficheiro de localidades: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    if (fclose(fpLocalidades) == EOF)
    {
        fprintf(stderr, "Erro ao fechar ficheiro de localidades: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

int obterProximoIdLocalidade()
{
    const char *filename = "localidades.txt";
    Localidade localidade;
    int maxId = 0;

    FILE *fpLocalidades = fopen(filename, "rb");

    if (fpLocalidades == NULL)
    {
        // Se o ficheiro não existir, retorne 1 como o primeiro ID
        return 1;
    }

    // Ler todas as localidades do ficheiro e encontrar o ID máximo
    while (fread(&localidade, sizeof(Localidade), 1, fpLocalidades))
    {
        if (localidade.IDLocalidade > maxId)
        {
            maxId = localidade.IDLocalidade;
        }
    }

    fclose(fpLocalidades);
    return maxId + 1; // Retorna o próximo ID
}
int localidadeExists(int idLocalidade)
{
    const char *filename = "localidades.bin";
    Localidade localidade;
    FILE *fpLocalidades = fopen(filename, "rb");

    if (fpLocalidades == NULL)
    {
        fprintf(stderr, "Erro ao abrir ficheiro de localidades: %s\n", strerror(errno));
        return 0;
    }

    while (fread(&localidade, sizeof(Localidade), 1, fpLocalidades))
    {
        if (localidade.IDLocalidade == idLocalidade)
        {
            fclose(fpLocalidades);
            return 1;
        }
    }

    fclose(fpLocalidades);
    return 0;
}
void registarLocalidade(Localidade novaLocalidade)
{
    const char *filename = "localidades.txt";
    FILE *fpLocalidades = fopen(filename, "ab");

    // Confirmar se o ficheiro abre corretamente
    if (fpLocalidades == NULL)
    {
        fprintf(stderr, "Erro ao abrir ficheiro de localidades: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Próximo ID disponível no ficheiro localidade
    novaLocalidade.IDLocalidade = obterProximoIdLocalidade();

    // Solicitar nome da localidade
    printf("Introduza o nome da Localidade: ");

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ; // clear input buffer

    if (fgets(novaLocalidade.nomeLocalidade, sizeof(novaLocalidade.nomeLocalidade), stdin) == NULL)
    {
        fprintf(stderr, "Erro ao ler input do utilizador.\n");
        fclose(fpLocalidades);
        return;
    }

    // Remover o trailing
    novaLocalidade.nomeLocalidade[strcspn(novaLocalidade.nomeLocalidade, "\n")] = 0;

    // Validar input
    if (strlen(novaLocalidade.nomeLocalidade) == 0)
    {
        printf("O nome da Localidade não pode ser vazio.\n");
        fclose(fpLocalidades);
        return;
    }

    // Escrever no ficheiro
    if (fwrite(&novaLocalidade, sizeof(Localidade), 1, fpLocalidades) != 1)
    {
        fprintf(stderr, "Erro ao escrever para o ficheiro de localidades.\n");
        fclose(fpLocalidades);
        return;
    }

    // Display messagem de sucesso
    printf("Localidade registada com sucesso!\n");

    fclose(fpLocalidades);
}

void listarLocalidades()
{
    Localidade novaLocalidade;
    const char *filename = "localidades.txt";

    FILE *fpLocalidades = fopen(filename, "rb");

    // Confirmar se o ficheiro abre corretamente
    if (fpLocalidades == NULL)
    {
        fprintf(stderr, "Erro ao abrir ficheiro de localidades: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Lista de Localidades: \n");
    while (fread(&novaLocalidade, sizeof(Localidade), 1, fpLocalidades))
    {
        printf("ID: %d | Nome de Localidade: %s\n",
               novaLocalidade.IDLocalidade,
               novaLocalidade.nomeLocalidade);
        break;
    }
    fclose(fpLocalidades);
}

void alterarLocalidadeId()
{
    Localidade novaLocalidade;
    const char *filename = "localidades.txt";
    int id_Localidade;
    char nome_Localidade[LOCALIDADE_NOME_SIZE];
    int found = 0;
    long int offset = 0;

    FILE *fpLocalidades = fopen(filename, "rb+");

    // Confirmar se o ficheiro abre corretamente
    if (fpLocalidades == NULL)
    {
        fprintf(stderr, "Erro ao abrir ficheiro de localidades: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    listarLocalidades();

    // Solicitar o id da localidade para alteração
    printf("Digite o ID da praia a alterar: ");
    while (scanf("%d", &id_Localidade) != 1)
    {
        printf("Input inválido. Tente novamente.\n");
        while (getchar() != '\n')
            ; // Limpa buffer
    }

    // Ler uma localidade de cada vez
    while (fread(&novaLocalidade, sizeof(Localidade), 1, fpLocalidades) == 1)
    {
        if (novaLocalidade.IDLocalidade == id_Localidade)
        {
            printf("Localidade encontrada.\n");
            found = 1;
            break;
        }
        offset += sizeof(Localidade);
    }

    if (!found)
    {
        printf("Localidade não encontrada.\n");
        fclose(fpLocalidades);
        return;
    }

    // Solicitar o dado para alteração
    printf("Digite o novo nome da localidade: ");
    while (scanf("%99s", nome_Localidade) != 1)
    {
        printf("Input inválido. Tente novamente.\n");
        while (getchar() != '\n')
            ; // Limpa buffer
    }

    // Alterar os dados
    strcpy(novaLocalidade.nomeLocalidade, nome_Localidade);

    // Gravar os dados da praia, confirmar se há algum erro de atualizar os dados ou de gravar no ficheiro
    if (fseek(fpLocalidades, offset, SEEK_SET) != 0)
    {
        printf("Erro a atualizar a praia no ficheiro.\nOs dados estão no estado original\n");
        fclose(fpLocalidades);
        return;
    }

    if (fwrite(&novaLocalidade, sizeof(Localidade), 1, fpLocalidades) != 1)
    {
        printf("Erro a gravar no ficheiro.\n");
        fclose(fpLocalidades);
        return;
    }

    // Display mensagem de sucesso
    printf("Localidade alterada com sucesso.\n");
}