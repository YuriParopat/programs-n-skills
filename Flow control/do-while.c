#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL, "Portuguese");
    int i = 0;
    int y, z = 0;

    printf("Entre com cinco números inteiros\n");

	do{
		scanf("%d", &y);
        z += y;
		i++;
	}while(i < 5);
	
    printf("Soma dos números %d Média dos números %d \n", z, z/5) ;
    return 0;
}
