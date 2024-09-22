#include <stdio.h>

int sum(x, y)
{
    return x + y;
};
int sub(x, y)
{
    return x - y;
};
float multi(x, y)
{
    return x * y;
};
float div(x, y)
{
    return x / y;
};

void aritmetica()
{
    int num1, num2;

    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &num1, &num2);

    printf("A soma dos numeros digitados foi: %.2f\n", sum(num1, num2));
    printf("A subtracao dos numeros digitados foi: %.2f\n", sub(num1, num2));
    printf("A multiplicacao dos numeros digitados foi: %.2f\n", multi(num1, num2));
    printf("A divisao dos numeros digitados foi: %.2f\n", div(num1, num2));
    return 0;
}

int main()
{
    aritmetica();
}