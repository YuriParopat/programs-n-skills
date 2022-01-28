#include <stdio.h>
#include <stdlib.h>

int fib(int n){
	int f=1;
	if(n>2){
		f =fib(n-1)+fib(n-2);
	}
	return f;
}


int main(){
	int n;
	printf("Insira o número N\n");
	scanf("%d", &n);
	printf("O fibonacci de %d é: %d\n", n,fib(n));
	printf("Final do programa");
	return 0;
}
