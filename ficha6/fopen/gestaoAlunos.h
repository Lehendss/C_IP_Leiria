#ifndef GESTAOALUNOS_H_INCLUDED
#define GESTAOALUNOS_H_INCLUDED

#include "funcoesGenericas.h"
#define MAXSTRING 80
#define MAXESTUDANTES 100
#define MIN_NUMALUNO 1
#define MAX_NUMALUNO 9999
#define MIN_NOTA 0
#define MAX_NOTA 20


typedef struct
{
    int num;
    char nome[MAXSTRING];
    tipoData dataAvaliacao;
    int notaFinal;

}   tipoEstudante;

int lerQuatEstudantes(void);
int lerDadosEstudante(char nome[]);
void acrescentaAvaliado(tipoEstudante vetorEstudantes[], int *quantEstudantes);
int procuraEstudante(tipoEstudante vetorEstudantes[], int quantEstudantes, int numAluno);
void mostrarDados(tipoEstudante vetorEstudante[], int quantEstudantes);
void lerNotas(tipoEstudante vetorEstudantes[], int quantEstudantes);
void gravaFicheiroBinario(tipoEstudante vetorEstudantes[], int quantEstudantes);

//2ª
void lerDadosEstudante_V2(tipoEstudante *aluno);
//3ª
tipoEstudante lerDadosEstudante_V3(void);

//void lerDadosEstudantes(int quantEstudantes, tipoEstudante vetorEstudantes[]);

#endif // GESTAOALUNOS_H_INCLUDED
