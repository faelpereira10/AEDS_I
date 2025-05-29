#ifndef TMATRIZ_H
#define TMATRIZ_H

/*Declarando matriz do caça palavras*/
typedef struct Tmatriz
{
    char **letras;
    int linhas;
    int colunas;
} Tmatriz;

/*inicializando função para criar e inicializar a matriz*/
Tmatriz *criar_matriz(int linhas, int colunas);

/*inicializando função para preencher os elementos da matriz*/
int preencher_matriz(Tmatriz *matriz);

/*inicializando função para mostrar matriz na tela*/
void imprimir_matriz(Tmatriz *matriz);

/*inicializando função para limpar a matriz matriz*/
int apagar_matriz(Tmatriz *matriz);

#endif