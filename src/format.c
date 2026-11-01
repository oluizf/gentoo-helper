#include <stdio.h>
#include <stdlib.h>
#include "../include/helper.h"

void menu_formatar() {
    
    int opcao_formatar;
    char particao[32];
    char comando[128];

    while(1) {
    limpar_tela();
    printf("Formatacao de Particoes\n\n");
    printf("Particoes disponiveis no sistema:\n");

    printf("\n");
    system("lsblk");
    printf("\n");

    printf("  [1] EFI (FAT32)     Formatacao /boot/efi (Sistemas UEFI)\n");
    printf("  [2] BOOT (EXT4)     Formatacao /boot separada (Sistemas BIOS)\n");
    printf("  [3] ROOT (EXT4)     Formatacao do sistema raiz (/)\n");
    printf("  [4] SWAP            Inicializar particao de swap\n");
    printf("  [0] VOLTAR          Retornar ao menu principal\n\n");

    opcao_formatar = ler_opcao();

        if (opcao_formatar == 0) {
            break;
        }

    switch(opcao_formatar) {
        
        case 1:
        case 2:
        case 3:
        case 4:
            printf("\nInforme a particao (ex: /dev/sda1 ou /dev/nvme0n1p1): ");
            if (scanf("%31s", particao) != 1) {
                while (getchar() != '\n');
                break;
        }
            while (getchar() != '\n'); 

            limpar_tela();

            if(opcao_formatar == 1) {
                snprintf(comando, sizeof(comando), "mkfs.vfat -F 32 %s", particao);
            } else if(opcao_formatar == 2 || opcao_formatar == 3) {
                snprintf(comando, sizeof(comando), "mkfs.ext4 %s", particao);
            } else if(opcao_formatar == 4) { 
                snprintf(comando, sizeof(comando), "mkswap %s", particao);
            }
            printf("A executar: %s\n\n", comando);
            system(comando);
            pausa();
            break;

        default:
            printf("\nInvalido!\n");
            pausa();
            break;
        
        }
    }
}
