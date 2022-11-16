#include <stdio.h>
#include <stdlib.h>
#include "funcoesGenericas.h"

#define MAXINSCRITOS 25

int lerQuantAvailados(void);
void lerNotas(int vetorNotasFinais[], int quantAlunos);

int main()
{
    int vetorNotasFinais[MAXINSCRITOS];
    int quantAlunos;

    quantAlunos = lerQuantAvailados();
    lerNotas(vetorNotasFinais, quantAlunos);

    return 0;
}

void lerNotas(int vetorNotasFinais[], int quantAlunos)
{
    int i;
    char msg[50];

    for (i = 0; i < quantAlunos; i++)
    {

        sprintf(msg, "Insira a nota do aluno (%d): ", i + 1);
        vetorNotasFinais[i] = lerInteiro(msg, 0, 20);

    }
}

int lerQuantAvailados(void)
{
    int quantAlunos;

    quantAlunos = lerInteiro("\nIndique o nr. Alunos avaliados", 0, MAXINSCRITOS);


    return quantAlunos;
}
