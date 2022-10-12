#include <stdio.h>

#define SALARIO_BASE 600.00
#define ACRESCIMIENTO 100.00
#define PERCENTAMGEM 0.10

int main()
{
    int nCarrosVendidos, porCarro;
    float montanteFaturado, vencimiento, total, PERCENTAMGEM1;

    printf("Indique o nr de carros vendidos\n");
    scanf("%d", &nCarrosVendidos);

    printf("Indique o montante faturado\n");
    scanf("%f", &montanteFaturado);

    porCarro = nCarrosVendidos *100;
    PERCENTAMGEM1 = PERCENTAMGEM *100;

    vencimiento = PERCENTAMGEM * montanteFaturado;

    total = SALARIO_BASE + porCarro + vencimiento;

    printf("\n\n \t VENCIMIENTO:\n");
    printf("\t\t\t Salario Base\t\t\t %8.2f \n", SALARIO_BASE);
    printf("\t\t\t Por carro vendido\t\t %8.2d \n", porCarro);
    printf("\t\t\t %.2f %% das vendas:\t\t %8.2f \n",PERCENTAMGEM1, vencimiento);
    printf("\t\t\t _________________________________________");
    printf("\n\t\t\t TOTAL \t\t\t\t %8.2f \n", total);




}
