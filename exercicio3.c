#include <stdio.h>
// Escreva um programa que solicite um determinado número de segundos, e em seguida indique quantas horas, minutos e segundos esse valor representa.
void returnHours()
{
    int seconds, hours, minutes, rest;
    int segundos, horas, minutos;

    printf("Digite o numero de segundos: ");
    scanf("%d", &segundos);

    horas = segundos / 3600;
    minutos = (segundos % 3600) / 60;

    printf("%d segundos equivalem a %d horas e %d minutos ", segundos, horas,
           minutos);
}
int main()
{
    returnHours();
}