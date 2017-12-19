
#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct SListaAdj{
    struct SVertice * vertice;
    struct SListaAdj * prox;
}TListaAdj;

typedef struct SVertice{
    int info;
    struct SVertice * prox;
    struct SListaAdj * listaAdj;
    _Bool visitado;  
}TVertice;

TVertice * inicio;
TVertice * fim;

//Busca semelhante ao de uma lista encadeada
TVertice * buscarVertice(int valor){
    TVertice * ultimo = inicio;
    while (ultimo != NULL){
        if (ultimo->info == valor)
            return ultimo;
        ultimo = ultimo->prox;
    }
    return NULL;
}

TVertice * adicionar(int informacao){
    TVertice * novo;
    //primeiro faz-se uma busca nos vértices e caso exista o vertice é retornado
    novo = buscarVertice(informacao);
    if (novo != NULL)
        return novo;
    
    //caso o vértica não exista o mesmo é criado
    novo = malloc(sizeof(TVertice));
    novo->info = informacao;
    novo->visitado = FALSE;
    //os campos prox e listaAdj  são nulos pois o vertice novo é ultimo e não  possui conexões
    novo->prox = novo->listaAdj = NULL;
    
    //Caso seja o primeiro vértice, a sentinela inicio guarda seu endereço, caso contrário o novo vértice é encadeado após o ultimo usando a referência fim
    if (inicio == NULL)
        inicio = novo;
    else
        fim->prox = novo;
    //atualiza a referencia fim para o endereço do novo vértice (ultimo)
    fim = novo;
    //retorno o endereço do novo vertice
    return novo;
}


void ligar(int valorVertice, int valorVertice2){
    
    TVertice * vertice, * vertice2;
		
	//tenta inserir novos vertices para os valores	
    vertice  = adicionar(valorVertice);
    vertice2 = adicionar(valorVertice2);
    
    //cria um item da lista de adjancencia do vertice
    TListaAdj * aresta = malloc(sizeof(TListaAdj));
    aresta->vertice = vertice2;
    aresta->prox = NULL;
    
    //pega a lista de adjacencia do vertice e caso ela não exista insere a aresta como o primeiro item da lista
    TListaAdj * lista = vertice->listaAdj;
    if (lista == NULL)
        vertice->listaAdj = aresta;
    else {
		//caso a lista exista, percorre-se até o ultimo item da lista e faz o encadeamento com aresta
        while (lista->prox != NULL)
            lista = lista->prox;
        lista->prox = aresta;
    }
}


void listar(){
    TVertice * ultimo = inicio;
    while (ultimo != NULL){
        printf("%d ",ultimo->info);
        ultimo = ultimo->prox;
    }
}

void profundidade(TVertice * vertice){
    if (vertice == NULL)
        return;
    //marcar o vértice como visitado
    vertice->visitado = TRUE;
    //imprime o informacao
    printf("%d ",vertice->info);
    //pega a lista de adjacencias do vertice atual
    TListaAdj * lista = vertice->listaAdj;
    //percorre toda a lista de adjacenci
    while (lista != NULL){
        //caso o vertice não tenha sido visitado, chama recursivamente função profundidade passando o vertice do item da lista de adjacencia
        if (lista->vertice->visitado == FALSE)
            profundidade(lista->vertice);
        //caso o vertice já tenha sido visitado, vai para o próximo item da lista de adjacencia
        lista = lista->prox;
    }
}

int main(int argc, char** argv) {
    
    int valor,valor2;
    
    while(1){
        scanf("%d,%d",&valor,&valor2);
        if (valor == 0)
            break;
        
        if (valor2 != 0)
            ligar(valor,valor2);
        else
            adicionar(valor);
    }
    
    profundidade(inicio);
    return (EXIT_SUCCESS);
}

