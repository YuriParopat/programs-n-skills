#include <stdio.h>
#include <stdlib.h>

void simpl(int *divd,int *divs){
	int i;
	for(int i=2;i<*divs**divd;i++){
		int a = *divd%i;
		int b = *divs%i;
		if((a==0)&&(b==0)){
			*divd/=i;
			*divs/=i;
			i=1;		
		}		
	}
}

int main(){
	int dv,ds;	
	printf("Informe a fra��o x/y\n");
	scanf("%d/%d",&dv, &ds);
	simpl(&dv,&ds);
	printf("A fra��o simplificada �: %d/%d",dv,ds);	
	return 0;
}
