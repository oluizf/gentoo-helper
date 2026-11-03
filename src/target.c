#include <stdio.h>
#include <stdlib.h>
#include "../include/helper.h"

void menu_montar() {

    int opcao_alvo;
    char particao[32];
    char comando[128];

    while(1) {
        printf("Montagem do Alvo de Instalacao (/mnt/gentoo)\n\n");
        printf("Estado atual das montagens:\n\n");

        system("lsblk -o NAME,SIZE,FSTYPE,MOUNTPOINTS | grep -E 'NAME|/mnt/gentoo'");

        printf("Etapas de montagem:\n\n");
        printf("  [1] Montar particao ROOT (/) em /mnt/gentoo\n");
        printf("  [2] Montar particao EFI em /mnt/gentoo/efi (UEFI)\n");
        printf("  [3] Montar particao BOOT em /mnt/gentoo/boot (BIOS)\n");
        printf("  [4] Ativar particao SWAP (swapon)\n");
        printf("  [5] Desmontar tudo em /mnt/gentoo\n");
        printf("  [0] VOLTAR ao menu principal\n\n");

        opcao_alvo = ler_opcao();

        if(opcao_alvo == 0) {
            break;
        }

    switch(opcao_alvo) {
    case 1:
            printf("\nInforme a particao ROOT (ex: /dev/sda3 ou /dev/nvme0n1p3): ");
            if (scanf("%31s", particao) != 1) {
                while (getchar() != '\n');
                break;
            }
            while (getchar() != '\n');

            snprintf(comando, sizeof(comando), "mkdir -p /mnt/gentoo && mount %s /mnt/gentoo", particao);
            system(comando);
            printf("\nParticao ROOT montada em /mnt/gentoo.\n");
            pausa();
            break;

        case 2:
            printf("\nInforme a particao EFI (ex: /dev/sda1 ou /dev/nvme0n1p1): ");
            if (scanf("%31s", particao) != 1) {
                while (getchar() != '\n');
                break;
            }
            while (getchar() != '\n');

            snprintf(comando, sizeof(comando), "mkdir -p /mnt/gentoo/efi && mount %s /mnt/gentoo/efi", particao);
            system(comando);
            printf("\nParticao EFI montada em /mnt/gentoo/efi.\n");
            pausa();
            break;

        case 3:
            printf("\nInforme a particao BOOT (ex: /dev/sda1): ");
            if (scanf("%31s", particao) != 1) {
                while (getchar() != '\n');
                break;
            }
            while (getchar() != '\n');

            snprintf(comando, sizeof(comando), "mkdir -p /mnt/gentoo/boot && mount %s /mnt/gentoo/boot", particao);
            system(comando);
            printf("\nParticao BOOT montada em /mnt/gentoo/boot.\n");
            pausa();
            break;

        case 4:
            printf("\nInforme a particao SWAP (ex: /dev/sda2): ");
            if (scanf("%31s", particao) != 1) {
                while (getchar() != '\n');
                break;
            }
            while (getchar() != '\n');

            snprintf(comando, sizeof(comando), "swapon %s", particao);
            system(comando);
            printf("\nSwap ativada.\n");
            pausa();
            break;

        case 5:
            system("umount -R /mnt/gentoo 2>/dev/null && swapoff -a 2>/dev/null");
            printf("\nSistemas de ficheiros em /mnt/gentoo desmontados.\n");
            pausa();
            break;

        default:
            printf("\nOpcao invalida.\n");
            pausa();
            break;
        }
    }
}

