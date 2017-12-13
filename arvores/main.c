#include "lib.h"

typedef struct SArvore{
	int info;
	struct SArvore * esq;
	struct SArvore * dir;
}TArvore;

TArvore * raiz;




void criarRaiz(){
	printf("Informe o valor da raíz: ");
	raiz = malloc(sizeof(TArvore));
	scanf("%d",&raiz->info);
	raiz->esq = raiz->dir = NULL;
}

void preencherArvore(TArvore * no){			
	TArvore * novo;
	int cont = 1;
	int leitura;
	
	if (no == NULL)
		return;

	
	while (cont <= 2){
		printf("Pai: %d\n Informe o valor: ",no->info);
		scanf("%d", &leitura);
		
		if (leitura == 0){
			cont++;
			continue;
		}
		
		novo = malloc(sizeof(TArvore));
		novo->info = leitura;
		novo->esq = novo->dir = NULL;
		
		if (cont == 1)
			no->esq = novo;
		else
			no->dir = novo;
		cont++;
	}
	
	preencherArvore(no->esq);
	preencherArvore(no->dir);
}


void preFixado(TArvore * no){
	if (no == NULL)
		return;
		
	printf("%d ",no->info);
	preFixado(no->esq);
	preFixado(no->dir);
}

void central(TArvore * no){
	if (no == NULL)
		return;
		
	central(no->esq);
	printf("%d ",no->info);
	central(no->dir);
}

void posFixado(TArvore * no){
	if (no == NULL)
		return;
		
	posFixado(no->esq);
	posFixado(no->dir);
	printf("%d ",no->info);
}


void preencherABB(TArvore * no, int informacao){
	TArvore * novo;
	
	if (no == NULL)
		return;
		
		
	if (informacao < no->info){
		if (no->esq == NULL){
			novo = malloc(sizeof(TArvore));
			novo->info = informacao;
			novo->esq = novo->dir = NULL;
			no->esq = novo;
		}else{
			preencherABB(no->esq, informacao);
		}
	}else{ 
		if (informacao > no->info){
			if (no->dir == NULL){
				novo = malloc(sizeof(TArvore));
				novo->info = informacao;
				novo->esq = novo->dir = NULL;
				no->dir = novo;
			}else{
				preencherABB(no->dir, informacao);
			}
		}else{
			printf("Esse valor ja existe.");
		}
			
		
		
	}	
}


TArvore * buscarABB(TArvore * no, int key){
	if (no == NULL)
		return NULL;
		
	if (no->info == key)
		return no;
	else if (key < no->info)
			return buscarABB(no->esq, key);
		 else
			return buscarABB(no->dir,key);
}



int main(int argc, char **argv)
{
	criarRaiz();
	
	int leitura;
	
	while(1){
		printf("Valor: ");
		scanf("%d",&leitura);
		if (leitura == 0)
			break;
			
		preencherABB(raiz,leitura);	
		
	}
	TArvore * posicao = buscarABB(raiz, 6);
	
	if (posicao == NULL)
		printf("Valor nao encontrado");
	else
		printf("Encontrado na posicao: %p",posicao);
	//preFixado(raiz);
	
	return 0;
}


