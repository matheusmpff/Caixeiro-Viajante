#include <stdio.h>
#include "lista.h"
#include "item.h"

//acha qual posicao vai se mover no proximo passo da permutacao
int maiorMovelEncontrar(int *sequencia, int *direcao, int n);

//troca a posicao que ira se mover, na direcao que ela aponta
void posicaoMover(int posicao_maior, int *sequencia, int *direcao, int n);

//funcao para calcular a distancia equivalente a aquela permutacao (sequencia de cidades), adicionando a cidade inicial no fim e inicio
int caminhoCalcular(LISTA *distancias, int n, int cidade_inicial, int *sequencia);

//funcao que passa por todas as permutacoes do array de cidades, cada array indica um caminho.
//comeca com o array (2, 3, 4, 5, 6), no caso de seis cidades, com a cidade 1 sendo a inicial
//esse algoritmo se chama johnson-trotter
int cidadesPermutar(LISTA *distancias, int *seqfinal, int cidade_inicial, int n, int *sequencia);

int fatorial(int n)
{
    int fatorial = 1;
    for (int i = 1; i <= n; i++)
    {
        fatorial *= i;
    }

    return fatorial;
}

int maiorMovelEncontrar(int *sequencia, int *direcao, int n)
{
    int posicao_maior = -1;
    int maior = -1;
    //primeiro testamos os dois casos especiais, o primeiro elemento e o ultimo
    //eles nao podem se mover para a esquerda e direita, respectivamente.
    if (direcao[0] != -1 && sequencia[0] > sequencia[1])
    {
        posicao_maior = 0;
        maior = sequencia[0];
    }
    if (direcao[n - 2] != 1 && sequencia[n - 2] > sequencia[n - 3])
    {
        if (maior < sequencia[n - 2])
        {
            posicao_maior = n - 2;
            maior = sequencia[n - 2];
        }
    }
    //agora, passamos por todos os elementos, vendo se eles podem se movimentar, e pegamos o maior numero que conseguir
    for (int i = 1; i < n - 2; i++)
    {
        if ((direcao[i] == -1 && sequencia[i] > sequencia[i - 1]) || (direcao[i] == 1 && sequencia[i] > sequencia[i + 1]))
        {

            if (maior < sequencia[i])
            {
                posicao_maior = i;
                maior = sequencia[i];
            }
        }
    }

    return posicao_maior;
}

void posicaoMover(int posicao_maior, int *sequencia, int *direcao, int n)
{

    int maior = sequencia[posicao_maior];
    int direcao_maior = direcao[posicao_maior];
    if (direcao[posicao_maior] == -1) //se a direcao for para a esquerda
    {
        sequencia[posicao_maior] = sequencia[posicao_maior - 1];
        sequencia[posicao_maior - 1] = maior;
        direcao[posicao_maior] = direcao[posicao_maior - 1];
        direcao[posicao_maior - 1] = direcao_maior;
    }
    else //para a direita
    {
        sequencia[posicao_maior] = sequencia[posicao_maior + 1];
        sequencia[posicao_maior + 1] = maior;
        direcao[posicao_maior] = direcao[posicao_maior + 1];
        direcao[posicao_maior + 1] = direcao_maior;
    }
    for (int i = 0; i < n - 1; i++) //todos os numeros maiores do que o numero que acabou de ser movido tem sua direcao revertida
    {
        if (sequencia[i] > maior)
        {
            direcao[i] *= -1;
        }
    }
}

int cidadesPermutar(LISTA *distancias, int *seqfinal, int cidade_inicial, int n, int *sequencia)
{
    int distancia;
    int distancia_aux; //esta variavel guarda temporariamente a distancia retornada por distanciaCalcular
    //a variavel distancia guardara a menor distancia, que sera retornada por esta funcao
    distancia = caminhoCalcular(distancias, n, cidade_inicial, sequencia);

    // sentido para esquerda é -1 e sentido para direita é 1.
    int direcao[n - 1];
    for (int i = 0; i < n - 1; i++){
        direcao[i] = -1;
    }

    int quantidade_sequencias = fatorial(n - 1); //a quantidade de permutacoes eh n fatorial, mas excluimos a cidade inicial

    int posicao_maior_movel;
    for (int i = 1; i < quantidade_sequencias; i++)
    {
        posicao_maior_movel = maiorMovelEncontrar(sequencia, direcao, n);
        posicaoMover(posicao_maior_movel, sequencia, direcao, n);

        distancia_aux = caminhoCalcular(distancias, n, cidade_inicial, sequencia);

        if(distancia_aux == -1){ //o numero -1 eh retornado caso esse caminho nao exista
            continue;
        }

        if (distancia > distancia_aux)
        {
            distancia = distancia_aux;
            for (int i = 0; i < n - 1; i++)
            {
                seqfinal[i] = sequencia[i]; //guardamos a sequencia que tem o menor caminho ja encontrado
            }
        }
    }
    return distancia;
}

