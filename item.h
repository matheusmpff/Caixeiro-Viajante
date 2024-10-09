#ifndef ITEM_H
	#define ITEM_H
	
	#include <stdbool.h>

	typedef struct item_ ITEM;

	ITEM *itemCriar(int chave, void *comp);
	void itemApagar(ITEM **item);
	int itemChaveGet(ITEM *item);
	bool itemChaveSet(ITEM *item, int chave);
	void *itemDadoGet(ITEM *item);

#endif
