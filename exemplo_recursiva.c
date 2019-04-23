#include <stdio.h>
#include <stdlib.h>

int produto(int *v, int);

int main()
{
    int n, i, *v, total;

    printf("\n Digite o tamanoho do vetor\n");
    scanf("%d",&n);

    
    v=(int*)malloc(n*sizeof(int));

    for (i = 0; i < n; i++)    
     v[i] = i + 1;

    total = produto(v, n);
    printf("\n total = %d", total);
    return 0;
}

int produto(int *v, int n)
{

    if (n >= 1)
    {
        return v[n - 1] * produto(v, n - 1);
    }
    else
    {
        return 1;
    }
}