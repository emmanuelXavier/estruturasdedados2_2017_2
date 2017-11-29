#include "lib.h"

#define TAM 5

int vetor[TAM] = {5,4,3,2,1};

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

void insertionSortD(TRegistro * primeiro){
	int temp;
	TRegistro * atual, *anterior;
	for(atual = primeiro->prox; atual != NULL; atual = atual->prox){
		anterior = atual->ant;
		temp = atual->info;
		while ((anterior != NULL) && (anterior->info > temp)){
			anterior->prox->info = anterior->info;
			anterior = anterior->ant;
		}
		if (anterior != NULL)
			anterior->prox->info = temp;
		else
			primeiro->info = temp;
	}
}

int main(int argc, char **argv)
{
	/*
	listarEst(vetor,TAM);
	insertionSort(vetor,TAM);
	listarEst(vetor,TAM);
	*/
	
	new(5);
	new(4);
	new(3);
	new(2);
	new(1);
	listar();
	insertionSortD(inicio);
	listar();
	
	
	
	

	
	return 0;
}


