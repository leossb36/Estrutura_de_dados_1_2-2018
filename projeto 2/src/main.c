#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define asphalt "../DataSet/asphalt/asphalt_01.txt"
#define max_size_ilbp 512
#define size_f 25

int col = 0;
int row = 0;

int *getFile(char *path);
int *calc_ILBP(int **matrix, int row, int col);
// double *glcm_direction(int direction[2], int* mat, int row, int col, int gray_level);



int main(int argc, char **argv){

	int **matrix, *ilbp;

	*matrix = getFile(asphalt);

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

int *calc_ILBP(int **matrix, int row, int col)
{
	// [2][3][7] 	s(x) >= 0 set (1), s(x) < 0 set(0)
	// [1][5][9]	ilbp(gc) = sum(0 -> 8) of s(gp - avg(gc))2^p, that gp = variant pixel
	// [8][4][6]
	//   			and avg(gc) = central pixel avarage - > (g0 + g1 + ... gc)/9
	// 		|
	//		|

	// ilbp describer:  (2 + 3 + 7 + 1 + 5 + 9 + 8 + 4 + 6)/9 = 5
	// s(x) - > [0][0][1]
	// 			[0][1][1] -> 001110100 -> unsigned
	// 			[1][0][0]

	// 	find the lowest bit in rotation of pixel
	// 	ex: 001001000 - > rotate -> 000100100 -> rotate -> 000010010 -> 000001001 = 9

	double avg = 0;
	int count = 0;
	int **submatrix;
	int binary[9] = {0};
	double decimal = 0;

	int *ilbp = (int *) calloc(max_size_ilbp, sizeof(int)); //max size of ilbp is 2^9 - 1, that 9 is the amount pixel of submatrix;

	if (ilbp == NULL) {
		printf("\nError: cannot alocate memory\n");
		exit(1);

	}

	for(int i = 0; i < 3; i++)
	{
		submatrix[i] = (int *) calloc(3, sizeof(int));
	}

	if (submatrix == NULL) {
		printf("\nError: cannot alocate memory\n");
		exit(1);
	}
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{

			if((i < row) && (i > 0) && (j < col) && (j > 0)) {
				submatrix[0][0] = matrix[i - 1][j - 1];
				submatrix[0][1] = matrix[i - 1][j];
				submatrix[0][2] = matrix[i - 1][j + 1];
				submatrix[1][0] = matrix[i][j - 1];
				submatrix[1][1] = matrix[i][j];
				submatrix[1][2] = matrix[i][j + 1];
				submatrix[2][0] = matrix[i + 1][j - 1];
				submatrix[2][1] = matrix[i + 1][j];
				submatrix[2][2] = matrix[i + 1][j + 1];
			}
			// now we need to get the lowest bin, 
			// but first we need compare average 
			// and the values between each them and set 0 or 1.
			for(int i = 0; i < 3; i++){
				for(int j = 0; i < 3; j++){
					avg += submatrix[i][j];
				}
			}

			avg /= 9;

			binary[0] = (submatrix[0][0] >= avg) ? 1 : 0;
			binary[1] = (submatrix[0][1] >= avg) ? 1 : 0; 
			binary[2] = (submatrix[0][2] >= avg) ? 1 : 0; 
			binary[3] = (submatrix[1][0] >= avg) ? 1 : 0; 
			binary[4] = (submatrix[1][1] >= avg) ? 1 : 0; 
			binary[5] = (submatrix[1][2] >= avg) ? 1 : 0; 
			binary[6] = (submatrix[2][0] >= avg) ? 1 : 0; 
			binary[7] = (submatrix[2][1] >= avg) ? 1 : 0; 
			binary[8] = (submatrix[2][2] >= avg) ? 1 : 0;
			
			
			// convert binary to decimal and make sum
			for (int i = 0; i < 9; i++){
				decimal += binary[i] * (double)(2^i);
			}
				
			// extracting the lowest binary

			int smaller = (int)decimal;
			
			for (int i = 0; i < 9; i++) {
				decimal = ((((int)decimal) >> 1) | (((int)decimal) << 8)) & 511;
				
				if ((int)decimal < smaller){
					smaller = (int)decimal;
				}

			}
			printf("binary vector: %d\n\n", binary[i]);
			*(ilbp + smaller);
		}
	}
	for(int i = 0; i < 3; i++)
		free(submatrix[i]);
			
	return ilbp;
}

// double *glcm_direction(int direction[2], int* mat, int row, int col, int gray_level) {

// }
