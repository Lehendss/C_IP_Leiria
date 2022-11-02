#include <stdio.h>
#include <stdlib.h>

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
    int indice;

    for (indice = 0; indice < quantAlunos; indice++)
    {
        printf("Insira a nota do aluno (%d): ", indice + 1);
        scanf("%d", &vetorNotasFinais[indice]);

    }
}

int lerQuantAvailados(void)
{
    int quantAlunos;

    printf("\nIndique o nr. Alunos avaliados: ");
    scanf("%d", &quantAlunos);


    return quantAlunos;
}
