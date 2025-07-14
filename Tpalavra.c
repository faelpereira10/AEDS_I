#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tpalavra.h"

// Cria uma nova palavra e aloca memória para a string
Tpalavra criar_palavra(char *palavra)
{
    Tpalavra p;
    p.palavra = malloc(strlen(palavra) + 1);
    if (!p.palavra)
    {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(1);
    }
    strcpy(p.palavra, palavra);
    palavra_n_encontrada(&p); // inicializa como não achada
    return p;
}

// Define as coordenadas da palavra encontrada e marca como achada
void posicao_palavra(Tpalavra *palavra, Tcoordenada inicio, Tcoordenada fim)
{
    palavra->inicio = inicio;
    palavra->fim = fim;
    palavra->achada = 1;
}

// Define estado inicial: palavra não foi encontrada
void palavra_n_encontrada(Tpalavra *palavra)
{
    Tcoordenada coord = {0, 0};
    palavra->inicio = coord;
    palavra->fim = coord;
    palavra->achada = 0;
}

// Libera a memória da string alocada na palavra
int apagar_palavra(Tpalavra *palavra)
{
    if (!palavra) return -1;

    if (palavra->palavra)
    {
        free(palavra->palavra);
        palavra->palavra = NULL;
    }

    return 0;
}

// Verifica se uma nova palavra pode ser adicionada (usado como placeholder)
int palavras_add(Tpalavra *vetor, Tpalavra nova)
{
    if (!vetor || !nova.palavra) return -1;
    return 1;
}

// Preenche um vetor de palavras a partir da entrada do usuário
int palavras_preencher(Tpalavra *vetor, int num_palavras)
{
    if (!vetor || num_palavras <= 0) return 0;

    char buffer[100];
    printf("\n");
    for (int i = 0; i < num_palavras; i++)
    {
        printf("Digite a palavra %d: ", i + 1);
        scanf("%s", buffer);
        vetor[i] = criar_palavra(buffer);
    }
    printf("\n");

    return 1;
}

// Imprime todas as palavras e sua situação (encontrada ou não)
void imprimir_solucao(Tpalavra *vetor, int num_palavras)
{
    printf("\nSolução do caça-palavras:\n");
    for (int i = 0; i < num_palavras; i++)
    {
        printf("Palavra: %s\n", vetor[i].palavra);
        if (vetor[i].achada)
        {
            printf("  Encontrada de [%d,%d] até [%d,%d]\n",
                   vetor[i].inicio.linha, vetor[i].inicio.coluna,
                   vetor[i].fim.linha, vetor[i].fim.coluna);
        }
        else
        {
            printf("  Não encontrada\n");
        }
    }
}
