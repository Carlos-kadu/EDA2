#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void insere_inicio (celula *le, int x){
   celula *novoNo;
   novoNo = (celula *)malloc(sizeof(celula));

   novoNo->dado = x;
   novoNo->prox = le->prox;
   le->prox = novoNo;

   return;
}

void insere_antes (celula *le, int x, int y){
   celula *novoNo, *aux;
   novoNo = (celula *)malloc(sizeof(celula));
   aux = (celula *)malloc(sizeof(celula));
   
   novoNo->dado = x;
   aux->prox = le->prox;

   while (aux->prox != NULL && aux->prox->dado != y){
      aux = aux->prox;
   }
   
   if(aux == NULL){
      novoNo->prox = NULL;
      aux->prox = novoNo;
   }

   novoNo->prox = aux->prox;
   aux->prox = novoNo;

   return;
}