#include <stdio.h>
#include <stdlib.h>
#define asphalt "../DataSet/asphalt/asphalt_01.txt"
#define max_size_ilbp 512
#define size_f 25
int col = 0;
int row = 0;

int *getFile(char *path);
int *calc_ILBP(int *matrix, int row, int col);



int main(int argc, char **argv){
	
	int *matrix, *ilbp;

	matrix = getFile(asphalt);

	ilbp = calc_ILBP(matrix, row, col);
	
	return 0;
}

int *getFile(char *path)
{
	FILE *fp;
	
	fp = fopen(path, "r");

	if(fp == NULL)
	{
		printf("\n\nError: Fail to open file!\n\n");
		exit(1);
	}

	if(row == 0)
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

		printf("\n\nlin: %d col: %d\n\n", row, col);
	}

	rewind(fp);

	int *matrix = (int *) calloc(row*col ,sizeof(int));

	for(int i = 0; i <= row; i++)
	{
		for(int j = 0; j <= col; j++)
			fscanf(fp, "%d;", matrix + i*col + j);
	}
	fclose(fp);

	return matrix;
}

int *calc_ILBP(int *matrix, int row, int col)
{
	// [2][3][7] 	s(x) >= 0 set (1), s(x) < 0 set(0)
	// [1][5][9]	ilbp(gc) = sum(0 -> 8) of s(gp - avg(gc))2^p, that gp = variant pixel
	// [8][4][6]
	//   			and avg(gc) = central pixel avarage - > (g0 + g1 + ... gc)/9
	// 		|
	//		|

	// ilbp describer:  (2 + 3 + 7 + 1 + 5 + 9 + 8 + 4 + 6)/9 = 5
	// s(x) - > [1][1][0]
	// 			[1][0][0] -> 110001011 -> unsigned
	// 			[1][0][1]

	// 	find the lowest bit in rotation of pixel
	// 	ex: 001001000 - > rotate -> 000100100 -> rotate -> 000010010 -> 000001001 = 9

	double avg = 0;
	int count = 0;
	int binaryVector[8] = {0};

	int *ilbp = (int *) calloc(max_size_ilbp, sizeof(int)); //max size of ilbp is 2^9 - 1, that 9 is the amount pixel of submatrix;

	if (ilbp == NULL) {
		printf("\nError: cannot alocate memory\n");
		exit(1);
	
	}
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{

			int submatrix[3][3];

			// we want do the path: (0,0)->(0,1)->(0,2)->(1,2)->(2,2)->(2,1)->(2,0)->(1,0)->(1,1)
			// find the lowest bit
			// 010010000 -> rotation ... > 000001001 = 9;

			unsigned short lowest = 0;		

		}
		
	}
	// printf("binary vector: %d\n\n", *binary);
	return ilbp;
}



