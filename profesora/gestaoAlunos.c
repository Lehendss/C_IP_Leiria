#include <stdio.h>
#include "funcoesGenericas.h"
#include "gestaoAlunos.h"


void gravaFicheiroTexto(tipoEstudante vetorEstudantes[], int quantEstudantes)
{
    FILE *ficheiro;
    int i;

    if (quantEstudantes == 0)
    {
        printf("\nATENCAO: nao existem estudantes inscritos\n\n");
    }
    else
    {
        ficheiro = fopen("dadosEstudantes.txt", "w");

        if (ficheiro == NULL)
        {
            printf("\nERRO: falha na abertura do ficheiro\n\n");
        }
        else
        {
            for (i=0; i < quantEstudantes; i++)
            {
                fprintf(ficheiro, "\n\nALUNO (%d)\n", i+1);
                fprintf(ficheiro, "Nr.%d - %s\n", vetorEstudantes[i].num, vetorEstudantes[i].nome);
                if (vetorEstudantes[i].notaFinal == -1)
                {
                    fprintf(ficheiro, "Aluno não avaliado\n");
                }
                else
                {
                    fprintf(ficheiro, "Nota final: %d ", vetorEstudantes[i].notaFinal);
                    fprintf(ficheiro, " (%02d-%02d-%d)\n", vetorEstudantes[i].dataAvaliacao.dia,
                            vetorEstudantes[i].dataAvaliacao.mes,
                            vetorEstudantes[i].dataAvaliacao.ano);
                }
            }
            fclose(ficheiro);
        }
    }
}


void lerFicheiroBinario(tipoEstudante vetorEstudantes[], int *quantEstudantes)
{
    FILE *ficheiro;
    int controlo;

    ficheiro = fopen("dadosEstudantes.bin", "rb");

    if (ficheiro == NULL)
    {
        printf("\nERRO: falha na abertura do ficheiro\n");
    }
    else
    {
        controlo = fread(quantEstudantes, sizeof(int), 1, ficheiro);
        if (controlo != 1)
        {
            printf("\nERRO: falha na leitura dos valores\n");
        }
        else
        {
            controlo = fread(vetorEstudantes, sizeof(tipoEstudante), *quantEstudantes, ficheiro);
            if (controlo != *quantEstudantes)
            {
                printf("\nERRO: falha na leitura dos valores\n");
                *quantEstudantes = 0;
            }
            else
            {
                printf("\nDados lidos com sucesso\n");
            }
        }

        fclose(ficheiro);
    }
}


void gravaFicheiroBinario(tipoEstudante vetorEstudantes[], int quantEstudantes)
{
    FILE *ficheiro;
    int controlo;

    ficheiro = fopen("dadosEstudantes.bin", "wb");

    if (ficheiro == NULL)
    {
        printf("\nERRO: falha na abertura do ficheiro\n");
    }
    else
    {
        controlo = fwrite(&quantEstudantes, sizeof(int), 1, ficheiro);
        if (controlo != 1)
        {
            printf("\nERRO: falha na escrita dos valores\n");
        }
        else
        {
            controlo = fwrite(vetorEstudantes, sizeof(tipoEstudante), quantEstudantes, ficheiro);
            if (controlo != quantEstudantes)
            {
                printf("\nERRO: falha na escrita dos valores\n");
            }
            else
            {
                printf("\nDados guardados com sucesso\n");
            }
        }

        fclose(ficheiro);
    }
}


void lerNotas(tipoEstudante vetorEstudantes[], int quantEstudantes)
{
    int i, contador = 0;

    if (quantEstudantes == 0)
    {
        printf("\nATENCAO: nao ha estudantes inscritos\n\n");
    }
    else
    {
        for (i=0; i < quantEstudantes; i++)
        {
            if(vetorEstudantes[i].notaFinal == -1)
            {
                printf("\nAluno (%d) %s\n", vetorEstudantes[i].num, vetorEstudantes[i].nome);
                vetorEstudantes[i].notaFinal = lerInteiro("Nota Final: ", MIN_NOTA, MAX_NOTA);
                vetorEstudantes[i].dataAvaliacao = lerData("Data Avaliacao: ");
                contador++;
            }
        }
        if(contador == 0)
        {
            printf("\n\nATENCAO: Nao existe alunos por avaliar\n");
        }
    }
}

