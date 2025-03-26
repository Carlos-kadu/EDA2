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

void em_ordem (no *raiz){
    if (raiz == NULL) return;

    Pilha* pilha = NULL;
    no* node = raiz;

    while (node != NULL || pilha != NULL) {

        while(node != NULL){
            empilha(&pilha, node);
            node = node->esq;
        }

        node = desempilha(&pilha);
        printf("%d ", node->dado);

        node = node->dir;

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

    em_ordem(raiz);

    return 0;
}
