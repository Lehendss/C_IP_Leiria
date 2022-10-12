#include <stdio.h>

int main()
{
    int numero;

    printf("Inserir numero:\n ");
    scanf("%d", &numero);


    if (numero > 0 && (numero % 2) == 0)
    {
        printf("numero POSITIVO e PAR\n");
    }
    else
    {
        if(numero > 0 && (numero % 2) == 1)
        {
            printf("numero POSITIVO e IMPAR\n");
        }
        else
        {
            printf("numero NULL");
        }
    }


    if (numero < 0 && (numero % 2)== 0)
    {
        printf("numero NEGATIVO e PAR\n");

    }
    else
    {
        if(numero < 0 && (numero % 2) == 1)
        {
            printf("numero NEGATIVO e IMPAR\n");
        }
    }



    return 0;
}
