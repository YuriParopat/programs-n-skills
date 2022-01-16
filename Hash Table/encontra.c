#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef	struct nodo{
	int dado;
	struct nodo *proximo;
	struct nodo *anterior;
}no;

*no encontraHash(no *v[],int n,int valor){
	no *p;
	int i;
	i=valor%n;
	p=v[i];
	if(p!=NULL) while(((p->dado)!=valor)&&(p->proximo!=NULL)) p=p->proximo;
	if(p->dado}!=valor) p=NULL;
	return p;
}
