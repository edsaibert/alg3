/* 
    Implementação TAD dicionário, por meio de
    uma árvore binária de busca.
*/

#include "tadDict.h"
#include <stdlib.h>
#include <stdio.h>

void criaDic ( arvBusca* arv ){
    arv = NULL;
}

int criaNodo( itemArv item, arvBusca* arv ) {

}

void rotacaoEsq ( arvBusca arv ){
    arvBusca aux = arv; arv = arv->dir; arv->esq = aux;
}

void rotacaoDir ( arvBusca arv ){
    arvBusca aux = arv; arv = arv->esq; arv->dir = aux;
}

int insereDic ( itemArv item, arvBusca* arv ){
    //apBin nodo;
    //if (!criaNodo(item, &nodo))
    //    return 0;
    if ( arv == NULL ){
        return 0;
    }

    // nao sei onde colocar o criaNodo (é no retorno)

    if (item < (*arv)->item){
        insereDic(item, (*arv)->esq);
        rotacaoDir(arv);
    }
    else {
        insereDic(item, (*arv)->dir);
        rotacaoEsq(arv);
    }
    
    return 1;
}