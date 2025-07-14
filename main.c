#include <stdio.h>
#include <stdlib.h>

#include "Tmatriz.h"
#include "Tpalavra.h"
#include "Tocorrencias.h"
#include "resolve.h"

int main()
{
    int linhas, colunas, qtd_palavras;

    // Leitura das dimensões da matriz e da quantidade de palavras
    printf("Digite o numero de linhas\n");
    scanf("%d", &linhas);

    printf("Digite o numero de colunas \n");
    scanf("%d", &colunas);

    printf("Digite a quantidade de palavras:\n");
    scanf("%d", &qtd_palavras);

    // Criação da estrutura para resolver o caça-palavras
    printf("Criando estrutura do jogo...\n");
    Tresolve *resolve = criar_resolve(linhas, colunas, qtd_palavras);

    // Leitura da matriz e das palavras (usa funções internas do resolve)
    printf("Digite a matriz de letras (%d linhas de %d letras):\n", linhas, colunas);
    printf("E depois as %d palavras, uma por linha:\n\n", qtd_palavras);
    ler_resolve(resolve);

    // Busca as palavras na matriz
    printf("Buscando palavras na matriz...\n");
    Tocorrencias *ocorrencias = buscar_palavras_resolve(resolve);

    // Imprime os resultados
    printf("\nResultados encontrados:\n");
    imprimir_resultado_resolve(ocorrencias, resolve->palavras, qtd_palavras);

    // Libera memória alocada
    apagar_tocorrencias(ocorrencias);
    apagar_resolve(resolve);

    return 0;
}
