#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int soma(int *a){
	int s=0;
	for (int i = 0; i <= 4; i++){
        	s=s+a[i];
    	}
	return s;

}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int num[4];
    int i ,y;
    printf("Insira cinco números \n");
    for (i = 0; i <= 4; i++){
        scanf("%d", &num[i]);
    }
 	printf("A soma dos vetores é: %d\n", soma(num));
    printf("Final do programa");
}
