#ifndef GESTAOALUNOS_H_INCLUDED
#define GESTAOALUNOS_H_INCLUDED

#include "funcoesGenericas.h"

#define MAXSTRING 80
#define MAXESTUDANTES 100
#define MIN_NUMALUNO 1
#define MAX_NUMALUNO 9999
#define MIN_NOTA 0
#define MAX_NOTA 20
#define NOTA_POSITIVA 9.5


typedef struct{
    int num;
    char nome[MAXSTRING];
    tipoData dataAvaliacao;
    int notaFinal;
} tipoEstudante;


int lerQuantidadeEstudantes(void);
int lerDadosEstudante(char nome[]);
void acrescentaAvaliado (tipoEstudante vetorEstudantes[], int *quantEstudantes);
int procuraEstudante(tipoEstudante vetorEstudantes[], int quantEstudantes, int numAluno);
void mostrarDados(tipoEstudante vetorEstudantes[], int quantEstudantes);
void lerNotas(tipoEstudante vetorEstudantes[], int quantEstudantes);
void gravaFicheiroBinario(tipoEstudante vetorEstudantes[], int quantEstudantes);
void lerFicheiroBinario(tipoEstudante vetorEstudantes[], int *quantEstudantes);

// 2ª versão
void lerDadosEstudante_v2(tipoEstudante *aluno);
// 3ª versão
tipoEstudante lerDadosEstudante_v3(void);

void gravaFicheiroTexto(tipoEstudante vetorEstudantes[], int quantEstudantes);


#endif // GESTAOALUNOS_H_INCLUDED
