#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// DECLARA플O DAS FUN합ES

int lerNumero(void);
int areaRetangulo(int comp, int larg);
int leDadosRetangulo(int *lar);
void leDadosRetangulov2(int *lar, int *com);
char menu(int qTriangulo, int  qRetangulo, int qCircu, int qQuadrado);

int main()
{

    int qTriangulo = 0, qRetangulo = 0, qCircu = 0, qQuadrado = 0;
    int com, lar, area;
    char opcao;


    //MENU
    do
    {
        opcao = menu(qTriangulo, qRetangulo, qCircu, qQuadrado);

        //SWITCH OP합ES
        switch(opcao)
        {
        case 'T':
            break;
        case 'Q':
            break;
        case 'C':
            break;
        case 'R':
            leDadosRetangulov2(&lar, &com);
            com = leDadosRetangulo(&lar);
            area = areaRetangulo(com, lar);
            printf("\nA area e :  %d\n", area);
            qRetangulo++;
            break;
        case 'S':
            break;
        default:
            printf("\n ERRO\n");

        }
    }
    while(opcao != 'S');





    return 0;
}

// --IMPLEMENTA플O DAS FUN합ES

char menu(int qTriangulo, int  qRetangulo, int qCircu, int qQuadrado)
{
    char opcao;

    printf("\n\t\tCalculo de Areas\n");
    printf("\nTriangulo(N):%d \t\t\tRetangulo (N):%d\n ", &qTriangulo, &qRetangulo);
    printf("\nCirculo(N):%d \t\t\tQuadrado (N):%d\n ", &qCircu, &qQuadrado);

    printf("\n\t\tOPCOES\n");
    printf("\n\t\t(T)riangulo\n");
    printf("\n\t\t(R)etagulo\n");
    printf("\n\t\t(Q)uadrado\n");
    printf("\n\t\t(C)irculo\n");
    printf("\n\t\t(Q)uadrado\n");
    printf("\n\t\t(F)im\n");
    printf("\nSelecione opcao:\n");

    scanf(" %c", opcao);
    opcao = toupper(opcao);

    return opcao;
}

void leDadosRetangulov2(int *lar, int *com)
{
    printf("\nInserir o comprimento do retangulo\n");
    *com = lerNumero();

    printf("\nInserir a largura do retangulo\n");
    *lar = lerNumero();

}

int leDadosRetangulo(int *lar)
{
    int com;

    printf("\nInserir o comprimento do retangulo\n");
    com = lerNumero();

    printf("\nInserir a largura do retangulo\n");
    *lar = lerNumero();

    return com;
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

