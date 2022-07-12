#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAM 3
#define MAX 3
// PROTÓTIPOS
void preencherMatriz(int **p);
void imprimirMatriz(int **p);
void verificarMatriz(int **p);
int converterBinario(int *bin, int **p);

int main() {
  int **p_matriz = NULL;
  int *p_bin = NULL;

  // === Alocando a matriz dinamicamente
  p_bin = malloc(sizeof(int) * 8);
  p_matriz = malloc(sizeof(int) * TAM);
  for (int i=0; i < TAM; i++){
   p_matriz[i] = malloc (TAM * sizeof (int));
  }
  
  preencherMatriz(p_matriz);
  imprimirMatriz(p_matriz);
  printf("\n\n");

  verificarMatriz(p_matriz);
  imprimirMatriz(p_matriz);
  printf("\n%d", converterBinario(p_bin, p_matriz));

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

int converterBinario(int *bin, int **p) {
  int i = 0, decimal = 0, m = 1;
  int v[8];
  //FUNCAO PARA PEGAR APENAS O BINARIO
  for (int j = 0; j < TAM; j++) {
    for (int k = 0; k < TAM; k++) {
      if (p[j][k] != p[1][1]){
      *(bin + i) = p[j][k];
      i++;
      }
    }
  } 
  //ORDENAÇAO DA MATRIZ MANUALMENTE
  v[0] = bin[3];
  v[1] = bin[5];
  v[2] = bin[6];
  v[3] = bin[7];
  v[4] = bin[4];
  v[5] = bin[2];
  v[6] = bin[1];
  v[7] = bin[0];

printf("\n\n");
  for(int r = 0; r < 8; r++) printf("%3d | ", v[r]);




  //CONVERTER BINARIO PARA DECIMAL
  for(int a = 7; a > -1; a--){
    if( v[a] == 1 ){
      decimal += v[a] * m;
    }
    m *= 2;
  }
  return decimal;
}

