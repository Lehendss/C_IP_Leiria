#include "gestaoReservas.h"

#include <stdio.h>
#include <string.h>

int procuraReserva(tipoReserva vetorReservas[], int quantReserva, char codigo[])
{
    int i, posicao = -1;

    for(i = 0; i < quantReserva; i++)
    {
        if(strcmp(codigo, vetorReservas[i].codigo) == 0)
        {
            posicao = i;
            i = quantReserva;
        }
    }
}

void criarReserva(tipoReserva vetorReservas[], int *quantReservas, tipoEstudante vetorEstudantes[], int quantEstudantes)//No se puede comparar un vetor con una variable
{
    int posReserva, posAluno;

    //Verificar se há espaco no vetor
    if(*quantReservas == MAX_RESERVAS || quantEstudantes == 0 )
    {
        printf("\n\nNAO e possivel efetuar mais reservas: Lotacao esgotada ou nao existe alunos inscritos");
    }
    else
    {
        printf("\n\nNOVA RESERVA\n");
        lerString("\nCodigo",vetorReservas[*quantReservas].codigo, TAM_CODIGO);
        posReserva = procuraReserva(vetorReservas, *quantReservas, vetorReservas[*quantReservas].codigo );
        if(posReserva != -1)
        {
            printf("\nERO: Ja existe reserva com o codigo indicado");
        }
        else
        {
            vetorReservas[*quantReservas].numAluno = lerInteiro("Nr.Aluno: ", MIN_NUMALUNO, MAX_NUMALUNO);
            procuraEstudante(vetorEstudantes, quantEstudantes, vetorReservas[*quantReservas].numAluno );

            if(posAluno == -1)
            {
                printf("\n\nERRO: aluno desconhecido");
            }
            else
            {
                vetorReservas[*quantReservas].dataRefeicao = lerData("Data Refeicao");
                vetorReservas[*quantReservas].tipoRefeicao = lerInteiro("Tipo Refeicao (1- Almoco /2- Jantar)", ALMOCO, JANTAR);
                (*quantReservas++);
           }
        }
    }

    //Pedir os dados da reserva ao utilizador
}


