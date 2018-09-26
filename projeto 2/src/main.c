#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define asphalt "../DataSet/asphalt/asphalt_"
#define grass "../DataSet/grass/grass_"
#define max_size_ilbp 512
#define size_f 25

int col = 0;
int row = 0;	

char *getFileFormat(char *path, int id, char *postfix);
int *getFile(char *path);
int *calcILBP(int *matrix, int row, int col);
int getLowestBin(int binary);
void maxAndMin(int *max, int *min, double *concatenateVector, int size);
double *glcmDirection(int direction[2], int* matrix, int row, int col);
double *glcmMatrix(int *matrix, int row, int col);
double *normalizedVector(double *concatenateVector, int size, int *max, int *min);

int main(int argc, char **argv){

	int *matrix, *ilbp;
	char *teste;

	teste = getFileFormat(asphalt, 1, ".txt");//Need to change the variable name

	matrix = getFile(teste);

	ilbp = calcILBP(matrix, row, col);

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

char *getFileFormat(char *path, int id, char *postfix){
	
	char *fileformat = (char *) calloc((strlen(path) + strlen(postfix) + 12), sizeof(char));

	if (fileformat == NULL) {
		printf("\nError: cannot alocate memory\n");
		exit(1);
	}
	
	char buffer[12] = { 0 };
	sprintf(buffer, "%02d", id);

	strcat(fileformat, path);
	strcat(fileformat, buffer);       
	strcat(fileformat, postfix);

	printf("\nFilename: %s\n", fileformat);

	return fileformat;
}

int *calcILBP(int *matrix, int row, int col)
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
	
	unsigned int lowestBin = 0;
	int binary[9] = {0};
	double avg = 0;
	int decimal = 0;
	
	int *ilbp = (int *) calloc(max_size_ilbp, sizeof(int)); //max size of ilbp is 2^9 - 1, that 9 is the amount pixel of submatrix;

	if (ilbp == NULL) {
		printf("\nError: cannot alocate memory\n");
		exit(1);
	}

	for(int i = 0; i <= row; i++){
		for(int j = 0; j <= col; j++){
			// setting the initial value of matrix as center
			int submatrix[3][3];

			submatrix[0][0] = (i == 0 || j == 0) ? 0 : *(matrix + ((i - 1) * col) +(j - 1));
			submatrix[0][1] = (i == 0 || j == 1) ? 0 : *(matrix + ((i - 1) * col) + j);
			submatrix[0][2] = (i == 0 || j == 2) ? 0 : *(matrix + ((i - 1) * col) +(j + 1));
			submatrix[1][0] = (i == 1 || j == 0) ? 0 : *(matrix + (i * col) + (j - 1));
			submatrix[1][1] = (i == 1 || j == 1) ? 0 : *(matrix + (i * col) + j);
			submatrix[1][2] = (i == 1 || j == 2) ? 0 : *(matrix + (i * col) +(j + 1));
			submatrix[2][0] = (i == 2 || j == 0) ? 0 : *(matrix + ((i + 1) * col) + (j - 1));
			submatrix[2][1] = (i == 2 || j == 1) ? 0 : *(matrix + ((i + 1) * col) + j);
			submatrix[2][2] = (i == 2 || j == 2) ? 0 : *(matrix + ((i + 1) * col) + (j + 1));
			

			for(int x = 0; x < 3; x++){
				for(int y = 0; y < 3; y++){
					avg += submatrix[x][y];
				}
			}

			avg = avg/9;

			binary[0] = (submatrix[0][0] >= avg) ? 1 : 0;
			binary[1] = (submatrix[0][1] >= avg) ? 1 : 0; 
			binary[2] = (submatrix[0][2] >= avg) ? 1 : 0; 
			binary[3] = (submatrix[1][0] >= avg) ? 1 : 0; 
			binary[4] = (submatrix[1][1] >= avg) ? 1 : 0; 
			binary[5] = (submatrix[1][2] >= avg) ? 1 : 0; 
			binary[6] = (submatrix[2][0] >= avg) ? 1 : 0; 
			binary[7] = (submatrix[2][1] >= avg) ? 1 : 0; 
			binary[8] = (submatrix[2][2] >= avg) ? 1 : 0;

			lowestBin = getLowestBin(*binary);

			*ilbp += lowestBin; 
		}
	}
	//printf("%d\n", *ilbp);
	return ilbp;
}

int getLowestBin(int binary)
{
	// extracting the lowest binary
	int lowest = binary;
			
	for (int i = 0; i < 9; i++) {
		binary = (binary >> 1) | (binary << 8) & 511;
		
		if (binary < lowest){
			lowest = binary;
		}

	}
	return lowest;
}

void maxAndMin(int *max, int *min, double *concatenateVector, int size)
{
	int tempMin = 0;
	int tempMax = *concatenateVector;

	for(int i = 0; i < size; i++) {
		if(*(concatenateVector + i) >= tempMax){
			tempMax = *(concatenateVector + i);
		}
		if (*(concatenateVector + i) <= tempMin){
			tempMin = *(concatenateVector + i);
		}
	}
	*max = tempMax;
	*min = tempMin; 
}

double *glcmDirection(int direction[2], int* matrix, int row, int col) {

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

	double energy = 0, contraste = 0, homog = 0;
	direction[2] -= 1;
	//Alocating memory for every direction
	double* glcm_matrix = (double*)calloc(pow(256, 2), sizeof(double));

	if(glcm_matrix == NULL){
		printf("\nError: cannot alocate memory\n");
		exit(1);
	}

	for(int i = 0; i < 256; i++){
		for(int j = 0; j < 256; j++){
			if(i + direction[0] >= row || j + direction[1] >= col || i + direction[0] < 0 || j + direction[1] < 0){
				continue;
			}
			int n = matrix[(i * col) + j];
			int m = matrix[(i + direction[0]) * col + (j + direction[1])];

			glcm_matrix[(n * 256) + m] += 1;
		}
	}

	double valor = *glcm_matrix;

	for(int i = 0; i < 256; i++){
   		for(int j = 0; j < 256; j++){
	      contraste += valor * pow(abs(i - j),2);
		  energy += pow(valor, 2);
		  homog += (valor /(1 + abs(i - j)));
	   }
	}

	double* metric = (double*)calloc(3, sizeof(double));

	metric[0] = contraste;
	metric[1] = energy;
	metric[2] = homog;

	free(glcm_matrix);
	return metric;
}

double *glcmMatrix(int *matrix, int row, int col) {
	double* glcm = (double*)calloc(24, sizeof(double));
	//We want to calculate glcm for every direction in a matrix.
	//We are putting x as a linear direction and y as a vertical direction,

	//Constant for putting all 24 metrics in GLCM;
	int m = 0;

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			int direction[2] = {i, j};

			if(i == 1 && j == 1){
				continue;
			}

			double *metric = glcmDirection(direction, matrix, row, col);

			for(int n = 0; n < 3; n++){
				glcm[m] = metric[n];
				m++;
			}
			
			free(metric);
		}
	}
	return glcm;

}

double *normalizedVector(double *concatenateVector, int size, int *max, int *min){
	int *vmax = max;
	int *vmin = min;
	double normalized[size];
	for(int i = 0; i < size; i++){
		normalized[i] = (size - vmin[i]) / (vmax[i] - vmin[i]);
	}
}