void mostrarDados(tipoEstudante vetorEstudantes[], int quantEstudantes)
{
    int i;

    if (quantEstudantes==0)
    {
        printf("\nATENCAO: nao existem estudantes inscritos\n\n");
    }
    else
    {
        for (i=0; i < quantEstudantes; i++)
        {
            printf("\n\nALUNO %d\n", i+1);
            printf("Nr: %d\n", vetorEstudantes[i].num);
            printf("Nome: %s\n", vetorEstudantes[i].nome);
            if (vetorEstudantes[i].notaFinal == -1)
            {
                printf("-- Aluno nao avaliado--");
            }
            else
            {
                printf("Data Avaliacao: ");
                escreverData(vetorEstudantes[i].dataAvaliacao);
                printf("\nNota Final: %d", vetorEstudantes[i].notaFinal);
            }
        }
    }
}


int procuraEstudante(tipoEstudante vetorEstudantes[], int quantEstudantes, int numAluno)
{
    int i, posicao=-1;

    for(i=0; i<quantEstudantes; i++)
    {
        if (vetorEstudantes[i].num == numAluno)
        {
            posicao = i;
            i = quantEstudantes;
        }
    }

    return posicao;
}




void acrescentaAvaliado (tipoEstudante vetorEstudantes[], int *quantEstudantes)
{
    int posicao, opcao=0;

    if (*quantEstudantes == MAXESTUDANTES)
    {
        printf("\nATENCAO: o total de alunos inscritos ja atingiu o maximo permitido\n");
    }
    else
    {
        // 1ª versão
        do
        {
            vetorEstudantes[*quantEstudantes].num = lerDadosEstudante(vetorEstudantes[*quantEstudantes].nome);

            posicao = procuraEstudante(vetorEstudantes, *quantEstudantes, vetorEstudantes[*quantEstudantes].num );
            if (posicao == -1)
            {
                vetorEstudantes[*quantEstudantes].notaFinal = -1;
                (*quantEstudantes)++;
                opcao = 0;
            }
            else
            {
                printf("\nERRO: o aluno indicado ja se encontra inscrito\n");
                opcao = lerInteiro("\nDeseja inserir novo aluno (0-Nao; 1-Sim)", 0, 1);
            }
        }
        while (opcao == 1);

        // 2ª versão
        // lerDadosEstudante_v2(&vetorEstudantes[*quantEstudantes]);

        // 3ª versão
        // vetorEstudantes[*quantEstudantes] = lerDadosEstudante_v3();
    }
}


int lerDadosEstudante(char nome[])
{
    int num;

    num = lerInteiro("\nNr. Aluno", MIN_NUMALUNO, MAX_NUMALUNO);

    lerString("\nNome: ", nome, MAXSTRING);

    return num;
}

// 2ª versão
void lerDadosEstudante_v2(tipoEstudante *aluno)
{
    //(*aluno).num
    aluno->num = lerInteiro("\nNr. Aluno", MIN_NUMALUNO, MAX_NUMALUNO);

    lerString("\nNome: ", aluno->nome, MAXSTRING);
}

// 3ª versão
tipoEstudante lerDadosEstudante_v3(void)
{
    tipoEstudante aluno;

    aluno.num = lerInteiro("\nNr. Aluno", MIN_NUMALUNO, MAX_NUMALUNO);

    lerString("\nNome: ", aluno.nome, MAXSTRING);

    return aluno;
}

int lerQuantidadeEstudantes(void)
{
    int num;

    num = lerInteiro("\nIndique o numero de alunos inscritos", 0, MAXESTUDANTES);

    return num;
}
