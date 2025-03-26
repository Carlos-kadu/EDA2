#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

no *remover(no *r, int x) {
    if (r == NULL)
        return r; 

    if (x < r->chave)
        r->esq = remover(r->esq, x);
    else if (x > r->chave)
        r->dir = remover(r->dir, x);
    else {
        if (r->esq == NULL) {
            no *temp = r->dir;
            free(r);
            return temp;
        } else if (r->dir == NULL) {
            no *temp = r->esq;
            free(r);
            return temp;
        }

        no *antecessor = r->esq;
        while (antecessor->dir != NULL)
            antecessor = antecessor->dir;
        r->chave = antecessor->chave;
        r->esq = remover(r->esq, antecessor->chave);
    }
    return r;
}


