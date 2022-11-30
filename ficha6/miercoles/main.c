#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "gestaoAlunos.h"
#include "funcoesGenericas.h"

char menu (int quantEstudantes);

int main()
{
    tipoEstudante vetorEstudantes[MAXESTUDANTES];
    int quantEstudantes = 0;



    char opcao;


    do
    {
        opcao = menu(quantEstudantes);

        switch(opcao)
        {
        case 'A':
            acrescentaAvaliado(vetorEstudantes, &quantEstudantes);
            break;
        case 'I':
            lerNotas(vetorEstudantes, quantEstudantes);
            break;
        case 'M':
            mostrarDados(vetorEstudantes, quantEstudantes);
            break;
        case 'G':
            gravaFicheiroBinario(vetorEstudantes, quantEstudantes);
            gravaFicheiroTexto(vetorEstudantes, quantEstudantes);
            break;
        case 'L':
            break;
        case 'F':
            break;
        default:
            printf("\nERRO: Opacao desconhecida\n");
        }
    }while(opcao != 'F');




/*
    quantProvisoria = lerQuatEstudantes();

    for(i = 0; i < quantProvisoria; i++)
    {
        printf("\nAluno %d: ", i+1);
        acrescentaAvaliado(vetorEstudantes, &quantEstudantes);
    }*/

    return 0;

}

char menu (int quantEstudantes)
{
    char opcao;

    printf("\n\n********************** MENU PRINCIPAL ********************** \n\n");
    printf("Estudantes Inscritos: %dn", quantEstudantes);
    printf("Estudantes Avaliados: ** \t\t Notas Positivas (%%): ***.**\n\n");
    printf("A - Acrescenta Estudante\nI - Introducao das Notas\n");
    printf("M - Mostrar Dados\nG - Gravar dados em ficheiros\n");
    printf("L - Ler dados de Ficheiro\nF - Fim\n");
    printf("\t\tOPCAO -> ");

    scanf("%c", &opcao);
    limpaBuffer();
    opcao = toupper(opcao);

    return opcao;
}
