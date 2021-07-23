#include <stdio.h>
#include <stdlib.h>

int Bolha(int v[],int n){
	int i, j, aux;
	for(i=n-1;i>=1;i--){
		for(j=0;j<i;j++){
			if(v[j]>v[j+1]){
				aux = v[j];
				v[j]=v[j+1];
				v[j+1]=aux;
			}		
		}
	
	}
	printf("\nVetor ordenado: \n");
	for(int i=0;i<n;i++){
		printf("%d ",v[i]);		
	}
}

void buscaBinaria(int v[],int in,int f,int x){
	int a=0;
	if(in<f){
		int m=(in+f)/2;
		if(x==v[m]) printf("Número encontrado na posição: %d",a);
		if(x<v[m]){

			buscaBinaria(v,in,m-1,x);
		
		}
		if(x>v[m]) {
			buscaBinaria(v,m+1,f,x);
		}
	}else printf("Número NAO encontrado");
}

int insertionSort(int v[],int n){
	int i,j,aux;
	for(i=0;i<n;i++){
	int a =v[i];
		for(j=i-1;j>=0;j--){
			if(v[j]>a){
				v[j+1]=v[j];
				v[j]=a;
			}		
		}
	
	}
	printf("\nVetor ordenado: \n");
	for(int i=0;i<n;i++){
		printf("%d ",v[i]);		
	}
}

void merge(int v[],int i,int m,int f){
	int *e,*d,ne,nd,j,k,l;
	ne=m-i+1;
	nd=f-m;
	e=malloc(sizeof(int)*ne);
	d=malloc(sizeof(int)*nd);
	
	k=i;
	for(j=0;j<ne;j++){
		e[j]=v[k];
		k++;
	}
	for(j=0;j<nd;j++){
		d[j]=v[k];		
		k++;	
	}
	j=0;
	k=0;
	l=i;
	while((j<ne)&&(k<nd)){
		if(e[j]<d[k]){
			v[l]=e[j];
			j++;
		}else{
			v[l]=d[k];
			k++;
		}
		l++;
	}
	if(j<ne){
		while(j<ne){
			v[l]=e[j];
			j++;
			l++;
		}
	}else{
		while(k<nd){
			v[l]=d[k];
			k++;
			l++;
		}
	}
}

void mergeSort(int v[],int i,int f){
	if(i<f){
		int m=(f+i)/2;
		mergeSort(v,i,m);	
		mergeSort(v,m+1,f);
		merge(v,i,m,f);	
	}
	
}

int main(){
	int n,w,t,x;
	int m[17] = {11,7,2,6,15,12,2,0,4,9,10,1,3,20,5,3,1};
	int b[7] = {0,1,4,7,9,10,12};
	printf("O vetor é:\n");
	for(int i=0;i<17;i++){
			printf("%d, ",m[i]);		
		}
	printf("\nInsira 1-boobleSort, 2-InsertionSort, 3-mergeSort\n");
	scanf("%d",&w);
	if(w==1){
		printf("\nInsira o número N de índices \n");
		scanf("%d",&n);
		Bolha(m, n);
	}else if(w==2){
		printf("\nInsira o número N de índices \n");
		scanf("%d",&n);
		insertionSort(m,n);
	}else if(w==3){
		printf("\nInsira o primeiro índice do vetor\n");
		scanf("%d",&n);
		printf("\nInsira o último índice do vetor\n");
		scanf("%d",&t);
		mergeSort(m,n,t);
		for(int i=0;i<(t-n+1);i++){
			printf("%d, ",m[i]);		
		}
	}else if(w==4){
		printf("\nInsira o primeiro índice do vetor\n");
		scanf("%d",&n);
		printf("\nInsira o último índice do vetor\n");
		scanf("%d",&t);
		printf("\nInsira o número a ser buscado\n");
		scanf("%d",&x);
		buscaBinaria(b,n,t,x);
	}else printf("\nInsira o número 1, 2 3 ou 4");
	
	printf("\nFinal do programa");
	return 0;
}
