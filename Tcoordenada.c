#include <stdio.h>
#include <stdlib.h>
#include "Tcoordenada.h"
#include "Tmatriz.h"

TCoordenada criar_coordenada(int linha, int coluna){
    TCoordenada cord;

    cord.linha = linha;
    cord.coluna = coluna;

    return cord;
}

int verificar_coordenada(TCoordenada coordenada, Tmatriz *matriz){

    return coordenada.coluna = > 0 && coordenada.coluna < matriz->colunas && coordenada.linha = > 0 && coordenada.linha < matriz->linhas;
}