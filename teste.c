#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAM 3

// PROTÓTIPOS
void preencherMatriz(int matriz[TAM][TAM]);
void imprimirMatriz(int matriz[TAM][TAM]);
void verificarMatriz(int matriz[TAM][TAM]);

int main () {
  int matriz[TAM][TAM];
  preencherMatriz(matriz);
  printf("\nNúmero central: %d\n", matriz[1][1]);
  imprimirMatriz(matriz);
  printf("\n\n");
  verificarMatriz(matriz);
  imprimirMatriz(matriz);
}

void preencherMatriz(int matriz[TAM][TAM]) {
    srand(time(NULL));
    for (int j = 0; j < TAM; j++) {
      for (int k = 0; k < TAM; k++) {
        matriz[j][k] = rand() % 100;
      }
    }
}

void verificarMatriz(int matriz[TAM][TAM]) {
  for (int j = 0; j < TAM; j++) {
      for (int k = 0; k < TAM; k++) {
        if (matriz[j][k] < matriz[1][1]) {
          matriz[j][k] = 0;
        } else {
          matriz[j][k] = 1;
        }
    }
  }
}
void imprimirMatriz(int matriz[TAM][TAM]) {
  for (int j = 0; j < TAM; j++) {
    printf("\n");
      for (int k = 0; k < TAM; k++) {
        printf("%3d |", matriz[j][k]);
      }
    }
}