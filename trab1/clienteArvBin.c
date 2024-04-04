/*---------------------------------------------------------
PROGRAMA: cliente TAD ArvBin
ALUNA : Eduarda Saibert - GRR: 20232368
-----------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef int ItemArv;
#include "arvBin.h"

/* ----------------------------------------------------- */
/* Funções */

/*  Função que retorna o menor valor entre dois inteiros */
int min(int a, int b){
  return (a < b ? a : b);
}

/*  Função que retorna o maior valor entre dois inteiros */
int max(int a, int b){
  return (a > b ? a : b);
}

/*  Calcula a soma de todas as chaves da arvore */
int somaChave ( ArvBin arv ){
  if (arv == NULL){
    return 0;
  }
  
  return (arv->item + somaChave(arv->esq) + somaChave(arv->dir));

};

/*  Calcula o valor mınimo/maximo das chaves armazenadas na arvore. Caso a arvore esteja vazia o valor retornado
    deve ser zero 
*/
int valorMinMax( ArvBin arv, int (* func)(int a, int b) ){
  if (arv == NULL){
    return 0;
  }

  if (arv->esq == NULL && arv->dir == NULL){
    return arv->item;
  } 

  return func(arv->item, func(valorMinMax(arv->esq, func), valorMinMax(arv->dir, func)));
};


/*  Altera a arvore de forma que na arvore final a chave do nodo pai e igual a chave do seu maior filho */
ArvBin paiMaior( ArvBin arv, int (* func)(int a, int b )){
  if (arv == NULL){
    return arv;
  }

  paiMaior(arv->esq, func);
  paiMaior(arv->dir, func);

  int max = valorMinMax(arv, func);
  arv->item = max;

};

/*  Alterar os valores das chaves dos nodos de forma que a maior chave da arvore fique na raiz. A arvore deve
    manter as chaves originais, fazendo a troca do valor de um nodo com um dos seus filhos caso seu valor nao
    seja o maior  
*/
ArvBin maiorNaRaiz( ArvBin arv ){
  int temp, max;
  ArvBin maiorNodo;

  if (arv == NULL)
    return arv;

  arv->esq = maiorNaRaiz(arv->esq);
  arv->dir = maiorNaRaiz(arv->dir);

  max = arv->item;
  maiorNodo = arv;

  if (arv->esq != NULL && arv->esq->item > max) {
    max = arv->esq->item;
    maiorNodo = arv->esq;
  }

  if (arv->dir != NULL && arv->dir->item > max) {
    max = arv->dir->item;
    maiorNodo = arv->dir;
  }

  if (maiorNodo != arv) {
    int temp = arv->item;
    arv->item = maiorNodo->item;
    maiorNodo->item = temp;
  }

  return arv;
}

/*  funcao que altera uma arvore de forma que cada nodo
    contém o maior valor dentre os seus filhos (mantendo todas as chaves originais da arvore)
*/
ArvBin ordenaPeloMaior( ArvBin arv ){
  int max, temp;
  ArvBin maiorNodo;

  if (arv == NULL){
    return arv;
  }

  arv = maiorNaRaiz(arv);
  if (arv->esq != NULL && arv->dir != NULL){

    if (arv->esq->item < arv->dir->item){
      temp = arv->esq->item;
      arv->esq->item = arv->dir->item;
      arv->dir->item = temp;
    }
  }

  arv->esq = ordenaPeloMaior(arv->esq);
  arv->dir = ordenaPeloMaior(arv->dir);

  return arv;
};

/*  Cria novo nodo  */
ArvBin novoNodo( ItemArv item, int chave ){
  ArvBin nodo = (ArvBin) malloc(sizeof(Nodo));

  if (nodo == NULL){
    printf("Erro de alocacao de memoria\n");
    return NULL;
  }

  nodo->item = chave;
  nodo->esq = NULL;
  nodo->dir = NULL;

  return nodo;
};

/*  Dobra a quantidade de nodos da arvore criando para cada um novo pai */
ArvBin dobraArvore( ArvBin arv ){
  if (arv == NULL){
    return arv;
  }

  ArvBin aux;
  if (arv->item % 2 == 0){
    aux = novoNodo(arv->item, (arv->item)+1);
    aux->esq = arv;
  }
  else {
    aux = novoNodo(arv->item, (arv->item)-1);
    aux->dir = arv;
  }

  if (arv->esq != NULL){
    arv->esq = dobraArvore(arv->esq);
  }
  if (arv->dir != NULL){
    arv->dir = dobraArvore(arv->dir);
  }

  return aux;

};


/* ----------------------------------------------------- */
/* Programa: cria uma árvore binária e imprime a árvore
*/
int main(int argc, char *argv[]){
  ArvBin arv;
  ItemArv v;

  criaArv( &arv );
  printf("Insira uma sequencia de chaves. Finalize a sequencia com 0: \n");
  scanf( "%d", &v );
  while( v != 0 ){
    insereArvNivel( v, &arv );
    scanf( "%d", &v );
  }
  printf( "\nArvore\n" );
  escreveArv( arv );

/*----   chamada das funcoes da lista ----*/
  printf("Soma das Chaves: %d\n", somaChave(arv));
  printf("Valor mínimo: %d\n", valorMinMax(arv, min));

  // printf("Nodo pai com maior chave: \n");
  // arv = paiMaior(arv, max);
  // escreveArv( arv );

  // arv = maiorNaRaiz(arv);
  // escreveArv( arv );

  // arv = dobraArvore( arv );
  // escreveArv( arv );

  // arv = ordenaPeloMaior(arv);
  // escreveArv( arv );
/*
  --------------------------------------------- */
  free( arv );
  return 0;
}
