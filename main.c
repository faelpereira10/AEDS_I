#include <stdlib.h>
#include <stdio.h>
#include "Tmatriz.h"

int main()
{

    int a = 0, b = 0;
    scanf("%d", &a);
    scanf("%d", &b);

    Tmatriz *m = criar_matriz(a, b);

    preencher_matriz(m);
    imprimir_matriz(m);
    apagar_matriz(m);

    return 0;
}
