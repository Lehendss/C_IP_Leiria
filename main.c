#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;


    do
    {
         printf("\ndigite um numero\n");
         scanf("%d", &num);
        if (num % 2 == 0)
        {
            printf("\nERRO nao e impar\n");
        }
    } while (num % 2 == 0);

    return 0;
}
