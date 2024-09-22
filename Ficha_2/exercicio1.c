#include <stdio.h>
// 1. Calcule o preço de venda de um artigo, sabendo o preço base e a percentagem do IVA.
void priceArticle()
{
    float priceBase, priceIVA, priceTotal;

    printf("Digite o preço base do artigo: ");
    scanf("%f", &priceBase);

    printf("Digite a percentagem do IVA: ");
    scanf("%f", &priceIVA);

    priceIVA = (priceBase * priceIVA) / 100;
    priceTotal = priceBase + priceIVA;

    printf("O preço total do artigo é: %.2f", priceTotal);
}

float main()
{
    priceArticle();
}