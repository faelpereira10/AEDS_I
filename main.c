#include <stdio.h>
#include <stdlib.h>

#include "Tmatriz.h"
#include "Tpalavra.h"
#include "Tocorrencias.h"
#include "resolve.h"

int main() {
    int linhas, colunas, qtd_palavras;

    // Etapa 1: Leitura das dimensões da matriz e da quantidade de palavras
    printf("Digite o numero de linhas, colunas e a quantidade de palavras:\n");
    scanf("%d %d %d", &linhas, &colunas, &qtd_palavras);

    // Etapa 2: Criação da estrutura de resolução do jogo
    printf("Criando estrutura do jogo...\n");
    Tresolve *resolve = criar_resolve(linhas, colunas, qtd_palavras);

    // Etapa 3: Leitura da matriz e das palavras
    printf("Digite a matriz de letras (%d linhas de %d letras):\n", linhas, colunas);
    printf("E depois as %d palavras, uma por linha:\n", qtd_palavras);
    ler_resolve(resolve);

    // Etapa 4: Busca das palavras na matriz
    printf("Buscando palavras na matriz...\n");
    Tocorrencias *ocorrencias = buscar_palavras_resolve(resolve);

    // Etapa 5: Impressão dos resultados
    printf("\nResultados encontrados:\n");
    imprimir_resultado_resolve(ocorrencias, resolve->palavras, qtd_palavras);

    // Etapa 6: Liberação da memória alocada
    apagar_tocorrencias(ocorrencias);
    apagar_resolve(resolve);

    return 0;
}
