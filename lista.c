#include <stdlib.h>
#include <stdio.h>
#include "item.h"
#include "lista.h"

struct lista_h{
	ITEM *posicao[TAM_MAX];
	int inicio;
	int fim;
	int tamanho;
};

LISTA *listaCriar(void){
	LISTA *lista;
	lista = (LISTA *) calloc(sizeof(LISTA));

