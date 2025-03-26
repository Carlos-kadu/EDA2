#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define OFFSET 536870912
#define TAM 1048575

typedef struct No {
    int chave;
    int qtd;
    struct No* prox;
} No;

typedef struct {
    int capacidade;
    No** elementos;
} Tabela;

uint32_t murmurhash3(uint32_t key) {
    key ^= key >> 16;
    key *= 0x85ebca6b;
    key ^= key >> 13;
    key *= 0xc2b2ae35;
    key ^= key >> 16;
    return key % TAM;
}

Tabela* criaTabela(int capacidade) {
    Tabela* tabela = malloc(sizeof(Tabela));
    tabela->capacidade = capacidade;
    tabela->elementos = calloc(capacidade, sizeof(No*));
    return tabela;
}

long long contabilizaItens(Tabela* tabela) {
    long long total = 0;
    for (int i = 0; i < tabela->capacidade; i++) {
        No* atual = tabela->elementos[i];
        while (atual != NULL) {
            total += atual->qtd;
            atual = atual->prox;
        }
    }
    return total;
}

No* busca(Tabela* tabela, int K) {
    int indice = murmurhash3(K);
    No* atual = tabela->elementos[indice];
    while (atual != NULL) {
        if (atual->chave == K) return atual;
        atual = atual->prox;
    }
    return NULL;
}

void insere(Tabela* tabela, int K, int qtd) {
    int indice = murmurhash3(K);
    No* atual = busca(tabela, K);
    if (atual != NULL){
        if((atual->qtd+qtd <= 0)) atual->qtd = 0;
        else atual->qtd += qtd;
    }
    else {
        if (qtd > 0) { 
            No* novoNo = malloc(sizeof(No));
            novoNo->chave = K;
            novoNo->qtd = qtd;
            novoNo->prox = tabela->elementos[indice];
            tabela->elementos[indice] = novoNo;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    Tabela* tabela = criaTabela(TAM);

    for (int i = 0; i < N; i++) {
        int K, Q;
        scanf("%d %d", &K, &Q);
        insere(tabela, K + OFFSET, Q);
    }

    long long totalItens = contabilizaItens(tabela);
    printf("%lld\n", totalItens);

    return 0;
}
