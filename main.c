#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, contador, soma;

    do
    {
        printf("Digite um numero inteiro positivo\n");
        scanf("%d", &num);

        if (num <= 0)
        {
            printf("nao e positivo");
        }
    }while (num <= 0);

    do
    {
        soma = soma + contador;
        contador++;

    }while(contador <= num);

    {
        printf("Resultado do DO..WHILE: %d", soma);
    }


}
