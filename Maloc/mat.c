#include <stdio.h>
#include <stdlib.h>

int main(){
	int **m;
	int l,c,i,j;

	scanf("%dx%d",&l, &c);
	*m=(int *)malloc(l*sizeof(int));	
	m=(int **)malloc(c*sizeof(int));
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			scanf("%d",m[i][j]);
			
		}
	}
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			printf("%d",&m[i][j]);
		}
	}
	return 0;
}
