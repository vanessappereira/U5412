/*
Faça um algoritmo que crie um array para inserção de temperaturas.
A matriz deve ser redimensionada sempre que se insira uma nova temperatura e ter no final uma posição para guardar a média das temperaturas.
A média deve ser atualizada sempre que se insira uma nova temperatura
*/
#include <stdio.h>
#include <stdlib.h>

void inserirTemperatura(float **temperaturas, int *tamanho, float novaTemp)
{
    *temperaturas = (float *)realloc(*temperaturas, (*tamanho + 1) * sizeof(float));
    (*temperaturas)[*tamanho] = novaTemp;
    
    (*tamanho)++;

}