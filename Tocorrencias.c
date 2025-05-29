#include <stdio.h>
#include <stdlib.h>
#include "Tocorrencias.h"

Tocorrencias* criar_tocorrencias(int qtd_palavras) {
    Tocorrencias *toc = (Tocorrencias*) malloc(sizeof(Tocorrencias));
    toc->qtd = qtd_palavras;
    toc->ocorrencias = (Tocorrencia*) malloc(qtd_palavras * sizeof(Tocorrencia));
    return toc;
}

void adicionar_ocorrencia(Tocorrencias *toc, int indice, Tcoordenada ini, Tcoordenada fim) {
    if (indice >= 0 && indice < toc->qtd) {
        toc->ocorrencias[indice].inicio = ini;
        toc->ocorrencias[indice].fim = fim;
    }
}

void apagar_tocorrencias(Tocorrencias *toc) {
    if (toc) {
        free(toc->ocorrencias);
        free(toc);
    }
}

void imprimir_ocorrencia(Tocorrencia ocorrencia) {
    printf("Início: (%d, %d), Fim: (%d, %d)\n",
           ocorrencia.inicio.linha, ocorrencia.inicio.coluna,
           ocorrencia.fim.linha, ocorrencia.fim.coluna);
}
