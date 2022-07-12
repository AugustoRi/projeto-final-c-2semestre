#include "functions.h"
#include <dirent.h>

int main(int argc, char *argv[]) {
	DIR *d;
	struct dirent *dir;
	d = opendir("../datasets/oncotex_pgm");
	struct pgm img;

	if (d) {
		while ((dir = readdir(d)) != NULL) {
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	}

	if (argc!=3) {
		printf("Formato: \n\t %s <imagemEntrada.pgm> <imagemSaida.pgm>\n",argv[0]);
		exit(1);
	}

	readPGMImage(&img,argv[1]);

	writePGMImage(&img, argv[2]);

	viewPGMImage(&img);

	return 0;
}