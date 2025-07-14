#include <stdio.h>
#include <stdlib.h>
#include "Tcoordenada.h"
#include "Tmatriz.h"


//Cria e retorna uma coordenada com linha e coluna fornecidas.
 
Tcoordenada criar_coordenada(int linha, int coluna)
{
    Tcoordenada coord;
    coord.linha = linha;
    coord.coluna = coluna;
    return coord;
}


//Verifica se a coordenada está dentro dos limites da matriz.
//Retorna 1 se for válida, 0 caso contrário.
 
int verificar_coordenada(Tcoordenada coordenada, Tmatriz *matriz)
{
    return coordenada.linha >= 0 && coordenada.linha < matriz->linhas &&
           coordenada.coluna >= 0 && coordenada.coluna < matriz->colunas;
}
