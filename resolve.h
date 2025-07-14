#ifndef RESOLVE_H
#define RESOLVE_H

#include "Tmatriz.h"
#include "Tpalavra.h"
#include "Tocorrencias.h"

// Estrutura principal que representa o resolvedor do caça-palavras
typedef struct
{
    Tmatriz *matriz;       // Ponteiro para a matriz de letras
    Tpalavra *palavras;    // Vetor de palavras a serem buscadas
    int qtd_palavras;      // Quantidade de palavras
} Tresolve;

 //Cria o resolvedor com base nas dimensões da matriz e quantidade de palavras.
 //Aloca memória para matriz e vetor de palavras.

Tresolve *criar_resolve(int linhas, int colunas, int qtd_palavras);


 //Lê a matriz e as palavras do usuário usando os TADs específicos.
 
void ler_resolve(Tresolve *resolve);


 //Busca todas as palavras na matriz e retorna as ocorrências encontradas.
 //Usa os TADs Tcoordenada e Tocorrencias para registrar os resultados.
 
Tocorrencias *buscar_palavras_resolve(Tresolve *resolve);


//Imprime as posições de início e fim de cada palavra encontrada na matriz.

void imprimir_resultado_resolve(Tocorrencias *ocorrencias, Tpalavra *palavras, int qtd_palavras);


//Libera toda a memória alocada na estrutura Tresolve.

void apagar_resolve(Tresolve *resolve);

#endif
