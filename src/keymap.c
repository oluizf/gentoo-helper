#include <stdio.h>
#include <stdlib.h>

void
menu_keymap() {
    printf("Configuracao de Teclado\n\n");
    printf("Selecione o mapa de teclado adequado para o console.\n\n");

    printf("  [1] br-abnt2    Padrao Brasileiro ABNT2 (com cedilha)\n");
    printf("  [2] us          Padrao Americano sem deadkeys\n");
    printf("  [3] us-acentos  Padrao Internacional com acentos (deadkeys)\n");
    printf("  [4] es          Espanhol / Latino-Americano\n");

    printf("  [0] VOLTAR      Retornar ao menu principal\n\n");

    printf(" Sua escolha: ");

    int opcao_keymap;
    scanf("%d", &opcao_keymap);

    switch(opcao_keymap) {

        case 0:
            break;

        case 1:
            system("loadkeys br-abnt2");
            break;

        case 2:
            system("loadkeys us");
            break;

        case 3:
            system("loadkeys us-intl");
            break;

        case 4:
            system("loadkeys es");
            break;

        default:
            printf(" Invalido!\n");
            printf(" Sua escolha: ");
            scanf("%d", &opcao_keymap);
             }
}   
