#ifndef GESTAOALUNOS_H_INCLUDED
#define GESTAOALUNOS_H_INCLUDED

#define MAXSTRING 80
#define MAXESTUDANTES 100
#define MIN_NUMALUNO 1
#define MAX_NUMALUNO 9999

typedef struct
{
    int dia, mes, ano;

}   tipoData;

typedef struct
{
    int num;
    char nome[MAXSTRING];
    tipoData dataAvaliacao;
    int notaFinal;

}   tipoEstudante;

int lerQuatEstudantes(void);
void lerDadosEstudantes(int quantEstudantes, tipoEstudante vetorEstudantes[]);

#endif // GESTAOALUNOS_H_INCLUDED
