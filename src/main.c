/* GENTOO-HELPER: main.c 
 * version 1.0
 * - Luiz Gustavo (zLuuzis)
 *   1/11/2026
 */

#include "../include/helper.h"

int 
main() {
    
    int opcao;
    
    while(1) {
    limpar_tela();
    menu_principal();
    opcao = ler_opcao();
    tratar_opcao(opcao);
    }

    return 0;
}
