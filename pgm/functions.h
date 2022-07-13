#include <stdio.h>
#include <stdlib.h>
#define MAXF 1000
#define MAXN 100
#define TAMCHAR 256
struct pgm {
	int tipo;
	int c;
	int r;
	int mv;
	unsigned char *pData;
};
char nomeArquivo[MAXF][MAXN];
void readPGMImage(struct pgm *, char *);
void getArray(unsigned char *, int, int, char *);
void histogram(unsigned char *, int, int, unsigned char *);
void CSV (const unsigned char *, char);
void viewPGMImage(struct pgm *);
void writePGMImage(struct pgm *, char *);