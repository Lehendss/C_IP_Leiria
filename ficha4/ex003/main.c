#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//DECLARA플O DAS FUN플OES

int binomioDiscriminante(int a, int b, int c);
int numDeZerosReais(int a, int b, int c);

int main()
{
    int a, b, c, nZeros, resBinomio;

    do
    {
        printf("\nInsira o valor de \"a\" : \n");
        scanf("%d", &a);

        if (a == 0)
        {
            printf("\nERRO: O valor de \"a\" nao pode ser zero\n");
        }

    }
    while (a == 0);

    printf("\nInsira o valor de \"b\" : \n");
    scanf("%d", &b);

    printf("\nInsira o valor de \"c\" : \n");
    scanf("%d", &c);

    nZeros = numDeZerosReais(a, b, c);

    switch (nZeros)
    {
    case 0:
        printf("\nApenas raizes imaginarias\n");
        break;

    case 1:
        printf("\nApenas uma raiz real\n %.2f\n ", -b / (2.0*a));
        break;

    case 2:
        resBinomio = binomioDiscriminante(a, b, c);
        printf("\nDuas raizes reais\n");
        printf("\n Raiz 1: %.2f\n", (-b + sqrt(resBinomio) /(2.0*a)));
        printf("\n Raiz 2: %.2f\n", (-b - sqrt(resBinomio) /(2.0*a)));
        break;
    }

    return 0;
}

//IMPLEMENTA플O DAS FUN플OES

int binomioDiscriminante(int a, int b, int c)
{

    int bd;

    bd = (b*b) - (4 * (a *c));

    return bd;
}


int numDeZerosReais(int a, int b, int c)
{
    int resultado,nZeros;

    resultado = binomioDiscriminante(a, b, c);

    if (resultado < 0)
    {
        nZeros = 0;
    }
    else
    {
        if( resultado == 0)
        {
            nZeros = 1;
        }
        else
        {
            nZeros = 2;
        }
    }

    return nZeros;
}

