#include <stdio.h>
#include "funcoesGenericas.h"
#include "gestaoAlunos.h"

/*void lerDadosEstudantes(int quantEstudantes, tipoEstudante vetorEstudantes[])
{
    int i;

    for(i = 0; i < quantEstudantes; i++)
    {
        printf("\nALUNO %d", i+1);
        vetorEstudantes[i].num = lerInteiro("\nNr. Aluno", MIN_NUMALUNO, MAX_NUMALUNO);
        lerString("\nNome: ", vetorEstudantes[i].nome, MAXSTRING);
    }
}*/
int procuraEstudante(tipoEstudante vetorEstudantes[], int quantEstudantes, int numAluno)
{
    int i, posicao = -1;

    for(i = 0; i < quantEstudantes; i++)
    {
        if(vetorEstudantes[i].num == numAluno)
        {
            posicao = i;
            i = quantEstudantes;
        }
    }

    return posicao;
}


void acrescentaAvaliado(tipoEstudante vetorEstudantes[], int *quantEstudantes)
{
    int posicao, opcao=0;

    if(*quantEstudantes == MAXESTUDANTES)
    {
        printf("\nO total de alunos ja atingiu o numero");
    }
    else
    {
        //2ª
        //lerDadosEstudante_V2(&vetorEstudantes[*quantEstudantes]);

        //3ª
        //vetorEstudantes[*quantEstudantes] = lerDadosEstudante_V3();

        //1ª
        do
        {

            vetorEstudantes[*quantEstudantes].num = lerDadosEstudante(vetorEstudantes[*quantEstudantes].nome);//Accede desde el vector hasta el nombre

            posicao = procuraEstudante(vetorEstudantes, *quantEstudantes, vetorEstudantes[*quantEstudantes].num);
            if(posicao == -1)
            {
                (*quantEstudantes)++;
            }
            else
            {
                printf("\nEERO: O aluno incidcado ja se encontra inscrito");
                opcao = lerInteiro("Deseja inseirir novo aluno?(1- SIM; 0-NAO)", 0, 1);
            }

        }
        while (opcao == 1);
    }
}


int lerDadosEstudante(char nome[])
{
    int num;

    num = lerInteiro("\nNumero do aluno: ", MIN_NUMALUNO, MAX_NUMALUNO);
    lerString("\nNome do aluno: ", nome, MAXSTRING);

    return num;
}
//2DA VERSÃO
void lerDadosEstudante_V2(tipoEstudante *aluno)
{
    //(*aluno).num
    aluno->num = lerInteiro("\nNumero do aluno: ", MIN_NUMALUNO, MAX_NUMALUNO);
    lerString("\nNome do aluno: ", aluno->nome, MAXSTRING);

}

//3RA VERSÃO
tipoEstudante lerDadosEstudante_V3(void)
{
    tipoEstudante aluno;

    aluno.num = lerInteiro("\nNumero do aluno: ", MIN_NUMALUNO, MAX_NUMALUNO);

    lerString("\nNome do aluno: ", aluno.nome, MAXSTRING);

    return aluno;
}


int lerQuatEstudantes(void)
{
    int num;

    num = lerInteiro("\n Indique o numero de alunos inscritos", 0, MAXESTUDANTES);

    return num;
}



