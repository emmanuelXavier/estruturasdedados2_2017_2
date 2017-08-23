#include "lib.h"

int main(int argc, char **argv)
{
	int n;
	
	
	
	while(1){
		printf("Informe o numero: ");
		scanf("%d",&n);
		if (n == 0)
			break;
		
		new(n);
		
	}	
	listar();
	
	return 0;
}

