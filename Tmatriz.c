#include <stdio.h>
#include <stdlib.h>
#include "Tmatriz.h"

// Aloca e inicializa a estrutura da matriz
Tmatriz *criar_matriz(int linhas, int colunas)
{
    Tmatriz *m = (Tmatriz *)malloc(sizeof(Tmatriz));
    if (m == NULL)
    {
        fprintf(stderr, "Erro ao alocar matriz.\n");
        exit(1);
    }

    m->linhas = linhas;
    m->colunas = colunas;

    // Aloca linhas
    m->letras = (char **)malloc(linhas * sizeof(char *));
    if (m->letras == NULL)
    {
        free(m);
        fprintf(stderr, "Erro ao alocar linhas da matriz.\n");
        exit(1);
    }

    // Aloca colunas para cada linha
    for (int i = 0; i < linhas; i++)
    {
        m->letras[i] = (char *)malloc(colunas * sizeof(char));
        if (m->letras[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(m->letras[j]);
            free(m->letras);
            free(m);
            fprintf(stderr, "Erro ao alocar colunas da matriz.\n");
            exit(1);
        }
    }

    return m;
}

// Lê os caracteres da matriz fornecidos pelo usuário
int preencher_matriz(Tmatriz *matriz)
{
    printf("Preencha a matriz do caca-palavras (%dx%d):\n", matriz->linhas, matriz->colunas);

    for (int i = 0; i < matriz->linhas; i++)
    {
        for (int j = 0; j < matriz->colunas; j++)
        {
            printf("Digite a letra da posicao [%d][%d]: ", i + 1, j + 1);
            scanf(" %c", &matriz->letras[i][j]);
        }
    }

    return 0;
}

// Exibe a matriz formatada
void imprimir_matriz(Tmatriz *matriz)
{
    printf("\nMatriz do caça-palavras:\n");

    for (int i = 0; i < matriz->linhas; i++)
    {
        for (int j = 0; j < matriz->colunas; j++)
        {
            printf("%c ", matriz->letras[i][j]);
        }
        printf("\n");
    }
}

// Libera toda a memória associada à matriz
int apagar_matriz(Tmatriz *matriz)
{
    if (matriz == NULL)
        return -1;

    for (int i = 0; i < matriz->linhas; i++)
    {
        free(matriz->letras[i]);
    }

    free(matriz->letras);
    free(matriz);

    return 0;
}
