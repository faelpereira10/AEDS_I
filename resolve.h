#ifndef RESOLVE_H
#define RESOLVE_H

#include "Tmatriz.h"
#include "Tpalavra.h"
#include "Tocorrencias.h"

typedef struct {
    Tmatriz *matriz;
    Tpalavra *palavras;
    int qtd_palavras;
} Tresolve;

// Cria o resolver a partir das dimensões da matriz e da quantidade de palavras
Tresolve* criar_resolve(int linhas, int colunas, int qtd_palavras);

// Lê a matriz e as palavras do usuário
void ler_resolve(Tresolve *resolve);

// Procura cada palavra na matriz e armazena as ocorrências
Tocorrencias* buscar_palavras_resolve(Tresolve *resolve);

// Mostra o resultado das palavras encontradas
void imprimir_resultado_resolve(Tocorrencias *ocorrencias, Tpalavra *palavras, int qtd_palavras);

// Libera memória alocada para o resolver
void apagar_resolve(Tresolve *resolve);

#endif
