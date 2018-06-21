//Everton da Silva Coelho  101937
//Gabriel Borin Takahashi 101953
//Pedro Manhez Naresi 105615

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Celula Apontador;

typedef struct Celula{
    int id_page;
    int hit;
    int time;
    Apontador * proximo;
}TCelula;

typedef struct Lista{
    int tamanho;
    Apontador *primeiro;
    Apontador *ultimo;
    Apontador *posicao;
}TLista;

TLista *TLista_Inicia(){
    TLista *pLista = (TLista*)malloc(sizeof(TLista));
    pLista->primeiro=NULL;
    pLista->ultimo=NULL;
    pLista->tamanho=0;
    return pLista;
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

void TLista_Insere(TLista *pLista, TCelula *x){
    TCelula *novo = (TCelula*)malloc(sizeof(TCelula));
	novo=x;
    if(TLista_EhVazia(pLista)){ 
        novo->proximo=NULL;
        pLista->primeiro=novo;
        pLista->ultimo=novo;
        pLista->posicao=pLista->primeiro;
        
    }else{
        novo->proximo=NULL;
        pLista->ultimo->proximo=novo;
        pLista->ultimo=novo;
    }
    pLista->tamanho++;
}

TCelula* TLista_Retira(TLista *pLista){
    if(TLista_EhVazia(pLista)==1){
        printf("A lista nao possui elementos\n");
        return NULL;
    }if(pLista->primeiro==pLista->ultimo){
        TCelula *aux;
        aux=pLista->primeiro;
        TCelula *x;
        x=aux;
        free(aux);
        free(pLista);
        return x;
    }
    if(pLista->posicao->proximo==NULL){            //Quero tirar o ultimo da fila
        TCelula *anterior;
        anterior=pLista->primeiro;
        while(anterior->proximo!=pLista->posicao){
            anterior=anterior->proximo;
        }
        TCelula *aux;
        TCelula *x;
        aux=pLista->posicao;
        anterior->proximo=NULL;
        pLista->ultimo=anterior;
        pLista->posicao=pLista->primeiro;
        x=aux;
        free(aux);
        pLista->tamanho--;
        return x;
    
    }if(pLista->posicao==pLista->primeiro){          //Quero tirar o primeiro da fila
        TCelula  *aux;
        aux=pLista->primeiro;
        pLista->primeiro=aux->proximo;
        TCelula *x;
        x=aux;
        free(aux);
        pLista->posicao=pLista->primeiro;
        pLista->tamanho--;
        return x;
    }
    else
    {
        TCelula *anterior;
        anterior=pLista->primeiro;
        while(anterior->proximo!=pLista->posicao){
            anterior=anterior->proximo;
        }
        TCelula *aux;
        aux=anterior->proximo;
        anterior->proximo=aux->proximo;
        TCelula *x;
        x=aux;
        pLista->posicao=anterior->proximo;
        free(aux);
        pLista->tamanho--;
        return x;
    }
}

void printaLista(TLista *pLista){
	TCelula *aux = pLista->primeiro;
	do{
		printf("%d\n", aux->id_page);
		aux=aux->proximo;
	}while(aux!=pLista->primeiro);
}

int main(){    
    int n, k, i, j;
    scanf("%d", &n);
    TLista *lista = TLista_Inicia();
    TCelula auxinsere;
    TCelula *auxretira;
    
    for(i=0;i<n;i++){
        scanf("%d", &auxinsere.id_page);
        TLista_Insere(lista, &auxinsere);
    }
    
	printaLista(lista);
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