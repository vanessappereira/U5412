#include <stdio.h>
// 2. Escreva um programa que solicite um número inteiro e escreva o seu sucessor e o antecessor.
void printNumbers()
{
    int number, previousNumber, nextNumber;

    printf("Digite um número inteiro: ");
    scanf("%d", &number);

    previousNumber = number - 1;
    nextNumber = number + 1;

    printf("O número anterior é %d e o próximo é %d", previousNumber, nextNumber);
}
int main(){
    printNumbers();
}