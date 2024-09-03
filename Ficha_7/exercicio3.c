/*
Crie um array para armazenar os dados referentes aos 30 aeroportos públicos de Portugal. O array deve utilizar a seguinte estrutura, e criar as seguintes funções para gestão do array
    inserir ( )
    listar ( )
    procurar ( )
    alterar ( )
*/

#define MAX 30
#define MAX_MUNICIPIO 51
#define MAX_ICAO 5
#define MAX_IATA 4
#define MAX_NOME 51

typedef struct
{
    char municipio[51];
    char ICAO[5];
    char IATA[4];
    char nome[51];
} aeroporto;

aeroporto aeroportos[30];

// Inserir Aeroportos
void inserir(aeroporto aeroportos[], int *contador) {

};

// Listar Aeroporto
void listar(aeroporto aeroportos[], int contador) {

};

// Procurar Aeroportos
void procurar(aeroporto aeroportos[], int contador, char ICAO[5])
{

}
// Alterar Aeroportos


