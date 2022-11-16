#include <stdio.h>
#include "funcoesGenericas.h"


void lerString(char mensagem[], char vetorCaracteres[], int maximoCaracteres)
{
    int tamanhoString;

    do 			// Repete leitura caso sejam obtidas strings vazias
    {
        printf("%s", mensagem);
        fgets(vetorCaracteres, maximoCaracteres, stdin);

        tamanhoString = strlen(vetorCaracteres);

        if (tamanhoString == 1)
        {
            printf("Nao foram introduzidos caracteres!!! . apenas carregou no ENTER \n\n");  // apenas faz sentido limpar buffer se a ficarem caracteres
        }

    }
    while (tamanhoString == 1);

    if(vetorCaracteres[tamanhoString-1] != '\n')  // ficaram caracteres no buffer....
    {
        limpaBufferStdin();  // apenas faz sentido limpar buffer se a ficarem caracteres
    }
    else
    {
        vetorCaracteres[tamanhoString-1] = '\0'; 	//Elimina o \n da string armazenada em vetor
    }

}


int lerInteiro (char msg[], int limMin, int limMax)
{
    int num, controlo;

    do
    {
        printf("%s [%d, %d]:", msg, limMin, limMax);
        controlo = scanf(" %d", &num);
        limpaBuffer();

        if(controlo != 1 )//Significa que nao fez atribucao a variabel
        {
            printf("ERRO: o valor inserido nao e numerico\n");
        }
        else
        {
            if(num < limMin || num > limMax)
            {
                printf("ERRO: o numero nao pertece ao intervalo");
            }
        }
    }
    while(controlo != 1 || num < limMin || num > limMax);

    return num;

}

void limpaBuffer(void)
{
    char letra;
    do
    {
        letra = getchar();
    }
    while (letra != '\n' && letra != EOF);
}
