#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int **mat, num1,num2;

    printf("Digite o valor desejado de linhas e colunas da matriz:\n");
    scanf("%d",&num1);
    scanf("%d",&num2);

    mat = malloc(num1 * num1 * sizeof(int*));

    for(int i = 0; i < num1; i++)
        mat[i] = malloc(num1 * num1 * sizeof(int));

    srand(time(NULL));

    for(int i = 0; i < num1; i++)
    {
        for(int j = 0; j < num2; j++)
        {
            mat[i][j] = rand() % 100;
        }    
    }

    for(int i = 0; i < num1; i++)
    {
        for(int j = 0; j < num2; j++)
            printf("|%d| ", mat[i][j]);
        printf("\n");
        
    }

    return 0;
}