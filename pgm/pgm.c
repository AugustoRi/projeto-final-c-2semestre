#include "functions.h"
#include <dirent.h>
#include <string.h>

int main() {
	DIR *d;
	struct dirent *dir;
	d = opendir("./images/");
	struct pgm img;
	int index = 0;


	if (d) {
		while ((dir = readdir(d)) != NULL) {
      if (strcmp(".", dir->d_name) == 0 || strcmp("..", dir->d_name)== 0) 
				continue;
			strcpy(nomeArquivo[index], "./images/");
			strcat(nomeArquivo[index], dir->d_name);
			// printf("%s\n", nomeArquivo[index]);
			index++;
		}
		for (int i = 0; i < index; i++){
			readPGMImage(&img, nomeArquivo[i]);
			getArray(img.pData, img.c, img.r, nomeArquivo[i]);
		}
		closedir(d);
	}

	return 0;
}