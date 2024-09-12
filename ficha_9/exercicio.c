/*
    Faça uma função que devolva o número de vezes que uma string é encontrada num ficheiro de texto.
    size_t nstrfile(char *filename, char *str)
*/
#include <stdio.h>
#include <stdlib.h>
// Adicionado para o strlen
#include <string.h>
/* Adicionado os parametros 'filename' e 'str' para indicar que não são modificados dentro da função */
size_t nstrfile(const char *filename, const char *str)
{
    // Inicialização de variaveis
    int c;
    size_t count = 0;
    char buffer[256]; // or use malloc and free

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        // Alterado 'perror' para 'fprintf' para incluir o nome do ficheiro na mensagem de erro.
        fprintf("Erro ao abrir o ficheiro: %s\n", filename);
        exit(1);
    }
    char *buffer = malloc(strlen(str) + 1);
    if (buffer == NULL)
    {
        // handle memory allocation error
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    // Iterar por cada caratere encontrado no ficheiro
    while ((c = fgetc(file)) != EOF)
    {
        // Verificar se o caractere corresponde ao primeiro caractere da string
        if (c == str[0])
        {
            // Se corresponder, verifica se o resto da string corresponde
            fseek(file, -1, SEEK_CUR); // retrocede um caractere
            if (fgets(buffer, strlen(str) + 1, file) != NULL)
            {
                // Se corresponder, aumenta a contagem
                if (strncmp(buffer, str, strlen(str)) == 0)
                {
                    count++;
                }
            }
            // volta para a posição anterior
            rewind(file);
            free(buffer);
        }
    }

    // Fechar a leitura do ficheiro
    fclose(file);

    // Retorna o valor da contagem
    return count;
}

int main(int argc, char const *argv[])
{
    /* Adicionado a constante char *str para fixar o caminho do ficheiro */
    const char *filename = "myfile.txt";
    // String para procura de texto
    const char *str = "l";

    size_t count = nstrfile(filename, str);
    /* Utilizado o %zu para imprimir o valor correctamente */
    printf("A letra '%s' aparece %zu vezes no ficheiro '%s'.\n", str, count, filename);

    return 0;
}
