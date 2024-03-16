/* 
    Implementação TAD dicionário, por meio de
    uma árvore binária de busca.
*/

/*  Definição do tipo contido no item da árvore */
typedef char itemArv[50];

/*  Estrutura do dicionário */
typedef struct arvBin *apBin;
typedef struct arvBin {
    itemArv item;
    apBin esq, dir;
    int chave;

} arvBin;

typedef apBin arvBusca;

/*  Entrada: ponteiro para a árvore; Saída: um dicionário vazio   */
void criaDic ( arvBusca* arv );

/*  Entrada: raiz da árvore/subárvore; Saída: contagem de elementos */
int contaItemDic ( arvBusca arv );

/*  Entrada: raíz da arvore/subárvore. Saída: (null)    */
void rotacaoEsq ( arvBusca arv );

/*  Entrada: raíz da arvore/subárvore. Saída: (null)    */
void rotacaoDir (arvBusca arv );

/*  Entrada: item a ser inserido no nodo, ponteiro para a raíz da árvore/subárvore;
    Saída: nova árvore
*/
arvBusca insereDic ( itemArv item, arvBusca arv );

/*  Entrada: item a ser procurado, sua chave, raíz da árvore/subárvore  
    Saída: o nodo procurado, se existir. 
*/
arvBusca buscaDic ( itemArv item, arvBusca arv);

/*  Entrada: chave do nodo a ser removido, ponteiro para a raíz da árvore/subárvore 
    Saída: 1 para sucesso, 0 para erro  
*/
int removeDic ( int chave, arvBusca* arv );

/*  Entrada: número 'k' representando o k-ésimo elemento a ser achado, raíz da árvore/subárvore
    Saída: chave do elemento encontrado, se encontrado
*/
int buscaElemK ( int k, arvBusca arv );

/*  Entrada: árvore/subárvore
    Saída: escrita da árvore
*/
void escreveDic ( arvBusca arv );

/*  Entrada: raíz da árvore/subárvore, função para ser aplicada a todos os nodos da árvore
    Saída: (void)
*/
void visitaOrdenado ( arvBusca arv, void (*func)(itemArv) );

/*  Entrada: raíz da árvore/subárvore. Saída: (void)    */
void freeArv( arvBusca arv );