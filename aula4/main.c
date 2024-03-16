/* 
    Implementação TAD dicionário, por meio de
    uma árvore binária de busca.
*/

#include <stdio.h>
#include <stdlib.h>
#include "tadDict.h"
#include "itemString.h"

int main() {
    arvBusca raiz, nodo;
    itemArv item;

    /*  Inicializa a árvore */
    criaDic(&raiz);

    /*  Preenche a árvore */
    read(item);
    while (!eq(item, "fim")){
        raiz = insereDic(item, raiz);
        read(item);
    }

    /*  Escreve a árvore e sua contagem de nodos    */
    escreveDic(raiz);
    printf("Contagem de nodos: %d\n", contaItemDic(raiz));
    
    /*  Busca de item por chave */
    read(item);
    nodo = buscaDic(item, raiz);
    if (nodo)
        write(nodo->item)
    else
        write("O nodo não existe.\n");

    /*  Busca de item por contagem  */

    /*  Limpeza dos ponteiros   */
    freeArv(raiz);

    return 0;
}