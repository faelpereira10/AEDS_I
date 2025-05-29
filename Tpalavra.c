#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tpalavra.h"
#include "Tcoordenada.h"

Tpalavra criar_palavra(char* palavra) {
    Tpalavra p;
    p.palavra = malloc(strlen(palavra) + 1);
    if (p.palavra == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(1);
    }
    strcpy(p.palavra, palavra);
    p.achada = 0;
    palavra_n_encontrada(&p);
    return p;
}

void posicao_palavra(Tpalavra* palavra, Tcoordenada inicio, Tcoordenada fim) {
    palavra->inicio = inicio;
    palavra->fim = fim;
    palavra->achada = 1;
}

void palavra_n_encontrada(Tpalavra* palavra) {
    Tcoordenada coord = {0, 0};
    palavra->inicio = coord;
    palavra->fim = coord;
    palavra->achada = 0;
}

int apagar_palavra(Tpalavra* palavra) {
    if (palavra == NULL) {
        return -1;
    }
    if (palavra->palavra != NULL) {
        free(palavra->palavra);
        palavra->palavra = NULL;
    }
    return 0;
}


int palavras_add(Tpalavra* vetor, Tpalavra nova) {
    if (vetor == NULL || nova.palavra == NULL) {
        return -1;
    }
    return 1;
}

int palavras_preencher(Tpalavra* vetor, int num_palavras) {
    if (vetor == NULL || num_palavras <= 0) return 0;

    char buffer[100];
    for (int i = 0; i < num_palavras; i++) {
        printf("Digite a palavra %d: ", i + 1);
        scanf("%s", buffer);
        vetor[i] = criar_palavra(buffer);
    }
    return 1;
}

void imprimir_solucao(Tpalavra* vetor, int num_palavras) {
    printf("\n--- Solução do caça-palavras ---\n");
    for (int i = 0; i < num_palavras; i++) {
        printf("Palavra: %s\n", vetor[i].palavra);
        if (vetor[i].achada) {
            printf("  Encontrada de [%d,%d] até [%d,%d]\n",
                   vetor[i].inicio.linha, vetor[i].inicio.coluna,
                   vetor[i].fim.linha, vetor[i].fim.coluna);
        } else {
            printf("  Não encontrada\n");
        }
    }
}