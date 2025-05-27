#ifndef TPALAVRA_H
#define TPALAVRA_H

#include "Tcoordenada.h"

typedef struct
{
    char *palavra;
    int achada;
    TCoordenada inicio;
    TCoordenada fim;
} Tpalavra;

Tpalavra criar_palavra(char *palavra);

void posicao_palavra(Tpalavra* palavra, TCoordenada inicio, TCoordenada fim);

void palavra_n_encontrada(Tpalavra* palavra);

#endif