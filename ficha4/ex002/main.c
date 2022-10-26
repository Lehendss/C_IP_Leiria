#include <stdio.h>
#include <stdlib.h>

// DECLARA플O DAS FUN합ES
int lerNumero(void);
int areaRetangulo(int comp, int larg);

int main()
{
    int com, lar, area;

    printf("\nInserir o comprimento do retangulo\n");
    com = lerNumero();
    printf("\nInserir a largura do retangulo\n");
    lar = lerNumero();

    area = areaRetangulo(com, lar);
    printf("\nA area e :  %d\n", area);



    return 0;
}

// --IMPLEMENTA플O DAS FUN합ES
int leDadosRetangulo(int c, int l)
{

}

int areaRetangulo(int comp, int larg)
{
    int area;
    area = comp * larg;

    return area;
}

int lerNumero(void)
{
    int num;

    printf("\nValor:\n ");
    scanf("%d", &num);

    do
    {
        if(num <= 0)
        {
            printf("\nERRO: o valor tem de ser positivo\n");

        }

    }

    while(num <= 0);


    return num;
}

