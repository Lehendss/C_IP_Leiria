#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, soma, quantNum;
    int quantPos, quantNeg;
    soma = 0;

    printf("Introducir numeros interios\n");

    //Sequência de numeros até ser 0

    do
    {

        scanf("%d", &numero);

        if (numero != 0)
        {
            soma+= numero;
            quantNum++;

            if(numero > 0)
            {
                quantPos++;
            }
            else
            {
                quantNeg++;
            }
        }



    }
    while (numero != 0);

    printf("\nSOMA = %d", soma);
    printf("\nMEDIA = %.2f", (float)soma/quantNum);
    printf("\nTOTAL POSITIVOS = %.d(%.2f%%)\n\n", quantPos, quantPos* 100.0/quantNeg);




    return 0;
}
