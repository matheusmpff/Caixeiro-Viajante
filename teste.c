#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "item.h"
																								// incluir lista

int fatorial(n){
    int fatorial=1;
    for(int i=1;i<=n;i++){
        fatorial*=i;
    }

    return fatorial;
}

void permutacao(int seqfinal, )

void melhor_caminho(LISTA* distancias, int n, int seqfinal[]){

    int direcao[n];
    int distancia_final=0;
    for(int i=0;i<n;i++){
        direcao[i] =-1;
    }
    //-1 representar esquerda 1 representar direita
    int sequencia[n];

    for(int i=0;i<n;i++){
        sequencia[i]=i+1;
        seqfinal[i] = i+1;
    }

    for(int i=0;i<n-1;i++){
        int l = sequencia[i]-1;
        int c = sequencia[i+1]-1;

        ITEM * it_aux = listaPosicao(distancias,l);
        
        LISTA * linha = itemDadoGet(it_aux);

        it_aux = listaPosicao(linha,c);


        distancia_final += itemChaveGet(it_aux);


    }

    int l = sequencia[n-1]-1;
    int c = sequencia[0]-1;

    ITEM * it_aux = listaPosicao(distancias,l);
        
    LISTA * linha = itemDadoGet(it_aux);

    it_aux = listaPosicao(linha,c);

    distancia_final += itemChaveGet(it_aux);


    permutacao();
    






}




int main(){
	
    int n, i, i2, i3, j, k, djk, dtemp, dfinal, seqfinal[n], numtrajetos;	

    dtemp = 0;
    dfinal = 0;	

    printf("Numero de cidades: ");
    scanf("%d", &n);


    numtrajetos = fatorial(n);

    //int dist[n][n];

    LISTA *dist = listaCriar();

    for(int i = 0;i<n;i++){
        LISTA * aux = listaCriar();

        ITEM * aux_item = item_criar(i,aux);

        listaInserir(dist,aux_item,i);

    }

    


    //LISTA *ordem = lista_criar();

   // for (i = 0; i < n; i++)
   // lista_inserir(ordem, n);

  //  for (i = 0; i < (n(n-1))/2; i++){					// definindo as distancias
        
   // scanf("%d %d %d", &j, &k, &djk);	
   // dist[j-1][k-1] = djk;
   // dist[k-1][j-1] = djk;	
   // }

   

   for(i = 0; i < (n*(n-1))/2; i++){
        scanf("%d %d %d", &j, &k, &djk);

        ITEM * it_aux = listaBuscar(dist,j-1);
        LISTA * lista_aux = item_get_dados(it_aux);
        ITEM *distancia= item_criar(djk,NULL);

        listaInserir(lista_aux, distancia,k-1);

        ITEM * it_aux = listaBuscar(dist,k-1);
        LISTA * lista_aux = item_get_dados(it_aux);
        ITEM *distancia= item_criar(djk,NULL);

        listaInserir(lista_aux, distancia,j-1); 
    }

        
    /*for (i = 0; i < numtrajetos; i++){					// testando os trajetos e escolhendo o menor
                                                                                                    
    lista_ordenar(lista);																								
            
    for(i2 = 0; i2 < n-1; i2)
    dtemp = dtemp + dist[ordem[i2]][ordem[i2 + 1]];	
        
    dtemp = dtemp + dist[ordem[i2 - 1]][ordem[0]];	
                                                                                                    
    if(dtemp >= dfinal){
        
    dfinal = dtemp;	

    for (i3 = 0; i3 < n; i3++)
    seqfinal[i3] = ordem[i3]; 	
        
    }

    dtemp = 0;																									
        
        
    }*/

    melhor_caminho(dist,n, seqfinal);

    printf("Cidade de Origem: %d\n", seqfinal[0]);

    printf("Rota: ");

    for (i = 0; i < n; i++)
    printf("%d-", seqfinal[i]);

    printf("%d\n", seqfinal[0]);

    printf("Distancia: %d", dfinal);


return 0;	
	
}

