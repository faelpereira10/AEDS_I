#ifndef TCOORDENADA_H
#define TCOORDENADA_H

#include "Tmatriz.h"

typedef struct
{
    int linha;
    int coluna;

} TCoordenada;

TCoordenada criar_coordenada(int linha, int coluna);

int verificar_coordenada(TCoordenada coordenada, Tmatriz *matriz)

#endif