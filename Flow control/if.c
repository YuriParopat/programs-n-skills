#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL, "Portuguese");
    int x;
    int y, z = 0;
    float w = 0;

    printf("Digite um n�mero inteiro\n");

    scanf("%d", &y);


    if (y%2 == 0){
	
		printf("O n�mero � par\n") ;
	}else{
		printf("O n�mero � impar\n") ;
	}

	return 0;
}