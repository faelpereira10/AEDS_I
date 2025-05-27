#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tpalavra.h"
#include "Tcoordenada.h"

Tpalavra criar_palavra(char *palavra)
{

    Tpalavra p;

    p.palavra = (char *)malloc(strlen(palavra) + 1);

    strcpy(p.palavra, palavra);

    p.achada = 0;

    p.inicio = palavra_n_encontrada(&p);

    return p;
}


void posicao_palavra(Tpalavra* palavra, TCoordenada inicio, TCoordenada fim){

    palavra->inicio=inicio;
    palavra->fim=fim;
    palavra->achada=1;

}

    
void palavra_n_encontrada(Tpalavra* palavra){

    TCoordenada coord= {0,0};

    palavra->inicio=coord;
    palavra->fim=coord;
    palavra->achada=0;

}