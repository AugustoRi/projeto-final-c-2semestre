#include "functions.h"

void readPGMImage(struct pgm *pio, char *filename){
	FILE *fp;
	char ch;

	if (!(fp = fopen(filename,"r"))){
		perror("Erro.");
		exit(1);
	}

	if ( (ch = getc(fp))!='P'){
		puts("A imagem fornecida não está no formato pgm");
		exit(2);
	}
	
	pio->tipo = getc(fp)-48;
	
	fseek(fp,1, SEEK_CUR);

	while((ch=getc(fp))=='#'){
		while( (ch=getc(fp))!='\n');
	}

	fseek(fp,-1, SEEK_CUR);

	fscanf(fp, "%d %d",&pio->c,&pio->r);
	if (ferror(fp)){ 
		perror(NULL);
		exit(3);
	}	
	fscanf(fp, "%d",&pio->mv);
	fseek(fp,1, SEEK_CUR);

	pio->pData = (unsigned char*) malloc(pio->r * pio->c * sizeof(unsigned char));

	switch(pio->tipo){
		case 2:
			puts("Lendo imagem PGM (dados em texto)");
			for (int k=0; k < (pio->r * pio->c); k++){
				fscanf(fp, "%hhu", pio->pData+k);
			}
		break;
		case 5:
			puts("Lendo imagem PGM (dados em binário)");
			fread(pio->pData,sizeof(unsigned char),pio->r * pio->c, fp);
		break;
		default:
			puts("Não está implementado");
	}
	
	fclose(fp);

}

