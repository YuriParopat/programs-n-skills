#include <stdio.h>
#include <stdlib.h>

int fat(int f){
	int k=1;
	if(f>1){
		k = f*fat(f-1);
	}
	return(k);
}

int main(){
	int n;
	printf("Insira o número N\n");
	scanf("%d", &n);
	printf("O fatorial de %d é: %d\n", n,fat(n));
	printf("Final do programa");
	return 0;
}
