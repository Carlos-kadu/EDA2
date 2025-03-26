#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 2097151 

typedef struct Alimento {
    char alimento[11];
    struct Alimento *esq;
    struct Alimento *dir;
} Alimento;

typedef struct HashAlimento {
    int id;
    Alimento *alimentos;
    struct HashAlimento *prox;
} HashAlimento;

HashAlimento *tabela[TAM];

int hash(int id) {
    return id % TAM;
}

Alimento *criaAlimento(char *alimento) {
    Alimento *novo = malloc(sizeof(Alimento));
    if (novo != NULL) {
        strcpy(novo->alimento, alimento);
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

void insereArvore(Alimento **raiz, char *alimento);

int buscaAlimento(Alimento *raiz, char *alimento) {
    if (raiz == NULL) {
        return 0;
    } else {
        int cmp = strcmp(alimento, raiz->alimento);
        if (cmp < 0) {
            return buscaAlimento(raiz->esq, alimento);
        } else if (cmp > 0) {
            return buscaAlimento(raiz->dir, alimento);
        } else {
            return 1;
        }
    }
}

int addAlimento(int id, char *alimento) {
    int index = hash(id);
    HashAlimento *aux = tabela[index];
    while (aux != NULL) {
        if (aux->id == id) {
            if (buscaAlimento(aux->alimentos, alimento)) {
                return id;
            } else {
                insereArvore(&(aux->alimentos), alimento);
                return 0;
            }
        }
        aux = aux->prox;
    }

    HashAlimento *novo = malloc(sizeof(HashAlimento));

    novo->id = id;
    novo->alimentos = NULL;
    insereArvore(&(novo->alimentos), alimento);
    novo->prox = tabela[index];
    tabela[index] = novo;
    return 0;
}

void insereArvore(Alimento **raiz, char *alimento) {
    if (*raiz == NULL) {
        *raiz = criaAlimento(alimento);
    } else {
        int cmp = strcmp(alimento, (*raiz)->alimento);
        if (cmp < 0) {
            insereArvore(&(*raiz)->esq, alimento);
        } else if (cmp > 0) {
            insereArvore(&(*raiz)->dir, alimento);
        }
    }
}

int main() {
    int id;
    char alimento[11];

    while (scanf("%d %s", &id, alimento) != EOF) {
        int result = addAlimento(id, alimento);
        if (result > 0) {
            printf("%d\n", result);
        }
    }

    return 0;
}
