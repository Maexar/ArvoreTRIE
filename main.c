#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ArvoreTRIE.h"

int main()
{
    Noh *raiz = NULL;

   int opcao;
    char palavra[100];

    do {
        printf("\n\nMenu TRIE:\n");
        printf("1. Incluir palavra\n");
        printf("2. Buscar palavra\n");
        printf("3. Excluir palavra\n");
        printf("4. Imprimir arvore\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:  // Incluir palavra
                printf("Digite a palavra para incluir: ");
                scanf("%s", palavra);
                if (incluirInfoTRIE(&raiz, palavra)) {
                    printf("Palavra '%s' incluida com sucesso!\n", palavra);
                } else {
                    printf("Erro: a palavra '%s' ja existe ou houve um problema.\n", palavra);
                }
                break;
            
            case 2:  // Buscar palavra
                printf("Digite a palavra para buscar: ");
                scanf("%s", palavra);
                if (buscarInfoTRIE(raiz, palavra)) {
                    printf("Palavra '%s' encontrada na arvore!\n", palavra);
                } else {
                    printf("Palavra '%s' NAO encontrada na arvore.\n", palavra);
                }
                break;

            case 3:  // Excluir palavra
                printf("Digite a palavra para excluir: ");
                scanf("%s", palavra);
                if (excluirInfoTRIE(&raiz, palavra)) {
                    printf("Palavra '%s' excluida com sucesso!\n", palavra);
                } else {
                    printf("Erro: palavra '%s' nao encontrada ou houve um problema.\n", palavra);
                }
                break;

            case 4:  // Imprimir árvore
                printf("Palavras na arvore TRIE:\n");
                imprimirArvoreTRIE(raiz);
                break;

            case 5:  // Sair
                printf("Saindo...\n");
                break;

            default:
                printf("Opçao invalida! Tente novamente.\n");
        }
    } while(opcao != 5);

    return 0;
}
