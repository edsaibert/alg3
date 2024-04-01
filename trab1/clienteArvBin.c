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

/*  Calcula a soma de todas as chaves da arvore */
int somaChave ( ArvBin arv ){
  if (arv == NULL)
    return 0;
  
  return (arv->item + somaChave(arv->esq) + somaChave(arv->dir));

};

/*  Calcula o valor mınimo das chaves armazenadas na arvore. Caso a arvore esteja vazia o valor retornado
    deve ser zero 
*/
int valorMinimo( ArvBin arv ){};

/*  Altera a arvore de forma que na arvore final a chave do nodo pai e igual a chave do seu maior filho */
ArvBin paiMaior( ArvBin arv ){};

/*  Alterar os valores das chaves dos nodos de forma que a maior chave da arvore fique na raiz. A arvore deve
    manter as chaves originais, fazendo a troca do valor de um nodo com um dos seus filhos caso seu valor nao
    seja o maior  
*/
ArvBin maiorNaRaiz( ArvBin arv ){};

/*  funcao que altera uma arvore de forma que cada nodo
    contém o maior valor dentre os seus filhos (mantendo todas as chaves originais da arvore)
*/
ArvBin ordenaPeloMaior( ArvBin arv ){};

/*  Dobra a quantidade de nodos da arvore criando para cada um novo pai */
ArvBin dobraArvore( ArvBin arv ){};


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
  printf("%d\n", somaChave(arv));
/*
  printf("%d\n" valorMinimo(...) );

  ... paiMaior(...)
  escreveArv( arv );

  ... maiorNaRaiz(...)
  escreveArv( raiz );

  ... ordenaPeloMaior(...)
  escreveArv( raiz );

  ... dobraArvore(...)
  escreveArv( raiz );
  --------------------------------------------- */
  free( arv );
  return 0;
}
