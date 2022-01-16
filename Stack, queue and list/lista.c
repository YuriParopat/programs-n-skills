#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef	struct nodo{
	int dado;
	struct nodo *proximo;
}no;

int insere(no **lista,int valor){
	int erro=0;
	no *novo,*busca;
	if((novo=malloc(sizeof(no)))==NULL)erro=1;
	else {
		novo->dado=valor;
		if(*lista==NULL){
			novo->proximo=NULL;
			*lista=novo;
		}else{
			busca=*lista;
			if(valor<busca->dado){
				novo->proximo=busca;
				*lista=novo;
			}else{
				while((busca->proximo!=NULL)&&((busca->proximo->dado)<valor)){
					busca=busca->proximo;
					novo->proximo=busca->proximo;
					busca->proximo=novo;
				}
			}
		}
	}
	return erro;
} 

int removelista(no **lista,int valor){
	int erro=0;
	no *anterior,*busca;
	if((*lista)==NULL)erro=1;
	else if((*lista)->dado==valor){
		busca=*lista;
		*lista=busca->proximo;
		free(busca);
	}
	anterior=*lista;
	busca=(*lista)->proximo;
	while((busca!=NULL)&&(busca->dado!=valor)){
		anterior=busca;
		busca=busca->proximo;
	} 	
	if(busca==NULL)erro=2;
	else{
		anterior->proximo=busca->proximo;
		free(busca);
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
		do{
		//
			
			if(n==1){
	
					
					scanf("%d",&m);
					insere(&v,m);
				
			}
			else if(n==2){
					
					removelista(&v,m);
			}
			if(n==1){
				printf("Digite o número a listar\n");
				scanf("%d",&m);
				if(insere(&v,m)==1)printf("Erro na execução\n");
			}
			else if(n==2){
				printf("Digite o número a remover da lista\n");
				scanf("%d",&m);
				if(removelista(&v,m)==1)printf("Erro na execução\n");	
			}
			else if(n==3){
				if(mostra(&v)==1)printf("FILA vazia!\n");
			}
			else{
				printf("Essa opção não existe. Digite uma opção de 1 a 4.\n");
			}
			printf("Você deseja? \n1-Listar, 2-Remover um elemento específico da lista, 3-Mostrar a lista, ou 4-Sair?\n");
			scanf("%d",&n);
		}while(n!=4);
	//
	return 0;	
}
