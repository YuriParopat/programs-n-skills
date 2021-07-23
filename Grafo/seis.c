#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int temCaminho(int **G,int n,int s,int vt1,int vt2){
	int erro=1,i,v1[n],l=0;
	s++;
	if((s!=n)&&(vt1!=vt2){
		if(G[vt1][vt2]!=0){
			erro=0;				
		}else{	
			for(i=0;i<n;i++){
				if(G[vt1][i]==1)erro=temCaminho(G,n,s,G[vt1][i],vt2);
			}
		}
	}
	return erro;
}

int grMatriz(int **G){
	int v,r,r2,i,j,erro=0;
	printf("Informe o número de vétices\n");
	scanf("%d", &v);
	//*n=v;
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
		printf("\nInsira os vértice que você deseja verificar se há caminho\nV1=");
		scanf("%d",&r);
		printf("\nV2=");
		scanf("%d",&r2);
		if(temCaminho(G,v,0,r,r2)==0)printf("Existe caminho");
		else if(temCaminho(G,v,0,r,r2)==-1)printf("Erro de memória");
		else printf("Não existe caminho!");
		printf("\nDeseja repitir a pesquisa? (1=Sim/0=Não)\n");
		scanf("%d", &r);
	}while(r!=0);
	
	return erro;
}


int main(){
	setlocale(LC_ALL, "Portuguese");
	int **G;	
	
	printf("Seja bem vindo ao Construa um Grafo e descubra se há caminho entre dois vértices\n");	
	grMatriz(G);
	
}
