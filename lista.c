#include <stdlib.h>
#include <stdio.h>
#include "item.h"
#include "lista.h"

struct lista_{
	ITEM *posicao[TAM_MAX];
	int inicio;
	int fim;
	int tamanho;
};

LISTA *listaCriar(void){
	LISTA *lista;
	lista = (LISTA *) calloc(1, sizeof(LISTA));
    if(lista != NULL){
        lista->inicio = 0;
        lista->fim = 0;
        lista->tamanho = 0;
    }
    return lista;
}

void listaApagar(LISTA **lista){
    if(*lista != NULL){
        free(*lista);
        *lista = NULL;
    }
    return;
}

bool listaCheia(LISTA *lista){
    if(lista->tamanho == TAM_MAX){
        return true;
    }
    return false;
}

bool listaVazia(LISTA *lista){
    if(lista->tamanho == 0){
        return true;
    }
    return false;
}

int listaTamanho(LISTA *lista){
    return lista->tamanho;
}

bool listaInserir(LISTA *lista, ITEM *item, int posicao){
    if(lista != NULL){
        lista->posicao[posicao] = item;
        return true;
    }
    return false;
}

ITEM *listaRemover(LISTA *lista, int posicao){
    if(lista != NULL){
        ITEM *aux = lista->posicao[posicao];
        lista->posicao[posicao] = NULL;
        return aux;
    }
    return NULL;
}

ITEM *listaPosicao(LISTA *lista, int posicao){
    if(lista != NULL){
        return lista->posicao[posicao];
    }
    return NULL;
}

void listaImprimir(LISTA *lista){
    if(lista != NULL){
        for(int i = 0; i <= lista->fim; i++){
            printf("Posição 1: chave -> %d\n", itemChaveGet(lista->posicao[i]));
        }
    }
    return;
}
