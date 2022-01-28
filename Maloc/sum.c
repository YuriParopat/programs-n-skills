#include <stdio.h>
#include <stdlib.h>

int main(){
	float *n1,*n2;
	printf("Insira dois números a serem somados \n");
	n1=(float *) malloc(sizeof(float));	
	n2=(float *) malloc(sizeof(float));
	scanf("%f %f", n1,n2);
	printf("A soma dos números é: %f",*n1+*n2);
	return 0;
}
