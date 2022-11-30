#ifndef FUNCOESGENERICAS_H_INCLUDED
#define FUNCOESGENERICAS_H_INCLUDED

#define MIN_ANO 2000
#define MAX_ANO 2050


typedef struct
{
    int dia, mes, ano;

}   tipoData;

int lerInteiro (char msg[], int limMin, int limMax);
void limpaBuffer(void);
void lerString(char mensagem[], char vetorCaracteres[], int maximoCaracteres);
void escreverData(tipoData data);
tipoData lerdata(char msg[]);

#endif // FUNCOESGENERICAS_H_INCLUDED
