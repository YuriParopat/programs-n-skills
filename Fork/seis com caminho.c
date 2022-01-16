#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int temCaminho(int **G,int n,int vt1,int vt2,int **v2,int *k){
	int erro=1,i,j,v1[n],l=0;
	if(G[vt1][vt2]==1){
		erro=0;				
	}else{
		for(i=0;i<n;i++){
			if(G[vt1][i]==1){
				v1[l]=i;
				l++;
			}
		}
		for(i=0;i<l;i++){
			for(j=0;j<n;j++){//if(G[v1[i]][j]==G[vt2][i])
				if(temCaminho(G,n,v1[i],vt2,v2,k)==0){
					 *v2[*k]=v1[i];
					 *k++;
				}
			}
		}
	}
	return erro;
}
void caminho(int **G,int n,int vt1,int vt2){
	int i,j,v1[n],*v2,h=0,k=0,l=1;
	v2=malloc(n*sizeof(int));
	if(temCaminho(G,n,vt1,vt2,&v2,&k)==0){
		printf("Seu caminho é: %d", vt1);
		for(i=0;i<k;i++)printf(" %d",v2[i]);
		printf(" %d", vt2);
	} 
	else printf("Não existe caminho!");
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
		caminho(G,v,r,r2);
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
