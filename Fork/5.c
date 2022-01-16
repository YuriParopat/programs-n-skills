#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void fClique(int **G, int k,int v[]){ 
	int i,j;
	for(i=0;i<k;i++){
		for(j=0;j<k;j++){
			if(G[v[i]][v[j]]==1) printf("%d ",v[i]); 
		}
		if(k==1) printf("%d",v[i]);
//caso o vértice tenha só uma aresta adjacente, é mostrado ela também
//k = quantidade de arestas adjacentes
	}
}
void cliqueM(int **G, int n, int vrt){
	int i,k=0,v[n],p=0;
	for(i=0;i<n;i++){
		if((G[vrt][i])==1){	
			v[k]=i;
			k++;
		}
	}	
	printf("\nSeu maior clique é: %d ", vrt);
	fClique(G,k,v);
}

int grMatriz(int **G){
	int v,r,i,j,erro=0;
	printf("Informe o número de vétices\n");
	scanf("%d", &v);
	if((G=malloc(v*sizeof(int*)))!=NULL){
	
		for(i=0;i<v;i++) G[i]=malloc(v*sizeof(int));
		for(i=0;i<v;i++) G[i][i]=0;
		for(i=0;i<v;i++){
			for(j=i+1;j<v;j++){
				printf("Existe uma aresta de %d para %d ?(1=Sim/0=Não)\n",i,j);
				scanf("%d", &r);
				if(r==1){		
					G[i][j]=1;
					G[j][i]=1;
				}
				else{
					G[i][j]=0;
					G[j][i]=0;
				}			
			}
		}
	}else{
		erro=1;
	}
	printf("este é seu garfo\n");
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			printf("%d",G[i][j]);
		}
		printf("\n");
	}
	
	do{
		printf("\nInsira o vértice que você deseja encontrar o maior clique\n");
		scanf("%d", &r);
		cliqueM(G,v,r);
		printf("\nDeseja repitir a pesquisa? (1=Sim/0=Não)\n");
		scanf("%d", &r);
	}while(r!=0);
	return erro;
}


int main(){
	setlocale(LC_ALL, "Portuguese");
	int **G;	
	
	printf("Seja bem vindo ao Construa um Grafo e descubra seu maior clique\n");	
	grMatriz(G);
}
