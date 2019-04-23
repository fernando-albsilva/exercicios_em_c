#include <stdio.h>

int fatorial(int);
void chama_fat();

int main()
{

    chama_fat();

    return 0;
}
void chama_fat()
{
    int n, teste = 1;

    do
    {
        printf("\n Digite o numero a ser calculado seu fatorial : ");
        scanf("%d", &n);
        printf("\n------------------\n");
        printf("\n %d!  = %d\n", n, fatorial(n));
        printf("\n------------------\n");
        printf(" \nDigite qualquer numero para continuar calculando outro numero ou 0 para sair\n");
        scanf("%d", &teste);
    } while (teste != 0);
}
int fatorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return (n * fatorial(n - 1));
    }
}