#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define TAM 3

// PROTÓTIPOS
void preencherMatriz(int **p);
void imprimirMatriz(int **p);
void verificarMatriz(int **p);
void converterBinario(int *bin, int **p);

int main() {
  int **p_matriz = NULL;
  int *p_bin = NULL;

  // ===Alocando a matriz dinamicamente
  p_bin = malloc(sizeof(int) * 8);
  p_matriz = malloc(sizeof(int) * TAM);
  for (int i=0; i < TAM; i++){
   p_matriz[i] = malloc (TAM * sizeof (int));
  }
  
  preencherMatriz(p_matriz);
  printf("\nNúmero central: %d\n", p_matriz[1][1]);
  imprimirMatriz(p_matriz);
  printf("\n\n");
  
  //converterBinario(p_bin, p_matriz);
  // verificarMatriz(p_matriz);
  // imprimirMatriz(p_matriz);

}

void preencherMatriz(int **p) {
  srand(time(NULL));
  for (int i=0; i < TAM; i++){
    for (int j=0; j < TAM; j++){
        p[i][j] = rand() % 100;
    }
  }
}

void verificarMatriz(int **p) {
  for (int j = 0; j < TAM; j++) {
    for (int k = 0; k < TAM; k++) {
      if (p[j][k] < p[1][1]) {
        p[j][k] = 0;
      } else if (p[j][k] > p[1][1]) {
        p[j][k] = 1;
      } else {
        p[j][k] = p[j][k];
      }
    }
  }
}

void imprimirMatriz(int **p) {
  for (int j = 0; j < TAM; j++) {
    printf("\n");
    for (int k = 0; k < TAM; k++) {
      printf("%3d |", p[j][k]);
    }
  }
}

void converterBinario(int *bin, int **p) {
  for (int j = 0; j < TAM; j++) {
    for (int k = 0; k < TAM; k++) {
        bin[j+k] = p[j][k];
      }
    }
  for (int a = 0; a < 8; a++) {
    printf("%2d |", bin[a]);}
}
  // 	for (int i = 8-1; i >= 0; i--) {
	// 	printf("%d|", bin[i]);
	// 	if (bin[i] == 1) {
	// 		novoValor += pow(2, 8-1-i);
	// 	}
  // }