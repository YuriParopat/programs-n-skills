#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL, "Portuguese");
    int i = 0;
    int y, z = 0;

    printf("Entre com cinco n�meros inteiros\n");

	do{
		scanf("%d", &y);
        z += y;
		i++;
	}while(i < 5);
	
    printf("Soma dos n�meros %d M�dia dos n�meros %d \n", z, z/5) ;
    return 0;
}
