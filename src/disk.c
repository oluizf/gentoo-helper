#include <stdio.h>
#include <stdlib.h>
#include "../include/helper.h"

void menu_disco() {

    int opcao_disco;
    char comando[128];
    char dispositivo[32];

    while (1) {
        limpar_tela();

        printf("Particionamento de Disco\n\n");
        printf("Dispositivos de armazenamento detectados:\n");
    
        printf("\n");
        system("lsblk");
        printf("\n");

        printf("Ferramentas disponíveis:\n\n");
        printf("  [1] cfdisk   Interface orientada a menus (Recomendado)\n");
        printf("  [2] fdisk    Utilitário clássico em linha de comandos\n");
        printf("  [0] VOLTAR   Retornar ao menu principal\n\n");

        //scanf("%d", &opcao_disco);
        opcao_disco = ler_opcao();

        if (opcao_disco == 0) {
            break;
        }
    
switch (opcao_disco) {
        case 1:
        case 2:
            printf("\nInforme a unidade (ex: /dev/sda ou /dev/nvme0n1): ");
            if (scanf("%31s", dispositivo) != 1) {
                while (getchar() != '\n');
                break;
            }
            while (getchar() != '\n'); /* Drena o Enter residual */

            limpar_tela();
            snprintf(comando, sizeof(comando), "%s %s",
                     (opcao_disco == 1) ? "cfdisk" : "fdisk", dispositivo);
            system(comando);

            pausa();
            return;

        default:
            printf("\nOpcao invalida. Tente novamente.\n");
            pausa();
            break;
        } 
    } 
}
