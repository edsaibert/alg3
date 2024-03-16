/* 
    Implementação TAD dicionário, por meio de
    uma árvore binária de busca.
*/

#include <stdio.h>
#include <stdlib.h>
#include "tadDict.h"
#include "itemString.h"

int main() {
    arvBusca raiz;
    itemArv item;

    criaDic(&raiz);

    read(item);
    while (!eq(item, "fim")){
        raiz = insereDic(item, raiz);
        read(item);
    }

    escreveDic(raiz);
    printf("Contagem de nodos: %d\n", contaItemDic(raiz));
    freeArv(raiz);

    return 0;
}