#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef	struct nodo{
	int dado;
	struct nodo *proximo;
}no;

int enf(no **inicio,no **fim,int valor){
	no *novo; 
	int erro=0;
	if((novo=malloc(sizeof(no)))==NULL)erro=1;
	else{
		novo->dado=valor;
		novo->proximo=NULL;
		if(*inicio==NULL){
			(*inicio)=(*fim)=novo;
		}else{
			(*fim)->proximo=novo;
			*fim=novo;
		}
	}
	return erro;
}

int desenf(no **inicio,no **fim,int *valor){
	no *aux; 
	int erro=0;
	if((*inicio)==NULL)erro=1;
	else{
		*valor=(*inicio)->dado;
		if(*inicio==*fim){
			*fim=NULL;
			//free(*inicio);
		}else{
			aux=*inicio;
			*inicio=aux->proximo;
			//free(aux);
		}
	}
	return erro;
} 

int mostra(no **fila){
	int erro=0;
	if((*fila)==NULL)erro=1;
	else{
		no *aux=(*fila);
 		//printf("\nLista:");
 		while(aux!=NULL){
  			printf("%d\n",(aux->dado));
  			aux=(aux->proximo);
		}	
	}	
	return erro;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int m,n;
	no *v=NULL;
	no *x=NULL;
		do{
		//
			
			if(n==1){
				printf("Digite o número a empilhar\n");
				scanf("%d",&m);
				if(enf(&v,&x,m)==1)printf("Erro na execução\n");
			}
			else if(n==2){
				if(desenf(&v,&x,&m)==1)printf("Erro na execução\n");
				else printf("Saída:%d \n",m);	
			}
			else if(n==3){
				if(mostra(&v)==1)printf("Fila vazia!\n");
			}
			else{
				printf("Essa opção não existe. Digite uma opção de 1 a 4.\n");
			}
			printf("Você deseja? \n1-Enfileirar, 2-Desenfileirar, 3-Mostrar a fila, ou 4-Sair?\n");
			scanf("%d",&n);
		}while(n!=4);
	//
	return 0;	
}
