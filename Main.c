#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


int main(){

    int opcao;

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

}while(1);

}
