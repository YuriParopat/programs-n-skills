#include <stdio.h>
#include <stdlib.h>

int trib(int n){
	int t=0;
	if(n==2){
		t=1;	
	}
	if(n>2){
		t = trib(n-1)+trib(n-2)+trib(n-3);
	}
	return(t);
}

int main(){
	int n;
	printf("Insira o número N\n");
	scanf("%d", &n);
	printf("O tribonacci de %d é: %d\n", n,trib(n));
	printf("Final do programa");
	return 0;
}
