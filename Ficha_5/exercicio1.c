// Crie um algoritmo em C que receba uma string e faça a conversão das minúsculas para maiúsculas e das maiúsculas para minúsculas.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void converterChar(char *str)
{
    while (*str != '\0')
    {
        if (islower(*str))
        {
            *str = toupper(*str);
        }
        else if (isupper(*str))
        {
            *str = tolower(*str);
        }
        str++;
    }
}
int main()
{
    char str[100];
    
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);
    
    converterChar(str);
    
    printf("String convertida: %s", str); 
}