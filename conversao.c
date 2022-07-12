#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAM 3

// PROTÓTIPOS
void preencherMatriz(int *p);
void imprimirMatriz(int *p);
void verificarMatriz(int *p);
int converterBinario(int *bin, int *p);

struct Matriz {
  int col;
  int lin;
  int *p_matriz;
};

int main() {
  struct Matriz matriz;
  int *p_bin = NULL;
  matriz.col = TAM;
  matriz.lin = TAM;

  // === Alocando a matriz dinamicamente
  p_bin = malloc(sizeof(int) * 8);
  matriz.p_matriz = malloc(matriz.col * matriz.lin * sizeof(int));
  
  preencherMatriz(matriz.p_matriz);
  imprimirMatriz(matriz.p_matriz);
  printf("\n\n");

  verificarMatriz(matriz.p_matriz);
  imprimirMatriz(matriz.p_matriz);
  printf("Binario convertido para decimal: %d", converterBinario(p_bin, matriz.p_matriz));

}

void preencherMatriz(int *p) {
  srand(time(NULL));
  for (int i=0; i < TAM * TAM; i++){
        *(p + i) = rand() % 100;
  }
}

void verificarMatriz(int *p) {
  for (int j = 0; j < TAM * TAM; j++) {

      if (*(p + j) < *(p + 4)) {
        *(p + j) = 0;
      } else if (*(p + j) > *(p + 4)) {
        *(p + j) = 1;
      } else {
        *(p + j) = *(p + j);
    }
  }
}

void imprimirMatriz(int *p) {
  for (int j = 0; j < TAM * TAM; j++) {
    if (j % 3 == 0){
      printf("\n");
    }
      printf("%3d |", *(p + j));
  }
}

int converterBinario(int *bin, int *p) {
  int i = 0, decimal = 0, m = 1;
  //FUNCAO PARA PEGAR APENAS O BINARIO

  for (int j = 0; j < TAM * TAM; j++) {
      if (*(p + j) != *(p + 4)){
      *(bin + i) = *(p + j);
      i++;
      }
    } 
  //ORDENAÇAO DA MATRIZ

	// //primeiro for
  int a = 0;
  printf("\n\n");
	for (int j = 3; j < TAM * TAM; j += 3 ) {
		*(bin + a) = *(p + j);
    printf("%d ", *(bin + a));
		a++;
	}

	//segundo for
	for (int k = TAM * TAM - 2; k < TAM * TAM; k++) {
		*(bin + a) = *(p + k);
    printf("%d ", *(bin + a));
		a++;
	}

	//terceiro for 
	for (int l = TAM * TAM - 3; l > 0; l = l - 3) {
		*(bin + a) = *(p + l);
    printf("%d ", *(bin + a));
		a++;
	}

	//quarto for
	for (int h = 1; h >= 0; h -= 1) {
		*(bin + a) = *(p + h);
    printf("%d ", *(bin + a));
		a++;
	}

// ================
   printf("\n");
  // for(int r = 0; r < 8; r++) printf("%3d | ", bin[r]);


  //CONVERTER BINARIO PARA DECIMAL
  for(int a = 7; a > -1; a--){
    if( bin[a] == 1 ){
      decimal += bin[a] * m;
    }
    m *= 2;
  }
  return decimal;
}
