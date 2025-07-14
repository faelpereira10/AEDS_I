#ifndef TPALAVRA_H
#define TPALAVRA_H

#include "Tcoordenada.h"

// Estrutura que representa uma palavra no caça-palavras
typedef struct
{
    char *palavra;          // Texto da palavra
    int achada;             // bool indicando se foi encontrada (1) ou não (0)
    Tcoordenada inicio;     // Coordenada de início na matriz
    Tcoordenada fim;        // Coordenada de fim na matriz
} Tpalavra;

// Cria uma nova palavra a partir de uma string
Tpalavra criar_palavra(char *palavra);

// Define a posição (início e fim) de uma palavra encontrada
void posicao_palavra(Tpalavra *palavra, Tcoordenada inicio, Tcoordenada fim);

// Marca a palavra como não encontrada (e reseta coordenadas)
void palavra_n_encontrada(Tpalavra *palavra);

// Libera a memória alocada da palavra
int apagar_palavra(Tpalavra *palavra);

// Adiciona uma nova palavra ao vetor (função auxiliar simples)
int palavras_add(Tpalavra *vetor, Tpalavra nova);

// Lê as palavras do usuário e preenche o vetor
int palavras_preencher(Tpalavra *vetor, int num_palavras);

// Mostra o resultado final das palavras (encontradas ou não)
void imprimir_solucao(Tpalavra *vetor, int num_palavras);

#endif
