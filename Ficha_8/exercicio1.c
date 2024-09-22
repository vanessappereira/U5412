/*
Faça um algoritmo que crie um array para inserção de temperaturas.
    1. A matriz deve ser redimensionada sempre que se insira uma nova temperatura
    2. Ter uma posição para guardar a média das temperaturas.
    2.1 A média deve ser atualizada sempre que se insira uma nova temperatura
*/
#include <stdio.h>
#include <stdlib.h>

// Estrutura para guardar as temperaturas e o tamanho
typedef struct
{
    // Iniciar o array das temperaturas com o default size
    float *temperaturas;
    float media;
    int tamanho;
} Temperaturas;

void inserirTemperatura(Temperaturas *temps, float novaTemp)
{

    // Redimensionar o array
    temps->temperaturas = realloc(temps->temperaturas, (temps->tamanho + 1) * sizeof(float));
    if (temps->temperaturas == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    // Adicionar a nova temperatura e atualizar o tamanho
    temps->temperaturas[temps->tamanho] = novaTemp;
    temps->tamanho++;

    // Atualizar a média de forma eficiente
    temps->media = ((temps->media * (temps->tamanho - 1)) + novaTemp) / temps->tamanho;
}
// função média de temperaturas
void calcularMedia(Temperaturas *temperaturas)
{
    // Verificar se o array está vazio
    if (temperaturas->tamanho == 0)
    {
        printf("Não há temperaturas para calcular a média.\n");
    }
    printf("Média das temperaturas: %.2f\n", temperaturas->media);
}

// Menu
int main()
{
    Temperaturas temps;
    float temp;
    int contador = 0;

    printf("Digite as temperaturas (digite -1 para parar):\n");

    while (1)
    {
        if (scanf("%f", &temp) != 1)
        {
            printf("Entrada inválida. Por favor, digite um número.\n");
            // Limpar o buffer de entrada
            while (getchar() != '\n');
            continue;
        }

        if (temp == -1)
        {
            break;
        }

        inserirTemperatura(&temps, temp);
        contador++;
    }

    if (contador > 0)
    {
        calcularMedia(&temps);
    }
    else
    {
        printf("Nenhuma temperatura foi inserida.\n");
    }

    // Libertar a memória alocada
    free(temps.temperaturas);
    return 0;
}