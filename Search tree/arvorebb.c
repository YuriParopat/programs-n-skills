#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef	struct nodo{
	int dado;
	struct nodo *esq;
	struct nodo *dir;
}no;

int insere(no **raiz,int valor){
	int erro=0;
	no *novo;
	if((*raiz)==NULL){
		if(((*novo)=malloc(sizeof(no)))!=NULL){
			novo->dado=valor;			
			novo->esq=novo->dir=NULL;
			*raiz=novo;
		}else erro=1;
	}else erro=buscainsere(*raiz,valor);
	
	return erro;
} 

int buscainsere(no *busca,int *valor){
	int erro=0;
	no *novo;
	if((busca->dado)>valor){
		if(busca->esq==NULL){
			if((novo=malloc(sizeof(no)))!=NULL){
				novo->dado=valor;
				novo->esq=novo->dir=NULL;
				busca->esq=novo
			}else erro=1;
		}else erro=buscainsere(busca->esq,valor);
	}else{		
		if(busca->dir==NULL){
			if((novo=malloc(sizeof(no)))!=NULL){
				novo->dado=valor;
				novo->esq=novo->dir=NULL;
				busca->dir=novo
			}else erro=1;
		}else erro=buscainsere(busca->dir,valor);
	}
	return erro;
} 

int mostra(no *p){
		printf("%d \n",p->dado);
 		if(p->esq!=NULL){
  			mostra(p->esq);
		}
		if(p->dir!=NULL){
  			mostra(p->dir);
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
