#include <stdio.h>
#include <stdlib.h>
#include "Tmatriz.h"

/*declarando funão de criar matrizes*/
Tmatriz *criar_matriz(int linhas, int colunas)
{

    Tmatriz *m = (Tmatriz *)malloc(sizeof(Tmatriz));

    m->linhas = linhas;
    m->colunas = colunas;

    m->letras = (char **)malloc(linhas * sizeof(char *));

    for (int i = 0; i < linhas; i++)
    {
        m->letras[i] = (char *)malloc(colunas * sizeof(char *));
    }

    return m;
}

/*declarando função de preencher matrizes*/
int preencher_matriz(Tmatriz *matriz)
{

    for (int i = 0; i < matriz->linhas; i++)
    {
        for (int j = 0; j < matriz->colunas; j++)
        {
            printf("Digite a posicao [%d][%d] do seu caca palavras: ", i + 1, j + 1);
            scanf(" %c", &matriz->letras[i][j]);
        }
    }

    return 0;
}

/*Declarando Função para imprimir matrizes*/
void imprimir_matriz(Tmatriz *matriz)
{
    printf("\nSeu caça palavras é: \n");

    for (int i = 0; i < matriz->linhas; i++);
    {
        for (int j = 0; j < matriz->colunas; j++)
        {
            printf("%c ", matriz->letras[i][j]);
        }
        printf("\n");
    }
}

int apagar_matriz(Tmatriz *matriz)
{

    for (int i = 0; i < matriz->linhas; i++)
    {

        free(matriz->letras[i]);
    }

    free(matriz->letras);
    free(matriz);

    return 0;
}