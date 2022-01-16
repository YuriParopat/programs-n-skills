#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void print(const int *v, const int size)
{
  if (v != 0) {
    for (int i = 0; i < size; i++) printf("%d",v[i]);
    printf("\n");
  }
} // print


void visit(int *Value, int N, int k)
{
	int level = -1;
	level = level+1; Value[k] = level;

  	if (level == N)
		print(Value, N);
	else
    		for (int i = 0; i < N; i++) if (Value[i] == 0)  visit(Value, N, i);
	level -=1;
	Value[k] = 0;
}


int main()
{
  const int N = 4;
  int Value[N];
  for (int i = 0; i < N; i++) {
    Value[i] = i;
  }
  visit(Value, N, 0);
}	
