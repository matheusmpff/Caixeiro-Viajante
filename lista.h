#ifndef LISTA_H
	#define LISTA_H
	
	#include <stdbool.h>

	typedef struct lista_ LISTA;

	LISTA *listaCriar(void);
	void listaApagar(LISTA **lista);
	bool listaCheia(LISTA *lista);
	bool listaVazia(LISTA *lista);
	int listaTamanho(LISTA *lista);
	bool listaInserir(LISTA *lista, ITEM *item, int posicao);
	bool listaRemover(LISTA *lista, int posicao);
	ITEM *listaBuscar(LISTA *lista, int posicao);
	void listaImprimir(LISTA *lista);

#endif
