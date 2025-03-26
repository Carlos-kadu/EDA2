#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

no *maximo(no *r) {
    if (r == NULL) {
        return NULL;
    }
    while (r->dir != NULL) {
        r = r->dir;
    }
    return r;
}

no* novoNo(int chave) {
    no* nodo = (no*) malloc(sizeof(no));
    nodo->chave = chave;
    nodo->esq = nodo->dir = NULL;
    return nodo;
}

no* inserir(no* nodo, int chave) {
    if (nodo == NULL) {
        return novoNo(chave);
    }
    if (chave < nodo->chave) {
        nodo->esq = inserir(nodo->esq, chave);
    } else if (chave > nodo->chave) {
        nodo->dir = inserir(nodo->dir, chave);
    }
    return nodo;
}

int main() {
    no* raiz = NULL;
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 70);
    inserir(raiz, 60);
    inserir(raiz, 80);

    no* max = maximo(raiz);
    if (max != NULL) {
        printf("O valor máximo na árvore binária de busca é: %d\n", max->chave);
    } else {
        printf("A árvore está vazia.\n");
    }

    return 0;
}
