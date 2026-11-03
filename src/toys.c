#include <stdio.h>
#include <stdlib.h>
#include "../include/helper.h"

void menu_ferramentas() {

    int opcao_ferramentas;
    char dns[64];
    char comando[128];

    printf("Utilitarios Rapidos de Configuracao\n\n");

    printf("  [1] NMTUI       Interface em modo texto do NetworkManager\n");
    printf("  [2] PING        Testar conexao com a internet (ping 1.1.1.1)\n");
    printf("  [3] RESOLV.CONF Configurar DNS rapido (/etc/resolv.conf)\n");
    printf("  [4] COPIAR DNS  Copiar resolv.conf para /mnt/gentoo/etc/\n");
    printf("  [5] IP / LINKS  Verificar interfaces ativas (ip a)\n");
    printf("  [0] VOLTAR      Retornar ao menu principal\n\n");
    
    opcao_ferramentas = ler_opcao();

    switch(opcao_ferramentas) {
        case 1:
            limpar_tela();
            system("nmtui");
            break;
        
        case 2:
            limpar_tela();
            system("ping -c 3 1.1.1.1");
            break;

        case 3: 
            limpar_tela();
            printf("Configuracao rapida de DNS:\n\n");
            printf("  [1] Cloudflare (1.1.1.1 / 1.0.0.1)\n");
            printf("  [2] Google     (8.8.8.8 / 8.8.4.4)\n");
            printf("  [3] Manual     (Digitar IP customizado)\n");
            printf("  [0] Cancelar\n\n");

            int op_dns = ler_opcao();

            if (op_dns == 1) {
                system("printf 'nameserver 1.1.1.1\\nnameserver 1.0.0.1\\n' > /etc/resolv.conf");
                printf("\nDNS Cloudflare aplicado em /etc/resolv.conf.\n");
                pausa();
            } else if (op_dns == 2) {
                system("printf 'nameserver 8.8.8.8\\nnameserver 8.8.4.4\\n' > /etc/resolv.conf");
                printf("\nDNS Google aplicado em /etc/resolv.conf.\n");
                pausa();
            } else if (op_dns == 3) {
                printf("\nDigite o IP do servidor DNS: ");
                if (scanf("%63s", dns) == 1) {
                    while (getchar() != '\n');
                    snprintf(comando, sizeof(comando), "echo 'nameserver %s' > /etc/resolv.conf", dns);
                    system(comando);
                    printf("\nDNS customizado gravado.\n");
                } else {
                    while (getchar() != '\n');
                }
                pausa();
            }
            break;

        case 4:
            limpar_tela();
            system("mkdir -p /mnt/gentoo/etc && cp -L /etc/resolv.conf /mnt/gentoo/etc/");
            printf("/etc/resolv.conf copiado com sucesso para /mnt/gentoo/etc/.\n");
            pausa();
            break;

        case 5:
            limpar_tela();
            system("ip -br a");
            pausa();
            break;

        default:
            printf("\nOpcao invalida.\n");
            pausa();
            break;
        }
    }


