#include <stdlib.h>
#include <stdio.h>

#define TAM 1000

int vetor[TAM];// = {5,4,3,2,6};
int passos = 0;


void bubbleSort(int vetor[], int tamanho){
	int i,j, temp;
	
	for(j= 0; j < tamanho; j++){
		for(i = 0; i < tamanho - 1 ; i++){
			passos++;
			if (vetor[i] > vetor[i + 1]){
				temp = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = temp;
			}
		}
	}
}

void bubbleSortM(int vetor[], int tamanho){
	int i,j, temp;
	int ordenado;
	
	for(j= 0; j < tamanho - 1; j++){
		ordenado = 1;
		for(i = 0; i < tamanho - 1 - j; i++){
			passos++;
			if (vetor[i] > vetor[i + 1]){
				temp = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = temp;
				ordenado = 0;
			}
		}
		if (ordenado == 1){
			break;
		}
	}
}

void listar(int vetor[], int tamanho){
	int i;
	printf("\n\nListando\n\n");
	for (i=0; i < tamanho; i++)
		printf("[%d] -> %d\n",i,vetor[i]);
}


int main(int argc, char **argv)
{
	int i;
	for (i = 0; i < 1000; i++){
		vetor[i] = 1000 - i;
	}
	listar(vetor,TAM);
	bubbleSortM(vetor,TAM);
	listar(vetor,TAM);
	
	printf("Passos: %d",passos);

	
	return 0;
}


