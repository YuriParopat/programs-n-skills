#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *arq, *arq2, *arq3;
	int vet[9], dec[9];
	arq = fopen("vetor1.txt", "r");
	arq2 = fopen("vetor2.txt", "r");
	arq3 = fopen("saida.txt","w");
	int i=0;
	char line;
	for(i=0;i<=9;i++){
		fscanf(arq, "%d", &vet[i]);
	}
	for(i=0;i<=9;i++){
		fscanf(arq2, "%d", &dec[i]);
		vet[i]+=dec[i];	
	}
	for(i=0;i<=9;i++){
		fprintf(arq3,"%d\n", vet[i]);
	}
	return 0;
}
