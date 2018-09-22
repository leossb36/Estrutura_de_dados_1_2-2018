#include <stdio.h>
#include <stdlib.h>
#define asphalt "../DataSet/asphalt/asphalt_01.txt"
int col = 0;
int row = 0;

int *getFile(char *path);

int main(int argc, char **argv){
	// FILE *fp;
	// char texto[1025][4085];
	// char arquivo[] = "";
	// fp = fopen(arquivo, "r");

	// if (fp==NULL) {
	// 	printf("Falha.\n");
	// 	exit(1);
	// }
	// else{
	// 	for(int i=1; i<=1025;i++){
	// 		for(int j=1; j<=4085;j++){
	// 			fscanf(fp, "%c", &texto[i][j]);
	// 			printf("%c", texto[i][j]);
	// 		}	
	// 	}
	// }
	return 0;
}

int *getFile(char *path)
{
	FILE *fp;
	
	fp = fopen(asphalt, "r");

	if(fp == NULL)
	{
		printf("\n\nError: Fail to open file!\n\n");
		exit(1);
	}

	if(col == 0)
	{
		char ch;
		int count = 1;

		while(feof(fp) == 0)
		{
			ch = fgetc(fp);

			if(count && ch == ';')
				col++;

			if(ch == '\n')
			{
				row++;
				count = 0;
			}
		}
		col += 1;
	}

	rewind(fp);

	int *matrix = (int *) calloc(row*col ,sizeof(int));

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			fscanf(fp, "%d;", matrix + (i * col) + j);
		}
	}
	fclose(fp);

	return matrix;
}
