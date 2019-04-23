/* Exemplo de matriz transposta e matriz unidimensional alocadas dinamicamente */

#include <stdio.h>
#include <stdlib.h>

int **tamanho_mat(int **, int *, int *);
int **preenche_mat(int **, int, int);
void imprime_mat(int **mat, int, int);
int *tamanho_mat_u(int *, int *, int *);
int *preenche_mat_u(int *, int, int);
void imprime_mat_u(int*,int ,int);
int main()
{
    int **mat, tam_l, tam_c;
    int *mat_u, tam_u_l, tam_u_c;

    mat = tamanho_mat(mat, &tam_l, &tam_c);
    mat = preenche_mat(mat, tam_l, tam_c);
    imprime_mat(mat, tam_l, tam_c);
    mat_u = tamanho_mat_u(mat_u, &tam_u_l, &tam_u_c);
    mat_u = preenche_mat_u(mat_u,tam_u_l,tam_u_c);
    imprime_mat_u(mat_u,tam_u_l,tam_u_c);

    return 0;
}

int **tamanho_mat(int **mat, int *tam_l, int *tam_c)
{
    int l, c, i;
    printf("\n Digite o tamanho de linhas da matriz: \n");
    scanf("%d", &l);
    printf("\n Digite o tamanho de colunas da matriz: \n");
    scanf("%d", &c);

    *tam_l = l;
    *tam_c = c;

    mat = (int **)malloc(l * sizeof(int *));
    if (mat == NULL)
    {
        printf(" \n Nao há memoria suficiente. \n");
        free(mat);
        exit(1);
    }
    else
    {

        for (i = 0; i < l; i++)
        {
            mat[i] = (int *)malloc(c * sizeof(int));
            if (mat[i] == NULL)
            {
                printf(" \n Nao há memoria suficiente. \n");
                free(mat[i]);
                exit(1);
            }
        }
    }

    return mat;
}
int **preenche_mat(int **mat, int l, int c)
{
    int i, j;
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("\nDigite mat[%d][%d] : ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    return mat;
}

int *tamanho_mat_u(int *mat_u, int *l_p, int *c_p)
{
    int i, l, c;

    printf("\n Digite o tamanho de linhas da matriz :");
    scanf("%d", &l);
    printf("\n Digite o tamanho de colunas da matriz :");
    scanf("%d", &c);

    *l_p = l;
    *c_p = c;

    mat_u = (int *)malloc(l * c * sizeof(int));
    if (mat_u == NULL)
    {
        printf(" \n Nao há memoria suficiente. \n");
        free(mat_u);

        exit(1);
    }
    return mat_u;
}

void imprime_mat(int **mat, int l, int c)
{
    int i, j;
    
    printf("\n-------------INICIO--MATRIZ--TRANSPOSTA-------\n\n");
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%5d", mat[i][j]);
        }
        printf("\n\n");
    }
    printf("\n-------------FIM--MATRIZ--TRANSPOSTA----------\n");
}

int * preenche_mat_u(int* mat_u,int l,int c)
{
    int i,j;

    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("\nDigite mat [%d][%d] :",i,j);
            scanf("%d",&mat_u[i*c+j]);
        }
    }

    return mat_u;

}

void imprime_mat_u(int* mat_u,int l,int c)
{
    int i,j;
    printf("\n-------------INICIO--MATRIZ--UNIDIMENSIONAL-------\n\n");
     for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%5d",mat_u[i*c+j]);
            
        }
        printf("\n\n");
    }
    printf("\n-------------FIM--MATRIZ--UNIDIMENSIONAL----------\n");
}
