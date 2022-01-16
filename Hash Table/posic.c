#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int posicao(no v[],int n,int valor){
	int i=0,erro=-1;
	for(i=0;i<n;i++) if(v[i]==valor) erro=i;
	return erro;
}
