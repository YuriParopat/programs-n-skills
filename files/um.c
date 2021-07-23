#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fib(int n){
	int f=1;
	if(n>2){
		f =fib(n-1)+fib(n-2);
	}
	return f;
}


int main(){
	FILE *arq;
	arq = fopen("Fib.txt", "w");
	for(int i=1;i<20;i++){
		fprintf(arq,"%d\n", fib(i));
	}
	fclose(arq); 	
	return 0;
}
