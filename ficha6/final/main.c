#include <stdio.h>
#include <stdlib.h>

#include "gestaoAlunos.h"

int main()
{
    tipoEstudante vetorEstudantes[MAXESTUDANTES];

    int quantEstudantes = 0, quantProvisoria;
    int i;

    quantProvisoria = lerQuatEstudantes();

    for(i = 0; i < quantProvisoria; i++)
    {
        printf("\nAluno %d: ", i+1);
        acrescentaAvaliado(vetorEstudantes, &quantEstudantes);
    }

    //2ª

    //3ª

    //lerDadosEstudantes(quantEstudantes, vetorEstudantes);

    return 0;

}
