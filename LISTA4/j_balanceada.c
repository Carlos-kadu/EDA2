#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int chave;
    struct No* esq;
    struct No* dir;
} No;

No* novoNo(int chave) {
    No* novoNo = malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->esq = novoNo->dir = NULL;
    return novoNo;
}

void addFilho(No* nos[], int pai, int filho) {
    if (nos[pai]->esq == NULL) {
        nos[pai]->esq = nos[filho];
    } else {
        nos[pai]->dir = nos[filho];
    }
}

bool calcBalanceada(No* no, int* h) {
    if (no == NULL) {
        *h = 0;
        return true;
    }

    int he = 0, hd = 0;
    bool heb = calcBalanceada(no->esq, &he);
    bool hdb = calcBalanceada(no->dir, &hd);

    *h = 1 + (he > hd ? he : hd);
    return heb && hdb && abs(he - hd) <= 1;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("Sim\n");
        return 0;
    }

    int pais[n-1];
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &pais[i]);
    }

    No* nos[n + 1];
    for (int i = 1; i <= n; i++) {
        nos[i] = novoNo(i);
    }

    for (int i = 0; i < n - 1; i++) {
        addFilho(nos, pais[i], i + 2);
    }

    int h = 0;
    bool ehBalanceada = calcBalanceada(nos[1], &h);

    if (ehBalanceada) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }

    return 0;
}
