#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define k 7

int H(int valor, int i,int n){
	int s;
	s=(valor+i)%n;	
	return s;
}

int endAberto(int v[],int n,int valor){
	int i=0,j,erro=0;
	j=H(valor,1,n);
	while((v[j]!=0)&&(i<n)){
		i++;
		j=H(valor,i,n);
	}
	if(i==n) erro=1;
	else v[j]=valor;
	return erro;
}

int posicao(int v[],int n,int valor){
	int i=0,erro=-1,r;
	for(i=0;i<n;i++){
		 if(v[i]==valor)erro=i;
	}return erro;
}

int main(){
	int *v;
	int valor,i,r,erro;
	if((v=malloc(k*sizeof(int)))==NULL)erro=1;
	else{
		for(i=0;i<k;i++)v[i]=0;
		printf("Seja bem vindo ao Insere Hash!\n");
		do{
			printf("Digite o valor que desaja inserir:"); 
			scanf("%d",&valor);
			if(endAberto(v,k,valor)==0)printf("\nO valor foi inserido na hash!\n");
			printf("Deseja realizar outra inserção? (1=S/0=N)");
			scanf("%d",&r); 
			printf("\n");
		}while(r!=0);
		do{
			printf("Deseja procurar algum valor?"); 
			scanf("%d",&r);
			if(r!=0){
				printf("Digite o valor: ");
				scanf("%d",&valor);
				printf("Ele está na posição: %d",posicao(v,k,valor));
		 	}
		}while(r!=0);
	}
		return erro;
}			