void getArray(unsigned char *array, int col, int lin) {
	//atualizar a matriz com os numeros binarios transformados em decimais
	//fazer um contador de frequencia com essa nova matriz
	/*
		1. inicializar o contador de frequencia em que no max 256(0->255) -> o valor inicial é 0 de todos
		2. com o contador de frequencia, eu vou pegar o numero gerado, e add no contador:
		ex: numero gerado: 255
		contador[numero_gerado] = contador[numero_gerado] + 1;

		contador de frequencia = [256 posicoes]
	*/

	/*
	CSV
	img1 -> mandar contador de frequencia + rotulo(filename[0])
	img2 -> mandar contador de frequencia + rotulo(filename[0])
	.
	.
	.
	*/
	puts("matriz gerada da primeira linha");
  for (int i = 0; i < col; i++) {
    unsigned char successor, up_successor, down_successor;
    unsigned char predecessor, up_predecessor, down_predecessor;
    unsigned char center = *(array + i), up_center, down_center = *(array + (i + col));
    
      up_predecessor = 0;
      up_successor = 0;
      up_center = 0;

      if (!i) {
        predecessor = 0;
        down_predecessor = 0;

        successor = *(array + (i + 1));
        down_successor = *(array + ( (i + 1) + col) );
      }

      if ( i && (i % (col - 1)) ) {
        predecessor = *(array + (i - 1));
        down_predecessor = *(array + ( (i - 1) + col) );

        successor = *(array + (i + 1));
        down_successor = *(array + ( (i + 1) + col) );
      }

      if ( i && !(i % (col - 1)) ) {
        predecessor = *(array + (i - 1));
        down_predecessor = *(array + ( (i - 1) + col) );
        
        successor = 0;
        down_successor = 0;
      }

      printf("\n\n");
      printf("%hhu | %hhu | %hhu \n", up_predecessor, up_center, up_successor);
      printf("%hhu | %hhu | %hhu \n", predecessor, center, successor);
      printf("%hhu | %hhu | %hhu \n", down_predecessor, down_center, down_successor);
      
    }

  puts("matriz gerada ate primeiro indice da ultima linha");
  int actualLine = 1;
  for (int j = col; j < (col * lin) - col; j++) {
    unsigned char successor, up_successor, down_successor;
    unsigned char predecessor, up_predecessor, down_predecessor;
    unsigned char center = *(array + j), up_center, down_center;

      if ( !(j % col) ) {
        up_predecessor = 0;
        predecessor = 0;
        down_predecessor = 0;

        up_center = *(array + (j - col));
        down_center = *(array + ( j + col));

        up_successor = *(array + ((j + 1) - col));
        successor = *(array + (j + 1));
        down_successor = *(array + ( (j + 1) + col) );
      }

      if ( j % (col) ) {
        up_predecessor = *(array + ( (j - 1) - col) );
        predecessor = *(array + (j - 1));
        down_predecessor = *(array + ( (j - 1) + col) );

        up_center = *(array + (j - col));
        down_center = *(array + (j + col));

        up_successor = *(array + ( (j + 1) - col) );
        successor = *(array + (j + 1));
        down_successor = *(array + ( (j + 1) + col) );
      }

      if ( !(j % (col + ( (col * actualLine) - 1) )) ) {
        up_predecessor = *(array + ( (j - 1) - col) );
        predecessor = *(array + (j - 1));
        down_predecessor = *(array + ( (j - 1) + col) );

        up_successor = 0;
        successor = 0;
        down_successor = 0;
        actualLine++;
      }

      printf("\n\n");
      printf("%hhu | %hhu | %hhu \n", up_predecessor, up_center, up_successor);
      printf("%hhu | %hhu | %hhu \n", predecessor, center, successor);
      printf("%hhu | %hhu | %hhu \n", down_predecessor, down_center, down_successor);
  }

  puts("matriz gerada da ultima linha");
  for (int k = (col * lin) - col; k < (col * lin); k++) {
    unsigned char successor, up_successor, down_successor;
    unsigned char predecessor, up_predecessor, down_predecessor;
    unsigned char center = *(array + k), up_center, down_center = *(array + (k + col));
    
		down_predecessor = 0;
		down_successor = 0;
		down_center = 0;
	
		if (!(k % ( (col * lin) - lin)) ) {
			up_predecessor = 0;
			predecessor = 0;

			up_center = *(array + (k - col));

			up_successor = *(array + ((k + 1) - col));
			successor = *(array + (k + 1));
		}

		if ( k % (col) ) {
			up_predecessor = *(array + ( (k - 1) - col) );
			predecessor = *(array + (k - 1));

			up_center = *(array + (k - col));

			up_successor = *(array + ( (k + 1) - col) );
			successor = *(array + (k + 1));
		}

		if ( !(k % ((col * lin) - 1 )) ) {
			up_predecessor = *(array + ( (k - 1) - col) );
			predecessor = *(array + (k - 1));

			up_successor = 0;
			successor = 0;
		}

		printf("\n\n");
		printf("%hhu | %hhu | %hhu \n", up_predecessor, up_center, up_successor);
		printf("%hhu | %hhu | %hhu \n", predecessor, center, successor);
		printf("%hhu | %hhu | %hhu \n", down_predecessor, down_center, down_successor);
		
	}
}

void writePGMImage(struct pgm *pio, char *filename){
	FILE *fp;
	char ch;

	if (!(fp = fopen(filename,"wb"))){
		perror("Erro.");
		exit(1);
	}

	fprintf(fp, "%s\n","P5");
	fprintf(fp, "%d %d\n",pio->c, pio->r);
	fprintf(fp, "%d\n", 255);

	fwrite(pio->pData, sizeof(unsigned char),pio->c * pio->r, fp);

	fclose(fp);

}

void viewPGMImage(struct pgm *pio){
	printf("Tipo: %d\n",pio->tipo);
	printf("Dimensões: [%d %d]\n",pio->c, pio->r);
	printf("Max: %d\n",pio->mv);

	for (int k=0; k < (pio->r * pio->c); k++){
		if (!( k % pio->c)) printf("\n");
		printf("%2hhu ",*(pio->pData+k));
	}	
	printf("\n");
}