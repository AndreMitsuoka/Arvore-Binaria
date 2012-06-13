#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#define MAX 10

No *arv(elem_t c, No* esq, No* dir){
  No *novo;

novo = (No *)malloc(sizeof(No));
novo->info = c;
novo->esq = esq;
novo->dir = dir;

  return novo;
}

void preorder(No* p){

	if(p != NULL){
		printf("%c",p->info);
		preorder(p->esq);
		preorder(p->dir);	
	}

}

void inorder(No* p){
	if (p != NULL){
		inorder (p->esq);
		printf ("%c",p->info);
		inorder(p->dir);
	}
}

void postorder(No* p){
	if(p != NULL){
		postorder(p->esq);
		postorder(p->dir);
		printf ("%c",p->info);
	}

}

void largura(No* p){
	No *aux, *vet[MAX];
	int fim, inicio;
		
	vet[0] = p;	
	inicio = 0;
	fim = 1;

	while(inicio < fim){
		aux = vet[inicio];
		inicio++;
		printf("%c", aux->info);
		if(aux->esq != NULL){
			vet[fim] = aux->esq;
			fim++;
		}		
		if(aux->dir != NULL){
			vet[fim] = aux->dir;
			fim++;		
		}
	}	
	
}


void libera(Arvore* p){
	No * aux;
	aux = *p;

	if((aux) != NULL){
		libera(&(aux)->esq);
	  libera(&(aux)->dir);
	  free(aux->info);
	  free(aux);
	  aux = NULL;
	  return 0;
  }
}

No* copia(No* p){
	No *novo;
	novo = (No *)malloc(sizeof(No));
	if (p != NULL){
		   (novo)->info = (p)->info;
		//do{
			novo->esq = copia(p->esq);
			novo->dir = copia(p->dir);	
		//} while(p != NULL);
	}
	return novo;
}

int altura (No* p){
	int e,d;

	if(p == NULL){
		return 0;		
	}
	e = altura(p->esq);
	d = altura(p->dir);

if(e > d){
		return e+1;		
	}
	return d+1;
}

int nNos (No* p){
  int count;
  if(p != NULL){
  	count++;
  	nNos(p->esq);
  	nNos(p->dir);
  }

  return count+1;
}

int iguais(No* arv1, No* arv2){
  char v1[MAX], v2[MAX];
  int i=0, n = 0 , flag = 0;
  No *aux;
  aux = arv1;

  while (flag <= 1){ // condição para trocar a árvore
    if (aux != NULL){

			strcat(v1,aux->info);
	  	i++;
			preorder(aux->esq);
			preorder(aux->dir);	
	  }
	  if (flag == 0){
	  	aux = arv2;
	  	n = i;
	  	i = 0;
	 		strcpy(v2,v1);
		}
		flag++;
	}
	printf("%s %s",v1,v2);
	if( n != i){
		return 0;
	}else if (strcmp(v1,v2) != 0)
		return 0;

	return 1;

}

//No* monta_arv_expr ();
//a = monta_arv_expr("*+abc", &i);

No* monta_arv_expr (char s[], int *pos){	
  No * novo;
  novo = (No*)malloc(sizeof(No));

  while (s[*pos] != '\0')    {
  	novo->info = s[*pos];
  	//printf("\n char %c  pos: %d \n",s[*pos],*pos);
  	*pos = *pos + 1;

  	if (((s[*pos] == '*') || ( s [*pos ]== '+')) || ((s[*pos] == '-') || (s[*pos] == '/'))){
  			printf("hello if");
  			novo->esq = monta_arv_expr(s,pos);
  			novo->dir = monta_arv_expr(s,pos);
  	} 
  }

  return novo;
}
		




