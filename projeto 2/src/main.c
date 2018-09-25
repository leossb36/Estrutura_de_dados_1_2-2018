#include <stdio.h>
#include <stdlib.h>
#define asphalt "../DataSet/asphalt/asphalt_01.txt"
#define max_size_ilbp 512
#define size_f 25
int col = 0;
int row = 0;

int *getFile(char *path);
int *calc_ILBP(int *matrix, int row, int col);
double *glcm_direction(int direction[2], int* mat, int row, int col, int gray_level);



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
	// s(x) - > [0][0][1]
	// 			[0][1][1] -> 001110100 -> unsigned
	// 			[1][0][0]

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
			submatrix[0][0] = (i == 0 || j == 0) ? 0 : *(matrix + ((i - 1) * col) + (j - 1));
			submatrix[0][1] = (i == 1) ? 0 : *(matrix + ((i - 1) * col) + j);
			submatrix[0][2] = (i == 0 || j == (col - 1)) ? 0 : *(matrix + ((i - 1) * col) + (j + 1));
			submatrix[1][0] = (j == 0) ? 0 : *(matrix + (i * col) + (j - 1));
			submatrix[1][1] = *(matrix + ((i - 1) * col) + j);
			submatrix[1][2] = (j == (col - 1)) ? 0 : *(matrix + (i * col) + (j + 1));
			submatrix[2][0] = (i == (row - 1) || j == 0) ? 0 : *(matrix + ((i + 1) * col) + (j - 1));
			submatrix[2][1] = (i == (row - 1)) ? 0 : *(matrix + ((i + 1) * col) + j);
			submatrix[2][2] = (i == (row - 1) || j == (col - 1)) ? 0 : *(matrix + ((i + 1) * col) + (j + 1));

			for (int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++)
				{
					avg += submatrix[i][j];
				}
			}

			avg /= 9;
			// find the lowest bit
			// 010010000 -> rotation ... > 000001001 = 9;

			unsigned short lowest = 0;

			int x = 0, y = 0;
			// rotation path: 0.0 > 0.1 > 0.2 > 1.2 > 2.2 > 2.1 > 2.0 > 1.0 > 1.1;
			while(1){
				lowest = lowest << 1;

				if(submatrix[x][y] >= avg){
					lowest = lowest | 0x0001;
				}
				if(x == 1 && y == 1){
					break;
				}
				if((x == 0 || x == 1) && y != 2){
					y++;
					continue;
				}
				if(x != 2 && y == 2){
					x++;
					y = 2;
					continue;
				}
				if(x == 2 && y != 2){
					x = 2;
					y--;
					continue;
				}
				else{
					x = 1;
					y = 0;
				}
			}
			int lowest_bit = lowest;

			for(int k = 0; k < 9; k++){
				unsigned short modificado = lowest & 0x0100;
				modificado = modificado >> 8;

				lowest = lowest << 1;

				lowest = lowest | modificado;
				modificado = lowest & 0x01FF;

				if(lowest < lowest_bit){
					lowest_bit = lowest;
				}
			}

			*(ilbp + lowest_bit) += 1;

		}

	}
	// printf("binary vector: %d\n\n", *binary);
	return ilbp;
}

double *glcm_direction(int direction[2], int* mat, int row, int col, int gray_level){

	// 		1º to condition your REFERENCE DIRECTION: right, left, up, botton;
	// 		2º: Need to look, "What is the BIGGEST bit?; this bit "m" will be the size of the GLCM[m][m].
	// 		3º: "How many times does J happens on DIRECTION of I?",
	//
	//		Example:
	//		[1][2][4]	1º: the REFERENCE DIRECTION is right; 
	//  	[2][1][4]	2º: the size of the GLCM is 4, because [1][3] && [2][3] = 4, most BIGGEST bit;
	// 		[3][2][3]	3º: looking the GLCM position, you answer the question:
	// 					   	GLCM[1][1], How many times does j(1) happens on RIGHT of i(1)? = 0 -> GLCM[1][1] = 0;
	//						GLCM[1][2], How many times does j(2) happens on RIGHT of i(1)? = 2 => GLCM[1][2] = 1;
	//					 ...GLCM[4][4], How many times does j(4) happens on RIGHT of i(4)? = 0 => GLCM[4][4] = 0;
	//
	// 		Finally, GLCM is:
	// 		[0][1][0][1]
	//		[1][0][1][1]
	//		[0][1][0][0]
	//		[0][0][0][0]

}
