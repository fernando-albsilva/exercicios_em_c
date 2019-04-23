/* Calcula o produto de um vetor de n elementos inteiros recursivamente */

#include <stdio.h>
#include <stdlib.h>

void tamanho_vetor(int *);
int *alloc_vetor(int *, int);
int *preenche_vetor(int *, int);
int produto(int *v, int);

int main()
{
    int n, i, *v, total;

    tamanho_vetor(&n);
    v = alloc_vetor(v, n);
    v = preenche_vetor(v, n);

    total = produto(v, n);
    printf("\n----------------------\n");
    printf("\n total = %d\n", total);
    printf("\n----------------------\n");
    return 0;
}
void tamanho_vetor(int *p_n)
{

    printf("\n Digite o tamanoho do vetor:\n");
    scanf("%d", &*p_n);
}
int *alloc_vetor(int *v, int n)
{
    v = (int *)malloc(n * sizeof(int));
    return v;
}
int *preenche_vetor(int *v, int n)
{
    int i = 0;
    for (; i < n; i++)
    {
        printf("\n Digite v[%d] : ", i);
        scanf("%d", &v[i]);
    }

    return v;
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