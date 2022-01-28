#include <stdio.h>
#include <stdlib.h>

int main(){
	int rows,cols,i,j;

	printf("Isert the matrix NxM");
	scanf("%dx%d",&rows, &cols);
	
	int **mat = (int **)malloc(rows * sizeof(int*));
	for(int i = 0; i < rows; i++) 
		mat[i] = (int *)malloc(cols * sizeof(int));

	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
