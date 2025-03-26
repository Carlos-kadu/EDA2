#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1048576

typedef struct Alimento {
    char alimento[11];
    struct Alimento *prox;
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

int addAlimento(int id, char *alimento) {
    int index = hash(id);
    HashAlimento *aux = tabela[index];
    while (aux != NULL) {
        if (aux->id == id) {
            Alimento *atual = aux->alimentos;
            while (atual != NULL) {
                if (strcmp(atual->alimento, alimento) == 0) {
                    return 1;
                }
                atual = atual->prox;
            }
            Alimento *noNo = malloc(sizeof(Alimento));
            strcpy(noNo->alimento, alimento);
            noNo->prox = aux->alimentos;
            aux->alimentos = noNo;
            return 0;
        }
        aux = aux->prox;
    }

    HashAlimento *novo = malloc(sizeof(HashAlimento));
    novo->id = id;
    novo->alimentos = malloc(sizeof(Alimento));
    strcpy(novo->alimentos->alimento, alimento);
    novo->alimentos->prox = NULL;
    novo->prox = tabela[index];
    tabela[index] = novo;
    return 0;
}

int main() {
    int id;
    char alimento[11];

    while (scanf("%d %10s", &id, alimento) != EOF) {
        if (addAlimento(id, alimento)) {
            printf("%d\n", id);
        }
    }
    
    return 0;
}
