#ifndef LISTA_H
	#define LISTA_H
	
	#include <stdbool.h>
    #define TAM_MAX 1000

	typedef struct lista_ LISTA;

	LISTA *listaCriar(void);
	void listaApagar(LISTA **lista);
	bool listaCheia(LISTA *lista);
	bool listaVazia(LISTA *lista);
	int listaTamanho(LISTA *lista);
	bool listaInserir(LISTA *lista, ITEM *item, int posicao);
	ITEM *listaRemover(LISTA *lista, int posicao);
	ITEM *listaPosicao(LISTA *lista, int posicao);
	void listaImprimir(LISTA *lista);

#endif
