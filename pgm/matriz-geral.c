#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void matrizParaPercorrer(struct pgm *pio) {
	for (int k=0; k < (pio->r * pio->c); k++){
		if (!( k % pio->c)) printf("\n");
		printf("%2hhu ",*(pio->pData+k));
    }
    return 0;
}