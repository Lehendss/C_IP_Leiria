#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int num, soma, i, contaWhile, contaDoWhile, contaFor;
    char opcao;




    do
    {
        printf("Digite um numero inteiro positivo\n");
        scanf("%d", &num);

        if (num <= 0)
        {
            printf("nao e positivo");
        }
    }
    while (num <= 0);

    //menu

    printf("\nChoose an option:\n");
    printf("\n(W) Ciclo 'While'\n");
    printf("(D) Ciclo 'Do..While'\n");
    printf("(F) Ciclo For\n");
    printf("(Sair)\n");
    printf("\n\tOPCAO\n");
    scanf(" %c", &opcao);
    opcao = toupper(opcao);

    do
    {


        switch (opcao)
        {
        case 'W':

            contaWhile++;
            i =1;
            soma = 0;

            while(contador <= num)
            {
                printf("Resultado do WHILE: %d", soma);
            }

            break;
        case 'D':

            contaDoWhile++;
            i =1;
            soma = 0;

            do
            {
                soma = soma + i;
                i++;

            }
            while(i <= num);
            soma = soma + i;
            i++;


            {
                printf("Resultado do DO..WHILE: %d", soma);
            }

            break;
        case 'F':

            contaFor++;
            for (i=1, soma=0; i <= num ; i++)
            {
                soma = soma + i;
            }
            printf("\nResultado do ciclo FOR: %d\n", soma);

            break;
        case 'S':

            break;
        default:
            printf("\nOpcao invalida\n");

        }
    }
    while (opcao != 'S');

    printf("\n Total de utilizacao dos ciclos : \n");
    printf("\n WHILE: %d\n", contaWhile);
    printf("\n WHILE: %d\n", contaFor);
    printf("\n WHILE: %d\n", contaDoWhile);

    return 0;
}
