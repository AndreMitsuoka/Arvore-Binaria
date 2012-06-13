/*
 * Árvores binárias
 */


#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"


int main() {
  Arvore a, b,c;
  int i;
/* Cria a árvore         
           a
          / \
			   b   c
			      /
			     d
            \
             e
              \
               f
          
*/
  a = arv('a',arv('b',NULL,NULL),arv('c',arv('d',NULL,arv('e',NULL,arv('f',NULL,NULL))),NULL));
  
  b = copia(a); //
   printf("%x %x", a, b);
  //  b = arv('a',arv('b',NULL,NULL),arv('c',NULL,NULL));
  printf("\nPre: ");
  preorder(a);
  printf("\nIn: ");
  inorder(a);
  printf("\nPost: ");
  postorder(a);
  printf("\nB tree\n\n");

  printf("Pre b: ");
  preorder(b);

  printf("\nEm b: ");
  inorder(b);
  printf("\nPos b: ");
  postorder(b);
  printf("\n\nLargura A: ");
  largura(a);
  printf("\n\n");

  printf("Altura %d\n", altura(a));


  printf("Numero de nos %d\n", nNos(a));
  
 libera(a);
 printf("liberado");

  i = 0;

  c = monta_arv_expr("*+abc", &i);
  //a = arv('a',arv('b',NULL,NULL),NULL);

  printf("Pre: ");
  preorder(c);
  printf("\nEm: ");
  inorder(c);
  printf("\nPos: ");
  postorder(c);
  printf("\n\n");

  printf("\n IGUAIS : %d \n", iguais(a,c));
  
  if (iguais(a,b) == 1)
    printf("arvores iguais\n\n");
  else
    printf("arvores diferentes\n\n");
  

  libera(&b);

  libera(&a);

  return 0;
}
