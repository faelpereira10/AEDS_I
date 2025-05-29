#ifndef TCOORDENADA_H
#define TCOORDENADA_H

#include "Tmatriz.h"

typedef struct Tcoordenada
{
    int linha;
    int coluna;

} Tcoordenada;

Tcoordenada criar_coordenada(int linha, int coluna);

int verificar_coordenada(Tcoordenada coordenada, Tmatriz *matriz);

#endif