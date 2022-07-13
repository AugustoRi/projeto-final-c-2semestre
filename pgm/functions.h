#include <stdio.h>
#include <stdlib.h>

struct pgm {
	int tipo;
	int c;
	int r;
	int mv;
	unsigned char *pData;
};

void readPGMImage(struct pgm *, char *);
void getArray(unsigned char *, int, int);
void viewPGMImage(struct pgm *);
void writePGMImage(struct pgm *, char *);