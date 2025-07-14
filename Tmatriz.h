#ifndef TMATRIZ_H
#define TMATRIZ_H

// Estrutura que representa a matriz do caça-palavras
typedef struct Tmatriz {
    char **letras;
    int linhas;
    int colunas;
} Tmatriz;

// Cria e inicializa a matriz com as dimensões fornecidas
Tmatriz *criar_matriz(int linhas, int colunas);

// Preenche a matriz com caracteres fornecidos pelo usuário
int preencher_matriz(Tmatriz *matriz);

// Imprime a matriz na tela
void imprimir_matriz(Tmatriz *matriz);

// Libera a memória alocada pela matriz
int apagar_matriz(Tmatriz *matriz);

#endif
