/*---------------------------------------------------------
PROGRAMA: expressao.c

Programa que le uma expressao em notação Polonesa reversa e a avalia 
utilizando o TAD Pilha.  A expressão termina com a palavra "fim".

Exemplo:
21 3 * 11.36 89 * 25.7 5.3 * - / fim

Saida: Valor = 0.072014

Dicas:
-----------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ItemPilha[50];
#include "itemString.h"
#include "pilha.h"

/* ----------------------------------------------------- */
/* Determina se uma string contem um operador (+ - * / )
   Entrada: string s
   Saida: 1 se s é um operador e 0, caso contrario */
int ehOperador( Item s ){
  if( eq(s, "/") ||  eq(s, "+") || eq(s, "-") || eq(s, "*") )
    return 1;
  else
    return 0;
}

/* ----------------------------------------------------- */
/* Avalia a operação op com os operadores s1 e s2 e coloca o
   resultado em res (todos os parâmetros são strings).
   DICA:
   use as funções
   atof( string): retorna um double representado na string
   sprintf( string, "%f", double ) converte o double em string
*/
void avalia( Item op, Item s1, Item s2, Item *res ){
   double auxS1, auxS2;
   auxS1 = atof(s1);
   auxS2 = atof(s2);

   switch (*op)
   {
   case '+':
      sprintf(*res, "%f", auxS1 + auxS2);
      break;
   
   case '-':
      sprintf(*res, "%f", auxS1 - auxS2);
      break;

   case '*':
      sprintf(*res, "%f", auxS1 * auxS2);
      break;
   
   case '/':
      sprintf(*res, "%f", auxS1 / auxS2);
      break;
   
   default:
      printf("Operador inválido\n");
      break;
   }
}


/* ----------------------------------------------------- */
/* Programa: lê uma expressao  aritmetica na notação Polonesa
   reversa  e avalia a expressao utilizando o TAD Pilha.
*/
int main(int argc, char *argv[]){
    Pilha p;
    ItemPilha v;
    ItemPilha s1, s2, res;

    // Inicializa pilha
    criaPilha(&p);

    // Manipula a expressão de acordo com o valor de "v" 
    read(v);
    while ((eq(v, "fim")) == 0){
   
      if (ehOperador(v)){
        desempilha(&p, s2);
        desempilha(&p, s1);
        avalia(v, s1, s2, &res);
        empilha(res, &p);
      }
      else
         empilha(v, &p);

      read(v);
    }

    // Imprime o resultado
    write(res);
    return 0;
}

