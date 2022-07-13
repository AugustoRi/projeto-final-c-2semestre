#include "functions.h"
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {
	DIR *d;
	struct dirent *dir;
	d = opendir("../datasets/oncotex_pgm");
	struct pgm img;

	if (argc!=2) {
		printf("Formato: \n\t %s <CSV>\n",argv[0]);
		exit(1);
	}

	if (d) {
		while ((dir = readdir(d)) != NULL) {
      if (strcmp(".", dir->d_name) == 0 || strcmp("..", dir->d_name)== 0) 
				continue;
			readPGMImage(&img, dir->d_name);
			getArray(img.pData, img.c, img.r);
			// percorrer matriz e substituir numeros centrais
			// contador 
		}
		closedir(d);
	}

	writePGMImage(&img, argv[1]);

	viewPGMImage(&img);

	return 0;
}