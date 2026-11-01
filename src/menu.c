#include <stdio.h>

void menu_principal(void) {
    printf("Instalador Gentoo Helper v1.0 - zLuuzis \n\n");

    printf("Bem-vindo ao Gentoo Helper Setup.\n");
    printf("Selecione uma opcao abaixo para configurar e instalar o sistema.\n\n");

    printf("  [1] TECLADO    Configurar layout do teclado no console\n");
    printf("  [2] DISCO      Particionar unidades de disco (cfdisk/fdisk)\n");
    printf("  [3] SISTEMA    Formatar particoes (root, boot, swap)\n");
    printf("  [4] ALVO       Montar sistema de arquivos em /mnt/gentoo\n");
    printf("  [5] STAGE3     Selecionar e extrair o tarball do Stage3\n");
    printf("  [6] PORTAGE    Configurar make.conf (MAKEOPTS, flags)\n");
    printf("  [7] CHROOT     Entrar no chroot (kernel, bootloader, base)\n");
    printf("  [8] SHELL      Abrir terminal de manutencao/suporte\n");
    printf("  [9] REINICIAR  Reiniciar o computador\n");
    printf("  [0] SAIR       Sair para o live environment\n\n");
}
