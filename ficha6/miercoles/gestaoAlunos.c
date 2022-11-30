#include <stdio.h>
#include "funcoesGenericas.h"
#include "gestaoAlunos.h"

int contas(tipoEstudante vetorEstudantes[], int quantEstudantes)
{
    int pNotasPositivas;


}


void gravaFicheiroTexto(tipoEstudante vetorEstudantes[], int quantEstudantes)
{
    FILE *ficheiro;

    int i;

    if(quantEstudantes == 0)
    {
        printf("\nATENCAO: Nao existe estudantes inscritos");
    }
    else
    {
        ficheiro = fopen("dadosEstudantes.txt", "w");

        if(ficheiro == NULL)
        {
            printf("\nERRO: falha na apertura do  ficheiro\n\n");

        }
        else
        {
            for(i = 0; i < quantEstudantes; i++)
            {
                fprintf(ficheiro, "\nALUNO (%d)\n", i+1);
                fprintf(ficheiro, "\nNr.%d- %s\n", vetorEstudantes[i].num, vetorEstudantes[i].nome);
                if(vetorEstudantes[i].notaFinal == -1)
                {
                    fprintf(ficheiro, "Aluno nao availado\n");

                }
                else
                {
                    fprintf(ficheiro, "Nota final : %d\n", vetorEstudantes[i].notaFinal);
                    fprintf(ficheiro, "%02d-%02d-%d\n", vetorEstudantes[i].dataAvaliacao.dia, vetorEstudantes[i].dataAvaliacao.mes, vetorEstudantes[i].dataAvaliacao.ano);


                }

            }
            fclose(ficheiro);
        }

    }


}

void gravaFicheiroBinario(tipoEstudante vetorEstudantes[], int quantEstudantes)
{
    FILE * ficheiro;
    int controlo;

    ficheiro = fopen("dadosEstudantes.bin", "wb");
    if(ficheiro == NULL)
    {
        printf("\nERRO: falha na abertura do ficheiro\n");
    }
    else
    {
        controlo = fwrite(&quantEstudantes, sizeof(int), 1, ficheiro);
        if( controlo != 1)
        {
            printf("\nERRO: Falha na escrita dos valores\n");
        }
        else
        {
            controlo = fwrite(vetorEstudantes, sizeof(tipoEstudante), quantEstudantes, ficheiro);
            if(controlo != quantEstudantes )
            {
                printf("\nERRO: Falha na escrita dos valores\n");
            }
            else
            {
                printf("\n Dados guarados co, suceso");
            }
        }
        fclose(ficheiro);
    }
}

void lerFicheiroBinario(tipoEstudante vetorEstudantes[], int *quantEstudantes)
{
    FILE * ficheiro;
    int controlo;

    ficheiro = fopen("dadosEstudantes.bin", "wb");
    if(ficheiro == NULL)
    {
        printf("\nERRO: falha na abertura do ficheiro\n");
    }
    else
    {
        controlo = fread(quantEstudantes, sizeof(int), 1, ficheiro);
        if( controlo != 1)
        {
            printf("\nERRO: Falha na leitura dos valores\n");
        }
        else
        {
            controlo = fread(vetorEstudantes, sizeof(tipoEstudante), *quantEstudantes, ficheiro);
            if(controlo != *quantEstudantes )
            {
                printf("\nERRO: Falha na leitura dos valores\n");
                *quantEstudantes = 0;
            }
            else
            {
                printf("\n Dados lidos com suceso");
            }
        }
        fclose(ficheiro);
    }
}


void lerNotas(tipoEstudante vetorEstudantes[], int quantEstudantes)
{
    int i;

    if (quantEstudantes == 0)
    {
        printf("\nATENCAO: Nao ha eestudantes inscritos");

    }
    else
    {
        for(i = 0; i < quantEstudantes; i++)
        {
            printf("\nAluno (%d) %s\n", vetorEstudantes[i].num, vetorEstudantes[i].nome);
            vetorEstudantes[i].notaFinal = lerInteiro("Nota final: ", MIN_NOTA, MAX_NOTA);
            vetorEstudantes[i].dataAvaliacao = lerdata("Data de avaliacao: ");
        }
    }
}


void mostrarDados(tipoEstudante vetorEstudante[], int quantEstudantes)
{
    int i;

    if(quantEstudantes == 0)
    {
        printf("\nATENCAO: nao existem estudantes inscritos");
    }
    else
    {
        for (i = 0; i < quantEstudantes; i++)
        {
            printf("\n\nALUNO %d", i + 1);
            printf("\nNr: %d\n", vetorEstudante[i].num);
            printf("\nNome: %s\n", vetorEstudante[i].nome);
            if(vetorEstudante[i].notaFinal == -1)
            {
                printf("--Aluno NAO avaliado--");

            }
            else
            {
                printf("Data Availacao: ");
                escreverData(vetorEstudante[i].dataAvaliacao);
                printf("\nNota final: %d", vetorEstudante[i].notaFinal);
            }

        }
    }
}

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
                vetorEstudantes[*quantEstudantes].notaFinal = -1;
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



