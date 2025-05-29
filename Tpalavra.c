#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tpalavra.h"
#include "Tcoordenada.h"

Tpalavra criar_palavra(char* palavra)
{

    Tpalavra p;
    p.palavra = malloc(strlen(palavra) + 1);
    // Verificação se a alocação foi bem-sucedida
    if (p.palavra == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(1); // Encerra o programa se a alocação falhar
    }
    strcpy(p.palavra, palavra);
    p.achada = 0;
    palavra_n_encontrada(&p);
    return p;
}


void posicao_palavra(Tpalavra* palavra, Tcoordenada inicio, Tcoordenada fim){

    palavra->inicio=inicio;
    palavra->fim=fim;
    palavra->achada=1;

}

    
void palavra_n_encontrada(Tpalavra* palavra){
    Tcoordenada coord= {0,0};

    palavra->inicio=coord;
    palavra->fim=coord;
    palavra->achada=0;
}

int apagar_palavra(Tpalavra* palavra)
{
    if (palavra == NULL) {
        return -1; // Ou algum código de erro se o ponteiro for nulo
    }
    
    // Libera a memória alocada para a string 'palavra' dentro da struct
    if (palavra->palavra != NULL) { // Verifica se a string não é nula antes de liberar
        free(palavra->palavra);
        palavra->palavra = NULL; // Boa prática: zera o ponteiro após liberar
    }
   
    return 0; // Sucesso
}
