#ifndef TPALAVRA_H
#define TPALAVRA_H

#include "Tcoordenada.h"

// Estrutura que representa uma palavra do caça-palavras
typedef struct {
    char *palavra;
    int achada;
    Tcoordenada inicio;
    Tcoordenada fim;
} Tpalavra;

// Cria uma nova palavra a partir de uma string
Tpalavra criar_palavra(char* palavra);

// Define a posição de uma palavra encontrada
void posicao_palavra(Tpalavra* palavra, Tcoordenada inicio, Tcoordenada fim);

// Marca a palavra como não encontrada e zera as posições
void palavra_n_encontrada(Tpalavra* palavra);

// Libera a memória da string da palavra
int apagar_palavra(Tpalavra* palavra);

// Adiciona uma nova palavra no vetor de palavras 
int palavras_add(Tpalavra* vetor, Tpalavra nova);

// Preenche um vetor de palavras pedindo entrada do usuário
int palavras_preencher(Tpalavra* vetor, int num_palavras);

// Imprime a solução final com todas as palavras e suas posições 
void imprimir_solucao(Tpalavra* vetor, int num_palavras);

#endif
