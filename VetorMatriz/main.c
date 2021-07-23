#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int num[4];
    int i ,y;
    printf("Insira cinco números \n");
    for (i = 0; i <= 4; i++){
        scanf("%d", &num[i]);
    }
    printf("Números pares \n");
    for (i = 0; i <= 4; i++){
        y = num[i]%2;
        if(y==0){
            printf("%d \n", num[i]);
        }
    }
    printf("Final do programa");
}
