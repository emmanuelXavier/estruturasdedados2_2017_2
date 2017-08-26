#include "lib.h"
/*
int main(int argc, char **argv)
{
	int n,qtdRemover,i;
	
	while(1){
		printf("Informe o numero: ");
		scanf("%d",&n);
		if (n == 0)
			break;
		
		new(n);
		
	}	
	listar();
	
	printf("Quantos elementos da fila deseja remover: ");
	scanf("%d",&qtdRemover);
	
	for(i = 1; i <= qtdRemover; i++)
		remover();
		
	listar();
	return 0;
}*/


int main(int argc, char **argv)
{
	int i = 0;
	
	while(i++ <= 1000000000)	
		new(i);

	printf("Fila preenchida");
	return 0;
}


