/* Praias Header */

#ifndef PRAIAS_H
#define PRAIAS_H
#include <string.h>

// Constants
#define MAX_PRAIA_NOME_SIZE 100
#define MAX_PRAIA_TIPO_SIZE 10
#define MAX_PRAIA_LOCALIDADE_SIZE 100

// Enum for Praia type
typedef enum PraiaType
{
    OCEANICA = 1,
    FLUVIAL = 2
} PraiaType;

// Struct definitions
typedef struct Praia
{
    int idPraia;
    char localidadePraia;
    char nomePraia[MAX_PRAIA_NOME_SIZE];
    PraiaType tipoPraia;
} Praia;

void criarFicheiroPraias();

// 1. (2,5 Val.) Inserir Praia
void registarPraia();

// 3. (2,5 Val.) Listar Praias
void listarPraias();

// 5. (2 Val.) Listar Praias por Localidade (Deve listar as praias de uma única localidade através do IDLocalidade)
void listarPraiasIdLocalidade();

// 6. (2 Val.) Procurar Praia (Procurar através do Nome)
void procurarPraiaNome();

// 8. (2,5 Val.) Alterar Praia (Alterar utilizando o IDPraia para procurar)
void alterarPraiaId();

// 9. (2,5 Val.) Exportar Praias para ficheiro CSV (Nome Localidade;Nome Praia;Tipo Praia)
void exportarPraias();

#endif // PRAIAS_H