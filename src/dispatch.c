#include <stdio.h>
#include <stdlib.h>
#include "../include/helper.h"

void tratar_opcao(int opcao) {

    switch(opcao) {

        case 0:
        printf(" Saindo...\n"); 
        exit(0); 
        break;

        case 1:
        limpar_tela();
        menu_keymap();
        break;

        case 2:
        limpar_tela();
        menu_disco();
        break;

        case 3:
        limpar_tela();
        menu_formatar();
        break;
    }
}
