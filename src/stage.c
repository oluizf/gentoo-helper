#include <stdio.h>
#include <stdlib.h>
#include "../include/helper.h"

#define URL_OPENRC  "https://distfiles.gentoo.org/releases/amd64/autobuilds/20261101T164556Z/stage3-amd64-desktop-openrc-20261101T164556Z.tar.xz"
#define URL_SYSTEMD "https://distfiles.gentoo.org/releases/amd64/autobuilds/20261101T164556Z/stage3-amd64-desktop-systemd-20261101T164556Z.tar.xz"

void
menu_stage3(void)
{
    int opcao_stage3;
    char comando[1024];

    while (1) {
        printf("Instalacao do Stage 3 (Desktop Profile)\n\n");
        printf("Status do alvo (/mnt/gentoo):\n");
        system("mountpoint -q /mnt/gentoo && echo '[OK] /mnt/gentoo montado' || echo '[AVISO] /mnt/gentoo NAO montado!'");
        printf("\nEscolha o init system desejado:\n\n");
        printf("  [1] OpenRC   (Desktop / Tradicional UNIX)\n");
        printf("  [2] systemd  (Desktop / Moderno)\n");
        printf("  [3] Extrair  (Extrair tarball ja presente em /mnt/gentoo)\n");
        printf("  [0] VOLTAR ao menu principal\n\n");

        opcao_stage3 = ler_opcao();

        if (opcao_stage3 == 0) {
            break;
        }

        switch (opcao_stage3) {
        case 1:
        case 2:
            limpar_tela();
            printf("Iniciando download do Stage 3 (%s)...\n\n", (opcao_stage3 == 1) ? "OpenRC" : "systemd");

            snprintf(comando, sizeof(comando),
                     "cd /mnt/gentoo && wget -c %s",
                     (opcao_stage3 == 1) ? URL_OPENRC : URL_SYSTEMD);
            system(comando);

            printf("\nDownload finalizado. Deseja extrair agora?\n");
            printf("  [1] Sim, extrair agora\n");
            printf("  [2] Nao, extrair mais tarde\n\n");

            if (ler_opcao() == 1) {
                limpar_tela();
                printf("Extraindo Stage 3 com atributos estendidos...\n\n");
                system("cd /mnt/gentoo && tar xpvf stage3-*.tar.xz --xattrs-include='*.*' --numeric-owner");
                printf("\nExtracao concluida com sucesso!\n");
                pausa();
                return;
            }
            pausa();
            break;

        case 3:
            limpar_tela();
            printf("Extraindo qualquer tarball presente em /mnt/gentoo...\n\n");
            system("cd /mnt/gentoo && tar xpvf stage3-*.tar.xz --xattrs-include='*.*' --numeric-owner");
            printf("\nExtracao finalizada.\n");
            pausa();
            return;

        default:
            printf("\nOpcao invalida.\n");
            pausa();
            break;
        }
    }
}
