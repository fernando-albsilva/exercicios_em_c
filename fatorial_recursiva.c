#include <stdio.h>

int fatorial(int);

int main()
{
    int n;

    printf(" Digite o numero para saber seu fatorial\n");
    scanf("%d",&n);

    n=fatorial(n);

    printf(" Total = %d", n);

    return 0;
}

int fatorial(int n)
{
    if (n==0)
    {
        return 1;
    }
    else
    {
    return (n*fatorial(n-1));

    }
}