/*
Crie um array para armazenar os dados referentes aos 30 aeroportos públicos de Portugal. O array deve utilizar a seguinte estrutura, e criar as seguintes funções para gestão do array
    inserir ( )
    listar ( )
    procurar ( )
    alterar ( )
*/

#define MAX 31

// Definição de constantes
#define MAX_AEROPORTOS 30
#define MAX_MUNICIPIO 50
#define MAX_ICAO 4
#define MAX_IATA 3
#define MAX_NOME 50

// Definição da estrutura Aeroporto
typedef struct
{
    char municipio[MAX_MUNICIPIO + 1];
    char ICAO[MAX_ICAO + 1];
    char IATA[MAX_IATA + 1];
    char nome[MAX_NOME + 1];
} Aeroporto;

Aeroporto aeroportos[MAX];

// Inserir Aeroportos

// Listar Aeroporto

// Procurar Aeroportos

// Alterar Aeroportos
