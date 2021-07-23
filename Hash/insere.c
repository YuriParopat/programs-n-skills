#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define k 7

typedef	struct nodo{
	int dado;
	struct nodo *proximo;
	struct nodo *anterior;
}no;

int remHash(no **v,int n,int valor){
	int erro=1;
	return erro;
}

int tabelaH(no **v,int n){
	int erro=1;
	return erro;
}

int insereHash(no **v,int n,int valor){
	int i,erro=0;
	i=valor%n;
	no *aux,*p;
	if((aux=malloc(sizeof(no)))!=NULL){
		aux->dado=valor;
		if(v[i]==NULL){
			v[i]=aux;	
			aux->proximo=NULL;
			aux->anterior=(v[i]);
	
		}else{				
			p=v[i];
			while(p->proximo!=NULL) p=p->proximo;
			aux->anterior=p;
			p->proximo=aux;
			aux->proximo=NULL;
		}	
	}else erro=1;
	return erro;
}

int main(){
	no **v;
	int valor,r,i;
	if((v=malloc(k*sizeof(no)))!=NULL){
		for(i=0;i<k;i++) v[i]=malloc(sizeof(no));
	}

	printf("Seja bem vindo ao Insere Hash!\n");
	do{
		printf("Você deseja inserir(1),ver(2),remover(3) ou sair(0)\n");
		scanf("%d",&r); 
		while(r==1){		
			printf("Digite o valor que desaja inserir:"); 
			scanf("%d",&valor);
			if(insereHash(v,k,valor)==0)printf("\nO valor foi inserido na hash!\n");
			printf("Deseja realizar outra inserção? (1=S/0=N)");
			scanf("%d",&r); 
		}
		while(r==2){		
			printf("Está é sua tabela: "); 
			tabelaH(v,k);
			printf("Deseja realizar outra verificação? (2=S)");
			scanf("%d",&r); 
		}
		while(r==3){		
			printf("Digite o valor que desaja remover:"); 
			scanf("%d",&valor);
			if(remHash(v,k,valor)==0)printf("\nO valor foi removido da hash!\n");
			printf("Deseja realizar outra remoção? (3=S)");
			scanf("%d",&r); 
		}
		
		printf("Deseja realizar outra intereção com a hash? (1=S/0=N)");
		scanf("%d",&r); 
	}while(r!=0);
	return 0;
}