int caminhoCalcular(LISTA *distancias, int n, int cidade_inicial, int *sequencia)
{
    int distancia_final = 0;
    for (int i = 0; i < n - 2; i++)
    {
        int l = sequencia[i] - 1;
        int c = sequencia[i + 1] - 1;
        //temos a cidade de origem e a de destino, l e c. agora, achamos a chave do item na posicao c da lista que esta no item na
        //posicao l da lista distancias
        ITEM *it_aux = listaPosicao(distancias, l);

        LISTA *linha = itemDadoGet(it_aux);

        if (listaPosicao(linha, c) == NULL) //se o item for nulo, ele n foi criado, ou seja, aquele caminho nao existe
        {
            return -1;
        }

        it_aux = listaPosicao(linha, c);

        distancia_final += itemChaveGet(it_aux);
    }
    //agora, adicionamos a cidade inicial no comeco e no final do caminho

    int l = sequencia[n - 2] - 1;
    int c = cidade_inicial - 1;

    ITEM *it_aux = listaPosicao(distancias, l);

    LISTA *linha = itemDadoGet(it_aux);

    if (listaPosicao(linha, c) == NULL)
        {
            return -1;
        }

    it_aux = listaPosicao(linha, c);

    distancia_final += itemChaveGet(it_aux);

    l = sequencia[0] - 1;
    c = cidade_inicial - 1;

    it_aux = listaPosicao(distancias, l);

    linha = itemDadoGet(it_aux);

    if (listaPosicao(linha, c) == NULL)
        {
            return -1;
        }

    it_aux = listaPosicao(linha, c);

    distancia_final += itemChaveGet(it_aux);

    return distancia_final;
}

int main()
{

    int n, i, j, k, djk, dfinal;
    dfinal = 0;

    //numero de cidades
    scanf("%d", &n);

    int seqfinal[n - 1];

    // cidade inicial
    int cidade_inicial;
    scanf("%d", &cidade_inicial);

    // quantidade de estrada:
    int quantidade_estrada;
    scanf("%d", &quantidade_estrada);
    //lista dist contera listas que contem as distancias entre as cidades
    //as listas nas posicoes i sao as distancias que partem da cidade i.
    //a chave do item na posicao j na lista dentro da lista contem a distancia da cidade i para a cidade j.
    LISTA *dist = listaCriar();

    for (int i = 0; i < n; i++)
    {
        LISTA *aux = listaCriar();

        ITEM *aux_item = itemCriar(i, aux);

        listaInserir(dist, aux_item, i);
    }
    // Criando a lista de lista com as distâncias inseridas pelo usuário
    for (i = 0; i < quantidade_estrada; i++)
    {
        scanf("%d %d %d", &j, &k, &djk);

        ITEM *it_aux = listaPosicao(dist, j - 1);
        LISTA *lista_aux = itemDadoGet(it_aux);
        ITEM *distancia = itemCriar(djk, NULL);

        listaInserir(lista_aux, distancia, k - 1);

        it_aux = listaPosicao(dist, k - 1);
        lista_aux = itemDadoGet(it_aux);

        listaInserir(lista_aux, distancia, j - 1);
    }

    // Coloca a primeira rota no vetor sequencia
    int sequencia[n - 1];
    int contador = 0;
    for (int i = 0; i < n; i++)
    {

        if (i == cidade_inicial - 1)
        {
            if (i == n - 1)
            {
                break;
            }
            sequencia[i] = i + 2;
            seqfinal[i] = i + 2;
            i++;
            contador++;
            continue;
        }
        if (contador == 1)
        {
            sequencia[i - 1] = i + 1;
            seqfinal[i - 1] = i + 1;
            continue;
        }
        sequencia[i] = i + 1;
        seqfinal[i] = i + 1;
    }

   
    // chamada da função que retorna o melhor caminho
    dfinal = cidadesPermutar(dist, seqfinal, cidade_inicial, n, sequencia);
    // Formatação para sair corretamente o resultado
    printf("Cidade de Origem: %d\n", cidade_inicial);

    printf("Rota: ");

    printf("%d-", cidade_inicial);
    for (i = 0; i < n - 1; i++)
        printf("%d-", seqfinal[i]);

    printf("%d\n", cidade_inicial);

    printf("Distancia: %d\n", dfinal);

    return 0;
}
