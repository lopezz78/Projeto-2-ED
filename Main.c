#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


void limpaBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(){

    setlocale(LC_ALL, "");



    int opcao;

    char resposta;
do{
    printf("\n");
    printf("========================================================\n");
    printf("    GERENCIADOR DE FALHAS EM EQUIPAMENTOS COMPUTACIONAIS\n");
    printf("========================================================\n");
    printf("|   1 - Cadastrar Equipamento                           |\n");
    printf("|   2 - Registrar Incidente                             |\n");
    printf("|   3 - Consultar Equipamento e Incidente               |\n");
    printf("|   4 - Listar todos os Incidentes                      |\n");
    printf("|   5 - Excluir um Incidente                            |\n");
    printf("|   6 - Excluir um Equipamento                          |\n");
    printf("|   0 - Encerrar Programa                               |\n");
    printf("========================================================\n");

    printf("\nEscolha uma opção: ");


    opcao = -9999; // valor que caia novamente no default apos primeiro uso de uma funcao


    scanf("%d", &opcao);
    limpaBuffer();



    switch(opcao){

        case 1:
        break;

        case 2:
        break;

        case 3:
        break;

        case 4:
        break;

        case 5:
        break;

        case 6:
        break;

        case 0:

        do {

            printf("\nDeseja Realmente sair do programa? (S || N) \n");
            printf("==> ");
            scanf("%c", &resposta);
            limpaBuffer();

            if ((resposta != 'S') && (resposta != 's') &&
                (resposta != 'N') && (resposta != 'n'))
            {
                printf("\n\n=> DIGITE SOMENTE S PARA SIM OU N PARA NÃO <=\n");


            }

            } while ((resposta != 'S') && (resposta != 's') && (resposta != 'N') && (resposta != 'n'));

            if ((resposta == 'S') || (resposta == 's'))
            {
                printf("\nFinalizando o programa...\n");

                printf("Programa finalizado.\n");
                exit(0);
            }

        break;

        default:
            printf("\nOpção inválida!\n");
            system("pause");


    }
    system("cls");
}while(1);

}
