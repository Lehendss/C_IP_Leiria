#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;

    printf("Indique 3 comprimentos:\n");
    scanf("%d%d%d", &a, &b, &c);

    if (abs (a  - b) < c && c < (a + b))
    {
        printf("Os comprimentos formam um triangulo\n");
        if (a == b && b ==c )
        {
            printf("\n\tE um triangulo equilatero\n");
        }
        else
        {
            if(a != b && b!= c && a != c)
            {
             printf("\n\tE um triangulo escaleno\n");
            }
            else
            {
                 printf("\n\tE um triangulo isosceles\n");
            }
        }
    }

    else
    {
        printf("Os comprimentos nao formam um triangulo");
    }


    return 0;
}
