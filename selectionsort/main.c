#include "lib.h"

#define TAM 5

int vetor[TAM] = {5,4,3,2,1};
int passos = 0;


void selectionSort(int vetor[], int tamanho){
	int i,j, temp;
	
	for(j= 0; j < tamanho - 1; j++){
		for(i = j + 1; i < tamanho; i++){
			if (vetor[j] > vetor[i]){
				temp = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = temp;
			}
		}
	}
}

void selectionSortEstavel(int vetor[], int tamanho){
	int i,j,menor,temp;
	
	for(j= 0; j < tamanho - 1; j++){
		menor = j;
		for(i = j + 1; i < tamanho; i++){
			if (vetor[menor] > vetor[i]){
				menor = i;
			}
		}
		if (menor != j){
			temp = vetor[menor];
			vetor[menor] = vetor[j];
			vetor[j] = temp;
		}
	}
}


void listarEst(int vetor[], int tamanho){
	int i;
	printf("\n\nListando\n\n");
	for (i=0; i < tamanho; i++)
		printf("[%d] -> %d\n",i,vetor[i]);
}

void selectionSortD(TRegistro * primeiro){
	int temp;
	TRegistro * atual, *proximo;
	for(atual = primeiro; atual->prox != NULL; atual = atual->prox){
		for(proximo = atual->prox; proximo != NULL; proximo = proximo->prox){
			if (atual->info > proximo->info){
				temp = atual->info;
				atual->info = proximo->info;
				proximo->info = temp;
			}
		}
	}
}

void selectionSortDEstavel(TRegistro * primeiro){
	int temp;
	TRegistro * atual, *proximo, * menor;
	for(atual = primeiro; atual->prox != NULL; atual = atual->prox){
		menor = atual;
		for(proximo = atual->prox; proximo != NULL; proximo = proximo->prox){
			if (menor->info > proximo->info){
				menor = proximo;
			}
		}
		if (menor != atual){
			temp = menor->info;
			menor->info = atual->info;
			atual->info = temp;
		}
	}
}

int main(int argc, char **argv)
{
	/*
	listarEst(vetor,TAM);
	selectionSortEstavel(vetor,TAM);
	listarEst(vetor,TAM);
	*/
	
	new(5);
	new(4);
	new(3);
	new(2);
	new(1);
	listar();
	selectionSortDEstavel(inicio);
	listar();
	
	
	

	
	return 0;
}


