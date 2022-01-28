#include <stdio.h>
#include <stdlib.h>

int main(){
	int *v;
	int n,i;
	float m;
	
	printf("Insira o números N de valores a calcular a média \n");
	scanf("%d",&n);
	v=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",&v[i]);
		m+=v[i];
	}
	printf("A média dos números é: %f",m/n);
	return 0;
}
