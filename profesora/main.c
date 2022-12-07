#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "gestaoAlunos.h"
#include "gestaoReservas.h"
#include "funcoesGenericas.h"

char menu (int quantEstudantes, int quantAvaliados, float percPositivas);
float contas(int *quantAvaliados, tipoEstudante vetorEstudantes[], int quantEstudantes);


int main()
{
    tipoReserva vetorReservas[MAX_RESERVAS];
    int quantReservas = 0;

    tipoEstudante vetorEstudantes[MAXESTUDANTES];
    int quantEstudantes = 0, quantAvaliados = 0;
    float percPositivas = 0;
    char opcao;

    do
    {
        opcao = menu(quantEstudantes, quantAvaliados, percPositivas);
        switch (opcao)
        {
        case 'C':
            criarReserva(vetorReservas, &quantReservas, vetorEstudantes, quantEstudantes);
            break;
        case 'A':
            acrescentaAvaliado(vetorEstudantes, &quantEstudantes);
            break;
        case 'I':
            lerNotas(vetorEstudantes, quantEstudantes);
            percPositivas = contas(&quantAvaliados, vetorEstudantes, quantEstudantes);
            break;
        case 'M':
            mostrarDados(vetorEstudantes, quantEstudantes);
            break;
        case 'G':
            gravaFicheiroBinario(vetorEstudantes, quantEstudantes);
            gravaFicheiroTexto(vetorEstudantes, quantEstudantes);
            break;
        case 'L':
            lerFicheiroBinario(vetorEstudantes, &quantEstudantes);
            percPositivas = contas(&quantAvaliados, vetorEstudantes, quantEstudantes);
            break;
        case 'F':
            break;
        default:
            printf("\nERRO: opcao desconhecida\n");
        }
    }
    while (opcao != 'F');

    return 0;
}


float contas(int *quantAvaliados, tipoEstudante vetorEstudantes[], int quantEstudantes)
{
    int i, quantPositivas=0;
    float perPositivas=0;

    *quantAvaliados = 0;
    for (i=0; i < quantEstudantes; i++)
    {
        if (vetorEstudantes[i].notaFinal != -1)
        {
            (*quantAvaliados)++;

            if (vetorEstudantes[i].notaFinal >= NOTA_POSITIVA)
            {
                quantPositivas++;
            }
        }
    }
    if (*quantAvaliados > 0)
    {
        perPositivas = quantPositivas * 100.0 / *quantAvaliados;
    }

    return perPositivas;
}


char menu (int quantEstudantes, int quantAvaliados, float percPositivas)
{
    char opcao;

    printf("\n\n********************** MENU PRINCIPAL ********************** \n\n");
    printf("Estudantes Inscritos: %d\n", quantEstudantes);
    printf("Estudantes Avaliados: %d \t\t Notas Positivas (%%): %.2f\n\n", quantAvaliados, percPositivas);
    printf("A - Acrescenta Estudante\nI - Introducao das Notas\n");
    printf("M - Mostrar Dados\nG - Gravar dados em ficheiros\n");
    printf("C - Criar reserva\n");
    printf("L - Ler dados de Ficheiro\nF - Fim\n");
    printf("\t\tOPCAO -> ");

    scanf("%c", &opcao);
    limparBuffer();

    opcao = toupper(opcao);

    return opcao;
}
