#include<stdio.h>

int main()
{
    int num1, num2, num3;
    scanf("%d%d%d", num1, num2, num3);

    if (num1 !=num2 && num3!= num2 && num3 != num1)
    {
        printf("TODOS DIFERENTES");
    }

    return 0;
}
