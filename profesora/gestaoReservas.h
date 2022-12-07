#ifndef GESTAORESERVAS_H_INCLUDED
#define GESTAORESERVAS_H_INCLUDED

#include "funcoesGenericas.h"
#include "gestaoAlunos.h"

#define TAM_CODIGO 5
#define MAX_RESERVAS 50
#define ALMOCO 1
#define JANTAR 2

typedef struct
{
    char codigo[TAM_CODIGO];
    int numAluno;
    tipoData dataRefeicao;
    int tipoRefeicao;

} tipoReserva;

int procuraReserva(tipoReserva vetorReservas[], int quantReserva, char codigo[]);
void criarReserva(tipoReserva vetorReservas[], int *quantReservas, tipoEstudante vetorEstudantes[], int quantEstudantes);
#endif // GESTAORESERVAS_H_INCLUDED
