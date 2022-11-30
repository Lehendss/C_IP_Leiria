#include <stdio.h>
#include <string.h>
#include "funcoesGenericas.h"


tipoData lerdata(char msg[])
{
    tipoData data;
    int controlo, maxDia;

    do
    {
        printf("%s (dd-mm-aaaa)", msg);
        scanf("%d-%d-%d",&data.dia, &data.mes, &data.ano);
        limpaBuffer();

        if(controlo != 3 )
        {
            printf("\nERRO: estrutura da data incorreta.");
        }
        else
        {
            if (data.ano < MIN_ANO || data.ano > MAX_ANO)
            {
                printf("\nERRO: ano invalido. O ano dever pertencer ao intervalo [%d, %d]\n", MIN_ANO, MAX_ANO);
            }
            else
            {
                switch(data.mes)
                {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    maxDia = 31;
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    maxDia = 30;
                    break;
                case 2:
                    if(data.ano % 400 == 0 || (data.ano % 4 == 0 && data.ano % 100 != 0))
                    {
                        maxDia = 29;
                    }
                    else
                    {
                        maxDia =28;
                    }
                    break;
                default:
                    printf("\nERRO: mes incorrecto\n\n");
                    maxDia = 31;
                }
                if (data.dia < 1 || data.dia > maxDia)
                {
                    printf("\nERRO: dia incorreto. O intervalo do dia pertence a [%d, %d]", 1, maxDia);
                }
            }
        }
    }
    while (controlo != 3 || data.ano % 400 == 0 || (data.ano % 4 == 0 && data.ano % 100 != 0) || data.mes < 1 || data.mes > 12 || data.dia < 1 || data.dia > maxDia);




    return data;
}

void escreverData(tipoData data)
{
    printf("%02d-%02d-%d", data.dia, data.mes, data.ano);
}


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
        limpaBuffer();  // apenas faz sentido limpar buffer se a ficarem caracteres
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
