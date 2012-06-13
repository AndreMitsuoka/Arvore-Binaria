/*
 * Árvores binárias
 */

#ifndef _ARV

typedef char elem_t;

typedef struct no {
  elem_t info;
  struct no *esq, *dir;
} No;

typedef No * Arvore;

No *arv(elem_t c, No* esq, No* dir);

void preorder(No* p);

void inorder(No* p);

void postorder(No* p);

void largura(No* p);

void libera(Arvore* p);

No* copia(No* p);

int altura (No* p);

int nNos (No* p);

int iguais(No* arv1, No* arv2);

//No* monta_arv_expr ();
No* monta_arv_expr (char s[], int *pos);
		
#endif



