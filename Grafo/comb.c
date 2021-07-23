#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int *valor(int vetor[],int k,int i){
	int *va,l;
	va=malloc((k-1)*sizeof(int *));

	for(l=0;l<k-1;l++){
		va[l]=vetor[k];
	}


	return va;
}

void teste(int v[],int k,int l,int j){
	int i,s;
	if(l<k){	
		for(i=j+1;i<l;i++){
			for(s=0;s<k;s++)teste(v,k,l+1,i);
			printf("%d",v[i]);
		}
	if(i=k-1)printf("\n");	
	}
}


/*
1234

123
124
134
234


*/
int **comb(int vetor[], int k){
	int i,m,h,j,**v2;

	v2=malloc(k*sizeof(int *));
	for(i=0;i<k;i++) v2[i]=malloc((k-1)*sizeof(int));
	for(i=0;i<k;i++){
		for(j=0;j<k-1;j++) v2[i][j]=0;
	}

	for(i=0;i<k;i++){
		v2[i]=valor(vetor,k,i);
	}
	return v2;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int num[4],**v;
    int i,j,y;
    for (i = 0; i < 4; i++){
        num[i]=i;
    }
	/*v=malloc(4*sizeof(int *));
	for(i=0;i<4;i++) v[i]=malloc(3*sizeof(int));
	for(i=0;i<4;i++){
		for(j=0;j<3;j++) v[i][j]=0;
	}
	
	v=comb(num,4);
	for(i=0;i<4;i++){
		for(j=0;j<3;j++) printf("%d",v[i][j]);	
		printf("\n");
	}*/
	teste(num,4,2,-1);
    printf("\nFinal do programa");
}
