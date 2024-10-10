all: item lista
	gcc -o caixeiro item.o lista.o caixeiro.c -std=c99

item:
	gcc -c item.c -std=c99

lista:
	gcc -c lista.c -std=c99

run:
	./caixeiro

clean:
	rm item.o lista.o caixeiro
