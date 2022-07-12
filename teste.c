//SEM ESCOLHA DO TAMANHO DA MATRIZ
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int **mat;

    mat = malloc(3 * sizeof(int*));

    for(int i = 0; i < 3; i++)
        mat[i] = malloc(3 * sizeof(int));

    srand(time(NULL));

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            mat[i][j] = rand() % 100;
        }    
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++){
            printf("%d ", mat[i][j]);
        printf("\n");
        }
    }

    return 0;
}