#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef	struct nodo{
	int dado;
	struct nodo *proximo;
}no;

int emp(no **topo,int valor){
	no *novo; 
	int erro=0;
	if((*topo)==NULL){	
		if(((*topo)=malloc(sizeof(no)))==NULL)erro=1;
		else{
			(*topo)->dado=valor;
			(*topo)->proximo=NULL;
		}
	}else{
		if((novo=malloc(sizeof(no)))==NULL)erro=1; //fiz o malloc pro novo, assim como o aux no desempilha, e não para o topo, pois o topo já existe, portanto, pra ele, o espaço na memória está alocado corretamente. 
		else{
			novo->proximo=*topo;
			*topo=novo;
			(*topo)->dado=valor;
		}
	}
	return erro;
}

int desemp(no **topo,int *valor){
	no *aux;
	int erro=0;
	if((*topo)==NULL) erro=1;
	else if((aux=malloc(sizeof(no)))!=NULL){
		aux=*topo;
		(*topo)=aux->proximo;
		(*valor)=aux->dado;
		//free(aux); tirei o free porque dava erro na memória "double free or corruption.....abortado(imagem de núcleo gravada)""
	}
	return erro;
} 

int mostra(no **pilha){
	int erro=0;
	if((*pilha)==NULL)erro=1;
	else{
		no *aux=*pilha;
 		printf("\nPILHA:");
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
		do{			
			if(n==1){
				printf("Digite o número a empilhar\n");
				scanf("%d",&m);
				if(emp(&v,m)==1)printf("Erro na execução\n");
			}
			else if(n==2){
				if(desemp(&v,&m)==1)printf("Erro na execução\n");
				else printf("Saída:%d \n",m);	
			}
			else if(n==3){
				if(mostra(&v)==1)printf("Pilha vazia!\n");
			}
			else{
				printf("Essa opção não existe. Digite uma opção de 1 a 4.\n");
			}
			printf("Você deseja? \n1-Empilhar, 2-Desempilhar, 3-Mostrar a pilha, ou 4-Sair?\n");
			scanf("%d",&n);
		}while(n!=4);
	return 0;	
}
