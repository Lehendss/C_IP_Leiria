#include <stdio.h>
#include "funcoesGenericas.h"
#include "gestaoAlunos.h"

void lerDadosEstudantes(int quantEstudantes, tipoEstudante vetorEstudantes[])
{
    int i;

    for(i = 0; i < quantEstudantes; i++)
    {
        printf("\nALUNO %d", i+1);
        vetorEstudantes[i].num = lerInteiro("\nNr. Aluno", MIN_NUMALUNO, MAX_NUMALUNO);
    }
}
int lerQuatEstudantes(void)
{
    int num;

    num = lerInteiro("\n Indique o numero de alunos inscritos", 0, MAXESTUDANTES);

    return num;
}

