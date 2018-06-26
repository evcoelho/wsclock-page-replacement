//Everton da Silva Coelho  101937
//Gabriel Borin Takahashi 101953
//Pedro Manhez Naresi 105615

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1023

typedef struct Item{
    int id_page;
    int hit;
    float time;
}TItem;

typedef struct Celula TApontador;

typedef struct Celula{
    TItem item;
    TApontador *proximo;
    TApontador *anterior;
}TCelula;

typedef struct Lista{
    int tamanho;
    TApontador *frente;
}TLista;

void TLista_Inicia(TLista *lista){
    lista->tamanho=0;
    TCelula *cabeca = (TCelula*) malloc(sizeof(TCelula));
    lista->frente=cabeca;
    cabeca->proximo=lista->frente;
    cabeca->anterior=lista->frente;
}

int TLista_Tamanho(TLista *pLista){
    return pLista->tamanho;
}

int TLista_EhVazia(TLista *pLista){
    if(pLista->tamanho == 0)
        return 1;
    else
        return 0;
}

int TLista_Insere(TLista *lista, TApontador *p, TItem x){
    if(TLista_Tamanho(lista)==MAX){
        return 0;
    }
    else{
        TCelula *novo = (TCelula*)malloc(sizeof(TCelula));
    	novo->item=x;
        novo->proximo=p;
        novo->anterior=p->anterior;
        p->anterior->proximo=novo;
        p->anterior=novo;
        lista->tamanho++;
        return 1;
    }
}

int TLista_Retira(TLista *lista, TApontador *p, TItem *x){
    if(TLista_EhVazia(lista)){
        printf("A lista nao possui elementos\n");
        return 0;
    }
    else{
        p=p->anterior;
        p->anterior->proximo=p->proximo;
        p->proximo->anterior=p->anterior;
        *x=p->item;
        free(p);
        lista->tamanho--;
        return 1;
    }
}

void printaLista(TLista *lista){
	TCelula *aux = lista->frente->proximo;
	while(aux!=lista->frente){
		printf("%d\t", aux->item.id_page);
        printf("%d\t", aux->item.hit);
        printf("%f\n", aux->item.time);
		aux=aux->proximo;
	}
}

int main(){    
    TLista lista;
    TLista_Inicia(&lista);
    
    TItem aux;
    TApontador *posicao;
    posicao=lista.frente->proximo;
    int i;
    for(i=1;i<=3;i++){
        aux.id_page=i*1000;
        aux.hit=i*10;
        aux.time=i*25.5;
        TLista_Insere(&lista, posicao, aux);
    }
    
	printaLista(&lista);
	/*
    while(lista->tamanho!=1){
        for(i=0;i<k;i++){
            if(lista->posicao->proximo==NULL){
                lista->posicao=lista->primeiro;
            }else
                lista->posicao=lista->posicao->proximo;
        }
        auxretira=TLista_Retira(lista);
        printf("%d\n", auxretira->id_page);
    }
    auxretira=TLista_Retira(lista);
    printf("%d\n", auxretira->id_page);*/
    return 0;
}