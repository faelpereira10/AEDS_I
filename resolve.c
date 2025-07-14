#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "resolve.h"

// Cria a estrutura principal do resolvedor
Tresolve *criar_resolve(int linhas, int colunas, int qtd_palavras)
{
    Tresolve *resolve = (Tresolve *)malloc(sizeof(Tresolve));
    resolve->matriz = criar_matriz(linhas, colunas);              // Cria matriz
    resolve->palavras = (Tpalavra *)malloc(qtd_palavras * sizeof(Tpalavra)); // Aloca vetor de palavras
    resolve->qtd_palavras = qtd_palavras;
    return resolve;
}

// Lê matriz e palavras, usando funções dos TADs
void ler_resolve(Tresolve *resolve)
{
    preencher_matriz(resolve->matriz);                            // Lê matriz
    palavras_preencher(resolve->palavras, resolve->qtd_palavras); // Lê palavras
}

// Busca palavras na matriz usando função do TAD Tocorrencias para armazenar ocorrências
Tocorrencias *buscar_palavras_resolve(Tresolve *resolve)
{
    Tocorrencias *toc = criar_tocorrencias(resolve->qtd_palavras);

    // Percorre cada palavra
    for (int p = 0; p < resolve->qtd_palavras; p++)
    {
        Tpalavra *palavra = &resolve->palavras[p];
        int encontrada = 0;

        // Percorre a matriz para tentar encontrar a palavra
        for (int i = 0; i < resolve->matriz->linhas && !encontrada; i++)
        {
            for (int j = 0; j < resolve->matriz->colunas && !encontrada; j++)
            {
                // Todas as 8 direções possíveis
                int dirs[8][2] = {
                    {-1, -1},{-1, 0},{-1, 1},{0, -1},{0, 1},{1, -1},{1, 0},{1, 1}
                };

                for (int d = 0; d < 8 && !encontrada; d++)
                {
                    int di = dirs[d][0], dj = dirs[d][1];
                    int x = i, y = j, k;

                    // Verifica se a palavra bate nas posições seguintes
                    for (k = 0; k < (int)strlen(palavra->palavra); k++)
                    {
                        // Se sair dos limites ou letras não baterem, sai
                        if (x < 0 || y < 0 || x >= resolve->matriz->linhas || y >= resolve->matriz->colunas)
                            break;
                        if (resolve->matriz->letras[x][y] != palavra->palavra[k])
                            break;

                        x += di;
                        y += dj;
                    }

                    // Se percorreu toda a palavra, encontrou!
                    if (k == (int)strlen(palavra->palavra))
                    {
                        Tcoordenada ini = criar_coordenada(i, j);
                        Tcoordenada fim = criar_coordenada(x - di, y - dj);
                        posicao_palavra(palavra, ini, fim);          // Atualiza posição na palavra
                        adicionar_ocorrencia(toc, p, ini, fim);      // Salva ocorrência
                        encontrada = 1;
                    }
                }
            }
        }

        // Se não encontrou, marca como não encontrada e adiciona ocorrência vazia
        if (!encontrada)
        {
            Tcoordenada coord_zero = criar_coordenada(0, 0);
            palavra_n_encontrada(palavra);
            adicionar_ocorrencia(toc, p, coord_zero, coord_zero);
        }
    }

    return toc;
}

// Imprime resultados com base nas ocorrências
void imprimir_resultado_resolve(Tocorrencias *toc, Tpalavra *palavras, int qtd_palavras)
{
    for (int i = 0; i < qtd_palavras; i++)
    {
        Tcoordenada ini = toc->ocorrencias[i].inicio;
        Tcoordenada fim = toc->ocorrencias[i].fim;
        printf("%d %d %d %d %s\n", ini.linha, ini.coluna, fim.linha, fim.coluna, palavras[i].palavra);
    }
}

// Libera memória alocada
void apagar_resolve(Tresolve *resolve)
{
    for (int i = 0; i < resolve->qtd_palavras; i++)
    {
        apagar_palavra(&resolve->palavras[i]); // Libera memória de cada palavra
    }
    apagar_matriz(resolve->matriz); // Libera matriz
    free(resolve->palavras);
    free(resolve);
}
