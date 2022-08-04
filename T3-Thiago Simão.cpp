// Esse programa lê um arquvivo Produto.ent, armazena em uma struct com cod e ano. Após isso ele retorna os valorres ordenados por id e depois pelo ano com o número de troca feita por cada ordenação.
#include <stdio.h>
#include <iostream>
#include <fstream>
#define MAX 100
typedef struct // definição da struct
{
    int cod;
    int ano;

} REG;

int ordena(REG v[]) // ORDENAÇÃO PELO ID - SELECT SORT
{
    int i, j, menor, contCod = 0;
    REG troca;
    for (i = 0; i < MAX - 1; i++)
    {
        menor = i;
        for (j = i + 1; j < MAX; j++)
        {
            if (v[j].cod < v[menor].cod)
            {
                menor = j;
            }
            if (i != menor)
            {
                troca.cod = v[i].cod;
                troca.ano = v[i].ano;
                v[i].cod = v[menor].cod;
                v[i].ano = v[menor].ano;
                v[menor].cod = troca.cod;
                v[menor].ano = troca.ano;
            }
        }
        contCod++;
    }
    return contCod;
}

int ordena2(REG v[]) // ORDENAÇÃO PELO ANO - INSERT SORT
{
    int i, j, contAno = 0;
    REG aux;
    for (i = 0; i < MAX - 1; i++)
    {
        for (i = 0; i < MAX; i++)
        {
            aux.ano = v[i].ano;
            aux.cod = v[i].cod;
            for (j = i; j > 0 && aux.ano < v[j - 1].ano; j--)
            {
                v[j].ano = v[j - 1].ano;
                v[j].cod = v[j - 1].cod;
            }
            contAno++;
            v[j].ano = aux.ano;
            v[j].cod = aux.cod;
        }
    }
    return contAno;
}
int main()
{

    int cod, ano, cont, cont2;
    REG v[MAX];
    FILE *lerarq;
    lerarq = fopen("produtos.ent", "r"); // leitura do arquivo
    if (lerarq == NULL)
    {
        printf("Erro ao abrir o arquivo");
    }
    else
    {
        for (int i = 0; i < MAX; i++) // Alocação do arquivo lido na struct REG v[MAX]
        {
            fscanf(lerarq, "%d %d", &v[i].cod, &v[i].ano);
        }
        cont = ordena(v);
        for (int i = 0; i < MAX; i++)
        {

            printf("%d %d\n", v[i].cod, v[i].ano); // Print de todos os valores lidos ordenados pelo ID
        }

        printf("%d trocas ordenadas pelo id\n", cont); // número de trocas realizadas

        cont2 = ordena2(v);
        for (int i = 0; i < MAX; i++)
        {

            printf("%d %d\n", v[i].cod, v[i].ano); // Print de todos os valores lidos ordenados pelo ANO
        }

        printf("%d trocas ordenadas pelo ano \n", cont2); // número de trocas realizadas
    }
    fclose(lerarq);

    return 0;
}