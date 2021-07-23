#include <stdio.h>
#include <stdlib.h>

int Show(int a){
	if(a>1){
		Show(a-1);
	}
	printf("%d\n",a);
	return(a);
}

int main(){
	int n;
	printf("Insira o número N");
	scanf("%d", &n);
	Show(n);
	printf("Final do programa");
	return 0;
}
