#ifndef TPALAVRA_H
#define TPALAVRA_H

#include "Tcoordenada.h"

typedef struct {
    char *palavra;
    int achada;
    Tcoordenada inicio;
    Tcoordenada fim;
} Tpalavra;

Tpalavra criar_palavra(char* palavra);
void posicao_palavra(Tpalavra* palavra, Tcoordenada inicio, Tcoordenada fim);
void palavra_n_encontrada(Tpalavra* palavra);
int apagar_palavra(Tpalavra* palavra);

#endif
