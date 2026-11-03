/* GENTOO-HELPER: utils.c 
 * version 1.0
 * - Luiz Gustavo (zLuuzis)
 *   1/11/2026
 */

#include <stdio.h>

void 
limpar_tela() {
    printf("\033[2J\033[H");
}

int 
ler_opcao(void) {
  
    int opcao;
    printf(" Sua escolha: ");
    scanf("%d", &opcao);

    while(opcao < 0 || opcao > 10) {
        printf(" Selecao invalida. Por favor tente novamente\n");
        printf(" Sua escolha: ");
        scanf("%d", &opcao);
    }

    return opcao;
}

void
pausa(void)
{
    printf("\nPressione ENTER para continuar...");
    while (getchar() != '\n');
}
