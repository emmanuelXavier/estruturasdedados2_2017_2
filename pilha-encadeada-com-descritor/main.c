#include "lib.h"

int main(int argc, char **argv)
{
	
	descritor.inicio = descritor.fim = NULL;
	int n,qtdRemover,i;
	
	while(1){
		printf("Informe o numero: ");
		scanf("%d",&n);
		if (n == 0)
			break;
			
		new(n);
		
		
	}	
	
	
	printf("Quantos elementos da fila deseja remover: ");
	scanf("%d",&qtdRemover);
	
	for(i = 1; i <= qtdRemover; i++)
		remover();
		
	listar();
	return 0;
}
