#include <stdio.h>
#include <stdlib.h>
float **alloc_matr(float **, int);
void print_matr(float **, int);
int tamanho_setor();
void read_matr(float **, int);
struct empregado *calcula_total_funcionarios(int *);
void cadastra_funcionario(int, struct empregado *, float **, int);
float busca_salario(float setor, float **, int);
struct empregado
{
    int matricula;
    float setor;
    float salario;
};

int main()
{
    float **matr, *mat;
    int i, *p_tamanho, tamanho = 0, *p_total_funcionario, total_funcionario;
    struct empregado *funcionario;
    p_total_funcionario = &total_funcionario;
    tamanho = tamanho_setor();
    matr = alloc_matr(matr, tamanho);
    read_matr(matr, tamanho);
    print_matr(matr, tamanho);

    funcionario = calcula_total_funcionarios(p_total_funcionario);
    cadastra_funcionario(total_funcionario, funcionario, matr, tamanho);

    return 1;
}

int tamanho_setor()
{
    int tamanho;
    printf("\n Digite quantos setores haverao na tabela :\n");
    scanf("%d", &tamanho);
    return tamanho;
}
float **alloc_matr(float **matr, int tamanho)
{
    int i;

    matr = (float **)malloc(tamanho * sizeof(float *));
    if (matr == NULL)
    {
        printf("\n Nao ha memorio suficiente\n");
        free(matr);
        return 0;
    }
    for (i = 0; i < tamanho; i++)
    {
        matr[i] = (float *)malloc(2 * sizeof(float));
        if (matr[i] == NULL)
        {
            printf("\n Nao ha memorio suficiente\n");
            free(matr[i]);
            return 0;
        }
    }
    return matr;
}
void print_matr(float **matr, int tamanho)
{
    int i, j;
    printf("\n\n");

    for (i = 0; i < tamanho; i++)
    {

        for (j = 0; j < 1; j++)
        {
            printf("Setor : %-20.2f", matr[i][j]);
            printf(" Salario R$ : %-20.2f", matr[i][j + 1]);
        }
        printf("\n");
    }
}

void read_matr(float **matr, int tamanho)
{
    int i, j;

    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < 1; j++)
        {
            printf("\n Digite o setor :");
            scanf("%f", &matr[i][j]);
            printf("\n Digite o salario do setor %f :", matr[i][j]);
            scanf("%f", &matr[i][j + 1]);
        }
    }
}

struct empregado *calcula_total_funcionarios(int *total)
{

    int i;
    struct empregado *funcionario;
    printf("\n Digite o total de funcionarios");
    scanf("%d", &*total);
    for (i = 0; i < (*total); i++)
    {
        funcionario = (struct empregado *)malloc(*total * sizeof(struct empregado));
        if (funcionario == NULL)
        {
            printf(" Nao ha memoria suficiente \n");
            free(funcionario);
            return 0;
        }
    }
    return funcionario;
}

void cadastra_funcionario(int total, struct empregado *funcionario, float **matr, int tamanho)
{

    int i, matricula;
    float setor;
    for (i = 0; i < total; i++)
    {
        printf("\ndigite a matricula do funcionario %d :", i);
        scanf("%d", &matricula);
        funcionario[i].matricula = matricula;
        printf("\nDigite o setor do funcionario :");
        scanf("%f", &setor);
        funcionario[i].setor = setor;
        funcionario[i].salario = busca_salario(setor, matr,tamanho);
    }

    for (i = 0; i < total; i++)
    {
        printf("\n Matricula : %d   Setor : %f  Salaraio : %f", funcionario[i].matricula, funcionario[i].setor,funcionario[i].salario);
    }
    printf("\n");
}

float busca_salario(float setor, float **matr, int tamanho)
{
    int i, j=0;
    float achou;

    for (i = 0; i < tamanho; i++)
    {

        if (matr[i][j] == setor)
        {
            return matr[i][j+1];
        }
    }
}