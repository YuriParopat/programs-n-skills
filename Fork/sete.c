#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*int temCaminho(int **G,int n,int s,int vt1,int vt2,int *v2){
	int erro=1,i,v1[n],l;
	v2[s]=vt1;
	s++;
	if((vt1!=vt2)&&(s!=n)){
		if(G[vt1][vt2]==1){
			erro=0;				
		}else{	
			for(l=0;l<n;l++){
				for(i=0;i<n;i++){
					if(((G[vt1][i])==1)&&(v2[l]!=vt2)){	
						erro=temCaminho(G,n,s,G[vt1][i],vt2,v2);
					}
				}
			}			
		}
	}
	return erro;
}*/

int conexo(int **G, int n){
	int i,j,r=0,r2=0,erro=0;
	/*for(i=0;i<n-1;i++){
		for(j=i+1;j<n-1;j++) if(temCaminho(G,n,0,i,j,v2)==1)erro=1;
	}*/
	for(i=0;i<n;i++) r +=G[i][i+1];
	for(j=1;j<n;j++) r2 +=G[j][j-1];
	if(r==r2)erro=1;
	return erro;
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
	
		if(conexo(G,v)==0) printf("\nO grafo é conexo\n");
		else printf("\nO grafo não é Conexo!\n");
	return erro;
}


int main(){
	setlocale(LC_ALL, "Portuguese");
	int **G;	
	
	printf("Seja bem vindo ao Construa um Grafo e descubra se ele é conexo\n");	
	grMatriz(G);
}
