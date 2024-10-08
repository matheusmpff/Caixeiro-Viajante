#include <stdlib.h>
#include "item.h"

struct item_h{
	int chave;
	void *dado;
};

ITEM *itemCriar(int chave, void *ptr){
	ITEM *novo_item;
	novo_item = (ITEM *) malloc(sizeof(ITEM));
	if(novo_item != NULL){
		novo_item->chave = chave;
		novo_item->dado = ptr;
	}
	return novo_item;
}

void itemApagar(ITEM **item){
	if((*item) != null){
		(*item)->dado = NULL;
		free(*item);
	}
	*item = NULL;
	return;
}

int itemChaveGet(ITEM *item){
	if(item != NULL){
		return item->chave;
	}
	exit(1);
}

bool itemChaveSet(ITEM *item, int chave){
	if(item != NULL){
		item->chave = chave;
		return true;
	}
	return false;
}

void *itemDadoGet(ITEM *item){
	if(item != NULL){
		return item->dado;
	}
	return NULL;
}

