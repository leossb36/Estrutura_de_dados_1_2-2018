#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv){
	FILE *fp;
	char texto[1025][4085];
	char arquivo[] = "/home/bruno/Documentos/Estrutura_de_Dados/Projetos/Estrutura_de_dados_2_2018/projeto 2/data/DataSet/asphalt/asphalt_01.txt";
	fp = fopen(arquivo, "r");

	if (fp==NULL) {
		printf("Falha.\n");
		exit(1);
	}
	else{
		for(int i=1; i<=1025;i++){
			for(int j=1; j<=4085;j++){
				fscanf(fp, "%c", &texto[i][j]);
				printf("%c", texto[i][j]);
			}	
		}
	}
	return 0;
}