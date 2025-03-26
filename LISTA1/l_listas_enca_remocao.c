#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

int remove_depois (celula *p){
    if(p->prox == NULL) return 1;
    celula *aux = p->prox;

    p->prox = aux->prox;
    free(aux);

    return 0;
}

void remove_elemento (celula *le, int x){
    celula *pAnt, *pPos;
    pAnt = le->prox;

    while(pAnt->prox != NULL && pAnt->prox->dado != x){
        pAnt = pAnt->prox;
    }

    if(pAnt->prox == NULL) return;

    pPos = pAnt->prox->prox;
    free(pAnt->prox);
    pAnt->prox = pPos;
}

void remove_todos_elementos (celula *le, int x){
    celula *pAnt = le, *aux = le->prox;
    if(le->prox == NULL) return;

    while (aux != NULL){
        
        if(aux->dado == x){
            pAnt->prox = aux->prox;
        }
        pAnt = aux;
        aux = aux->prox;
    }
    
}
