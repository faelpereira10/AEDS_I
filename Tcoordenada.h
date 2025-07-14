#ifndef TCOORDENADA_H
#define TCOORDENADA_H

#include "Tmatriz.h"

// Representa uma posição na matriz
typedef struct
{
    int linha;
    int coluna;
} Tcoordenada;


//Cria uma coordenada com linha e coluna fornecidas.

Tcoordenada criar_coordenada(int linha, int coluna);


//Verifica se a coordenada está dentro dos limites da matriz.

int verificar_coordenada(Tcoordenada coordenada, Tmatriz *matriz);

#endif
