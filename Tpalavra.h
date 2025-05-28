#ifndef TPALAVRA_H
#define TPALAVRA_H

#include "Tcoordenada.h" // se estiver usando TCoordenada

typedef struct {
    char *palavra;
    int achada;
    TCoordenada inicio;
    TCoordenada fim;
} Tpalavra;  // <-- Aqui é onde o tipo Tpalavra é declarado

// Agora você pode usar Tpalavra nas funções abaixo
Tpalavra criar_palavra(char *palavra);
void posicao_palavra(Tpalavra* palavra, TCoordenada inicio, TCoordenada fim);
void palavra_n_encontrada(Tpalavra* palavra);

#endif