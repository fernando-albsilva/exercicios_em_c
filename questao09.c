#include <stdio.h>
#include <stdlib.h>

int **aloca_mat(int **, int);
void dimensao_mat(int *);
void read_mat(int **, int);
void print_mat(int **, int);
void busca_mat(int **, int);

int main()
{
    int **mat, *p_n;
    int n;

    p_n = &n;
    dimensao_mat(p_n);
    printf("\n A dimensao da matris quadrada sera = %d", n);
    mat = aloca_mat(mat, n);
    read_mat(mat, n);
    print_mat(mat, n);
    busca_mat(mat, n);

    return 0;
}
void dimensao_mat(int *p_n)
{

    printf("Digite a dimensao da matriz quadrada \n");
    scanf("%d", &*p_n);
}
int **aloca_mat(int **mat, int n)
{
    int i;

    mat = (int **)malloc(n * sizeof(int *));
    if (mat == NULL)
    {
        printf(" Nao ha memoria suficiente");
        free(mat);
        exit(1);
    }
    for (i = 0; i < n; i++)
    {
        mat[i] = (int *)malloc(n * sizeof(int));
        if (mat[i] == NULL)
        {
            printf(" Nao ha memoria suficiente");
            exit(1);
        }
    }
    return mat;
}

void read_mat(int **mat, int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j > i)
            {
                mat[i][j] = 0;
            }
            else
            {

                printf("\n Digite mat[%d[%d] =", i, j);
                scanf("%d", &mat[i][j]);
            }
        }
    }
}
void print_mat(int **mat, int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf(" %6d ", mat[i][j]);
        }
        printf("\n");
    }
}

void busca_mat(int **mat, int n)
{
    int busca, i, j, teste = 0;
    do
    {
        printf("\nDigite um valor inteiro para ser pesquisado se o mesmo se encontra na matriz oi digite 0 para sair");
        scanf("%d", &busca);

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (j <= i)
                {
                    if (busca == mat[i][j])
                    {
                        printf("\n O numero %d buscado se encontra na posiçao mat[%d][%d] \n", busca, i, j);
                        teste = 1;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        if (teste == 0)
        {
            printf("\n Numero nao se encontra na matriz");
        }
        teste = 0;
    } while (busca != 0);
}