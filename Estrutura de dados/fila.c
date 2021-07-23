#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef	struct nodo{
	int dado;
	struct nodo *proximo;
	struct nodo *anterior;
}no;

int adicionar(no **inicio,no *aux,int valor){
	int erro=0;
	no *novo,*busca;
	if((novo=malloc(sizeof(no)))==NULL)erro=1;
	else {
		novo->dado=valor;
		if(*inicio!=NULL){
			(*inicio)->anterior=novo;
			novo->anterior=NULL;			
			*inicio=novo;
		}else{
			novo->proximo=aux->proximo;
			novo->anterior=aux;
			aux->proximo=novo;
			if((novo->proximo)!=NULL){
				novo->proximo->anterior=novo;
			}
		}
	}
	return erro;
} 

int removelista(no **lista,no *aux,int *valor){
	int erro=0;
	no *anterior, *busca;
	if((*lista)==NULL)erro=1;
	else{
		*valor=aux->dado;
		if(aux==*lista){
			*lista=aux->proximo;
			if((aux->proximo)!=NULL)(*lista)->anterior=NULL;
		}else{
			aux->anterior->proximo=aux->proximo;
			if((aux->proximo)!=NULL)aux->proximo->anterior=aux->anterior;
					
		}
		free(aux);
	}
	return erro;
} 

int mostra(no **lista){
		no *aux=(*lista);
 		//printf("\nLista:");
 		while(aux!=NULL){
  			printf("%d\n",(aux->dado));
  			aux=(aux->proximo);
		}	
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int m,n;
	no *v=NULL;
	no *x=NULL;
		do{
		//
			
			if(n==1){
	
					printf("Digite o número a listar\n");
					scanf("%d",&m);
					adicionar(&v,x,m);
				
			}
			else if(n==2){
					printf("Digite o número a remover da lista\n");
					scanf("%d",&m);
					removelista(&v,x,&m);
			}
			else if(n==3){
				
			
				 mostra(&v);
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
