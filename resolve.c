#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "resolve.h"

Tresolve* criar_resolve(int linhas, int colunas, int qtd_palavras) {
    Tresolve *resolve = (Tresolve*) malloc(sizeof(Tresolve));
    resolve->matriz = criar_matriz(linhas, colunas);
    resolve->palavras = (Tpalavra*) malloc(qtd_palavras * sizeof(Tpalavra));
    resolve->qtd_palavras = qtd_palavras;
    return resolve;
}

void ler_resolve(Tresolve *resolve) {
    // Lê matriz
    for (int i = 0; i < resolve->matriz->linhas; i++) {
        for (int j = 0; j < resolve->matriz->colunas; j++) {
            scanf(" %c", &resolve->matriz->letras[i][j]);
        }
    }

    // Lê palavras
    char buffer[100];
    for (int i = 0; i < resolve->qtd_palavras; i++) {
        scanf("%s", buffer);
        resolve->palavras[i] = criar_palavra(buffer);
    }
}

Tocorrencias* buscar_palavras_resolve(Tresolve *resolve) {
    Tocorrencias *toc = criar_tocorrencias(resolve->qtd_palavras);

    for (int p = 0; p < resolve->qtd_palavras; p++) {
        Tpalavra *palavra = &resolve->palavras[p];
        int encontrada = 0;

        for (int i = 0; i < resolve->matriz->linhas && !encontrada; i++) {
            for (int j = 0; j < resolve->matriz->colunas && !encontrada; j++) {

                int dirs[8][2] = {
                    {-1, -1}, {-1, 0}, {-1, 1},
                    {0, -1},          {0, 1},
                    {1, -1},  {1, 0},  {1, 1}
                };

                for (int d = 0; d < 8 && !encontrada; d++) {
                    int di = dirs[d][0], dj = dirs[d][1];
                    int x = i, y = j, k;

                    for (k = 0; k < strlen(palavra->palavra); k++) {
                        if (x < 0 || y < 0 || x >= resolve->matriz->linhas || y >= resolve->matriz->colunas)
                            break;
                        if (resolve->matriz->letras[x][y] != palavra->palavra[k])
                            break;

                        x += di;
                        y += dj;
                    }

                    if (k == strlen(palavra->palavra)) {
                        Tcoordenada ini = {i, j};
                        Tcoordenada fim = {x - di, y - dj};
                        posicao_palavra(palavra, ini, fim);
                        adicionar_ocorrencia(toc, p, ini, fim);
                        encontrada = 1;
                    }else{
                        Tcoordenada ini = {0, 0};
                        Tcoordenada fim = {0,0};
                        posicao_palavra(palavra, ini, fim);
                        adicionar_ocorrencia(toc, p, ini, fim);
                        encontrada = 0;
                    }
                }
            }
        }
    }

    return toc;
}

void imprimir_resultado_resolve(Tocorrencias *toc, Tpalavra *palavras, int qtd_palavras) {
    for (int i = 0; i < qtd_palavras; i++) {
        Tcoordenada ini = toc->ocorrencias[i].inicio;
        Tcoordenada fim = toc->ocorrencias[i].fim;
        printf("%d %d %d %d %s\n", ini.linha, ini.coluna, fim.linha, fim.coluna, palavras[i].palavra);
    }
}

void apagar_resolve(Tresolve *resolve) {
    for (int i = 0; i < resolve->qtd_palavras; i++) {
        apagar_palavra(&resolve->palavras[i]);
    }

    apagar_matriz(resolve->matriz);
    free(resolve->palavras);
    free(resolve);
}



