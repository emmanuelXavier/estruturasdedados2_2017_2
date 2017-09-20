#include <stdio.h>
#include <stdlib.h>

typedef struct Registro{
	int info;
	struct Registro * prox;
} TRegistro;

typedef struct Descritor{
	TRegistro * inicio;
	int qtd;
	TRegistro * fim;
} TDescritor;

TDescritor descritor;

void primeiro(int informacao){
	TRegistro * novo;
	novo =  malloc(sizeof(TRegistro));
	novo->info = informacao;
	novo->prox = NULL;	
	descritor.inicio = novo;
	descritor.fim = novo;
	descritor.qtd++;
}

void demais(int informacao){
	TRegistro * novo;
	novo =  malloc(sizeof(TRegistro));
	novo->info = informacao;
	novo->prox = descritor.inicio;
	descritor.inicio = novo;
	descritor.qtd++;
}

int estaVazia(){
	
	if (descritor.inicio == NULL)
		return 1;
	else
		return 0;		
}



void listar(){
	TRegistro * ultimo;	
	for (ultimo = descritor.inicio; ultimo != NULL; ultimo = ultimo->prox)
		printf("[%p] -> %d\n",ultimo,ultimo->info);
}
	
void new(int informacao){
	if (descritor.inicio == NULL)
		primeiro(informacao);
	else
		demais(informacao);		
}

void remover(){
	TRegistro * destroyer = descritor.inicio;
	descritor.inicio = descritor.inicio->prox;
	free(destroyer);
	descritor.qtd--;
}


