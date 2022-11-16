#include <stdio.h>
#include <stdlib.h>

#include "gestaoAlunos.h"

int main()
{
    tipoEstudante vetorEstudantes[MAXESTUDANTES];

    int quantEstudantes = 0;

    quantEstudantes = lerQuatEstudantes();
    lerDadosEstudantes(quantEstudantes, vetorEstudantes);

    return 0;

}
