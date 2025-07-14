#ifndef TOCORRENCIAS_H
#define TOCORRENCIAS_H

#include "Tcoordenada.h"

// Representa uma ocorrência de uma palavra no caça-palavras
typedef struct
{
    Tcoordenada inicio;
    Tcoordenada fim;
} Tocorrencia;

// Estrutura que agrupa todas as ocorrências encontradas
typedef struct
{
    Tocorrencia *ocorrencias; // Vetor de ocorrências
    int qtd;                  // Quantidade de palavras/ocorrências
} Tocorrencias;

// Cria estrutura para armazenar ocorrências
Tocorrencias *criar_tocorrencias(int qtd_palavras);

// Define a ocorrência de uma palavra (posição inicial e final)
void adicionar_ocorrencia(Tocorrencias *toc, int indice, Tcoordenada ini, Tcoordenada fim);

// Libera memória alocada para as ocorrências
void apagar_tocorrencias(Tocorrencias *toc);

// Mostra uma ocorrência (útil para depuração)
void imprimir_ocorrencia(Tocorrencia ocorrencia);

#endif
