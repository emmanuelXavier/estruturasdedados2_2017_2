#include <stdio.h>
#include <stdlib.h>

typedef struct Registro{
	int info;
	struct Registro * prox;
} TRegistro;

TRegistro * inicio = NULL, * ultimo = NULL;

void primeiro(int informacao){
	inicio =  malloc(sizeof(TRegistro));
	inicio->info = informacao;
	inicio->prox = NULL;
	ultimo = inicio;
}

void demais(int informacao){
	TRegistro * novo;
	novo =  malloc(sizeof(TRegistro));
	novo->info = informacao;
	novo->prox = NULL;
	
	/*ultimo = inicio;
	while (ultimo->prox != NULL)
		ultimo = ultimo->prox;*/
	
	ultimo->prox = novo;
	ultimo = novo;
}




void listar(){
	TRegistro * ultimo;	
	for (ultimo = inicio; ultimo != NULL; ultimo = ultimo->prox)
		printf("[%p] -> %d\n",ultimo,ultimo->info);
}
	
void new(int informacao){
	if (inicio == NULL)
		primeiro(informacao);
	else
		demais(informacao);		
}


TRegistro * primeiroNovo(){
	inicio =  malloc(sizeof(TRegistro));
	inicio->prox = NULL;
	return inicio;
}


TRegistro * demaisNovo(){
	TRegistro * novo,* ultimo;
	novo =  malloc(sizeof(TRegistro));
	novo->prox = NULL;
	
	ultimo = inicio;
	while (ultimo->prox != NULL)
		ultimo = ultimo->prox;
	
	ultimo->prox = novo;
	return novo;
}

TRegistro * novo(){
	if (inicio == NULL)
		return primeiroNovo();
	else
		return demaisNovo();		
}

void remover(){
	TRegistro * destroyer = inicio;
	inicio = inicio->prox;
	free(destroyer);
}


