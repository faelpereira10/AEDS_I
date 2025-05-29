#include <stdio.h>
#include <stdlib.h>
#include "Tcoordenada.h"
#include "Tmatriz.h"

Tcoordenada criar_coordenada(int linha, int coluna){
    Tcoordenada cord;

    cord.linha = linha;
    cord.coluna = coluna;

    return cord;
}

int verificar_coordenada(Tcoordenada coordenada, Tmatriz *matriz){

    return coordenada.coluna = > 0 && coordenada.coluna < matriz->colunas && coordenada.linha = > 0 && coordenada.linha < matriz->linhas;
}