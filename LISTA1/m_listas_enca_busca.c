#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca(celula *le, int x) {
    celula *pAtual = le->prox;

    while (pAtual != NULL) {
        if (pAtual->dado == x)
            return pAtual;
        pAtual = pAtual->prox;
    }

    return NULL;
}

celula *busca_rec(celula *le, int x) {
    celula *pAtual = le->prox;
    if (pAtual == NULL)
        return NULL;
    if (pAtual->dado == x)
        return pAtual;

    return busca_rec(pAtual, x);
}

