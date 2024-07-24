#include <stdio.h>
// 3. Escreva um programa que solicite dois números e faça a troca dos números entre variáveis.
void trocaNumb()
{
    int num1, num2, numTroca;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    numTroca = num1;
    num1 = num2;
    num2 = numTroca;

    printf("Troca de numeros o primeiro agora é: %d e o segundo é: %d", num1, num2);
}
int main()
{
    trocaNumb();
}