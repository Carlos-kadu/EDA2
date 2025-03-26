#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le) {
    if (le == NULL) {
        printf("NULL\n");
        return;
    }

    celula *pAtual = le->prox;

    while (pAtual != NULL) {
        printf("%d -> ", pAtual->dado);
        pAtual = pAtual->prox;
    }

    printf("NULL\n");
}

void imprime_rec_aux(celula *le) {
    if (le == NULL) {
        printf("NULL\n");
        return;
    }

    printf("%d -> ", le->dado);
    imprime_rec_aux(le->prox);
}

void imprime_rec(celula *le) {
    imprime_rec_aux(le->prox);
}
