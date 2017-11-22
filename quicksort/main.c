#include "lib.h"

#define TAM 5

int vetor[TAM] = {5,4,3,2,1};

int separar(int vetor[], int inicio, int fim){
	int pivo = vetor[fim];
	int menores = inicio - 1;
	int atual,temp;
	for (atual = inicio; atual < fim; atual++){
		if (vetor[atual] < pivo){
			menores++;
			if (menores != atual){
				temp = vetor[atual];
				vetor[atual] = vetor[menores];
				vetor[menores] = temp;
			}
		}
	}
	menores++;
	temp = vetor[fim];
	vetor[fim] = vetor[menores];
	vetor[menores] = temp;
	
	return menores;	
}	

void quicksort(int vetor[], int inicio, int fim){	
	if (inicio < fim){
		int meio = separar(vetor,inicio,fim);
		quicksort(vetor,inicio, meio - 1);
		quicksort(vetor, meio + 1, fim);
	}
}

void insertionSort(int vetor[], int tamanho){
	int i,j, temp;
	for (i = 1; i < tamanho; i++){
		j = i - 1;
		temp = vetor[i];
		while ((vetor[j] > temp) && (j >= 0)){
			vetor[j + 1] = vetor[j];
			j--;
		}
		vetor[j + 1] = temp;	
	}
}



void listarEst(int vetor[], int tamanho){
	int i;
	printf("\n\nListando\n\n");
	for (i=0; i < tamanho; i++)
		printf("[%d] -> %d\n",i,vetor[i]);
}


int main(int argc, char **argv)
{
	
	listarEst(vetor,TAM);
	quicksort(vetor,0,TAM - 1);
	listarEst(vetor,TAM);
	
	return 0;
}


