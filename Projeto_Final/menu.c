#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "praias.h"
#include "localidades.h"

int main(int argc, char const *argv[])
{
    int opcao;
    // Menu
    while (1)
    { // infinite loop
        // Menu
        printf("==== Menu Praia ====\n");
        printf("1. Registar praia\n");
        printf("2. Listar praias\n");
        printf("3. Listar praias (ID Localidade)\n");
        printf("4. Procurar praias (Nome)\n");
        printf("5. Alterar praia (ID Praia)\n");
        printf("6. Exportar ficheiro praias \n");
        printf("7. Registar localidade \n");
        printf("8. Listar localidades \n");
        printf("9. Alterar localidade (ID Localidade)\n");
        printf("0. Sair \n");
        printf("====================\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        if (opcao < 0 || opcao > 9)
        {
            printf("Opcao invalida. Tente novamente.\n");
        }
        else
        {
            switch (opcao)
            {
            case 1:
                registarPraia();
                break;
            case 2:
                listarPraias();
                break;
            case 3:
                listarPraiasIdLocalidade();
                break;
            case 4:
                procurarPraiaNome();
                break;
            case 5:
                alterarPraiaId();
                break;
            case 6:
                exportarPraias();
                break;
            case 7:
                registarLocalidade();
                break;
            case 8:
                listarLocalidades();
                break;
            case 9:
                alterarLocalidadeId();
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
            }
        }
    }
    return 0;
}
