/* Localidades Header */
#ifndef LOCALIDADES_H
#define LOCALIDADES_H
#define LOCALIDADE_NOME_SIZE 100

// Struct definitions
typedef struct
{
    int IDLocalidade;
    char nomeLocalidade[LOCALIDADE_NOME_SIZE];
} Localidade;

void criarFicheiroLocalidades();

// 2. (2 Val.) Inserir Localidade
void registarLocalidade();

// 4. (2 Val.) Listar Localidades
void listarLocalidades();

// 7. (2 Val.) Alterar Localidade (Alterar utilizando o IDLocalidade para procurar)
void alterarLocalidadeId();

int localidadeExists(int idLocalidade);

#endif // LOCALIDADES_H