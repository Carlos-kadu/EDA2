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

void pos_ordem (no *raiz){
    if (raiz == NULL) return;

    Pilha* pilha = NULL;
    no* node = raiz;
    no* ultimo = NULL;

    while (node != NULL || pilha != NULL) {

        while(node != NULL){
            empilha(&pilha, node);
            node = node->esq;
        }

        no* topo = pilha->dado;
    
        if (topo->dir == NULL || topo->dir == ultimo) {
            printf("%d ", topo->dado);
            ultimo = desempilha(&pilha);
        } else {
            node = topo->dir;
        }

    }   

    printf("\n"); 
}