#ifndef TOCORRENCIAS_H
#define TOCORRENCIAS_H

#include "Tcoordenada.h"

// Representa uma ocorrência única
typedef struct {
    Tcoordenada inicio;
    Tcoordenada fim;
} Tocorrencia;

// Representa o conjunto de ocorrências 
typedef struct {
    Tocorrencia *ocorrencias;  // vetor de ocorrências
    int qtd;                   // quantidade total de ocorrências
} Tocorrencias;

// Funções para o vetor de ocorrências
Tocorrencias* criar_tocorrencias(int qtd_palavras);
void adicionar_ocorrencia(Tocorrencias *toc, int indice, Tcoordenada ini, Tcoordenada fim);
void apagar_tocorrencias(Tocorrencias *toc);

// Função de depuração
void imprimir_ocorrencia(Tocorrencia ocorrencia);

#endif
