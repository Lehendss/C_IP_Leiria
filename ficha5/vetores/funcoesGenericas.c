#include <stdio.h>
#include "funcoesGenericas.h"

int lerInteiro (char msg[], int limMin, int limMax)
{
    int num;



    do
    {
        printf("%s [%d, %d]:", msg, limMin, limMax);
        scanf("%d", &num);

        if(num < limMin || num > limMax)
        {
            printf("ERRO: o numero nao pertece ao intervalo");
        }
    }
    while(num < limMin || num > limMax);

    return num;

}
