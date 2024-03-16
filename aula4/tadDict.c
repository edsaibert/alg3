/* 
    Implementação TAD dicionário, por meio de
    uma árvore binária de busca.
*/

#include "tadDict.h"
#include "itemString.h"
#include <stdlib.h>
#include <stdio.h>


void criaDic ( arvBusca* arv ){
    arv = NULL;
}

int arvVazia ( arvBusca arv ){
    return (arv == NULL);
}

void rotacaoEsq ( arvBusca arv ){
    arvBusca aux = arv; arv = arv->dir; arv->esq = aux;
}

void rotacaoDir ( arvBusca arv ){
    arvBusca aux = arv; arv = arv->esq; arv->dir = aux;
}

arvBusca criaNodo( itemArv item ){
    arvBusca nodo;

    nodo = (arvBusca) malloc(sizeof(arvBin));

    cp(nodo->item, item);    
    nodo->chave = 1;
    nodo->esq = NULL;
    nodo->dir = NULL;

    return nodo;
}

arvBusca insereDic ( itemArv item, arvBusca arv ){

    if (arvVazia(arv)){
        return criaNodo(item);
    }
    arv->chave++;

    if (lt(arv->item, item)) 
        arv->esq = insereDic(item, arv->esq);
    else
        arv->dir = insereDic(item, arv->dir);

    return arv;
}

void escreveDic( arvBusca arv ){
    if ( arvVazia(arv) ){
        return;
    }

    escreveDic(arv->dir);
    write(arv->item);
    write("\n");
    escreveDic(arv->esq);
}

void freeArv ( arvBusca arv ){
    if (arv == NULL)
        return;

    freeArv( arv->esq );
    freeArv( arv->dir );
    free(arv);
}