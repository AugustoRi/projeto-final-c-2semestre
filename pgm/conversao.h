#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAM 3

// PROTÓTIPOS
void preencherMatriz(int *p);
void imprimirMatriz(int *p);
void verificarMatriz(unsigned char *, unsigned char *);
int converterBinario(unsigned char *bin, unsigned char *p);

struct Matriz {
  int col;
  int lin;
  int *p_matriz;
};