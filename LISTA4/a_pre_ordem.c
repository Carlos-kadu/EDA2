#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int dado;
   struct no *esq, *dir;
} no;

typedef struct Pilha {
    no* dado;
    struct Pilha* prox;
} Pilha;

void empilha(Pilha** topo, no* dado) {
    Pilha* novoEmp = malloc(sizeof(Pilha));
    novoEmp->dado = dado;
    novoEmp->prox = *topo;
    *topo = novoEmp;
}

no* desempilha(Pilha** topo) {
    if (*topo == NULL) return NULL;
    
    Pilha* temp = *topo;
    *topo = (*topo)->prox;
    no* removido = temp->dado;
    free(temp);
    return removido;
}

void pre_ordem (no *raiz){
    if (raiz == NULL) return;

    Pilha* pilha = NULL;
    empilha(&pilha, raiz);

    while (pilha != NULL) {

        no* no = desempilha(&pilha);
        printf("%d ", no->dado);

        if (no->dir != NULL) empilha(&pilha, no->dir);
        if (no->esq != NULL) empilha(&pilha, no->esq);
    }   

    printf("\n"); 
}


no* novoNo(int dado) {
    no* temp = (no*)malloc(sizeof(no));
    temp->dado = dado;
    temp->esq = NULL;
    temp->dir = NULL;
    return temp;
}

int main() {
    no *raiz = novoNo(2);
    raiz->esq = novoNo(5);
    raiz->dir = novoNo(7);

    raiz->esq->esq = novoNo(3);
    raiz->esq->dir = novoNo(8);
    raiz->esq->dir->esq = novoNo(4);

    raiz->dir->esq = novoNo(1);
    raiz->dir->dir = novoNo(6);
    raiz->dir->esq->dir = novoNo(9);

    pre_ordem(raiz);

    return 0;
}
