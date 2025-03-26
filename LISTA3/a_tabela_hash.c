#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void imprime(celula *le) {
    if (le == NULL) {
        printf("\\\n");
        return;
    }

    celula *pAtual = le->prox;

    while (pAtual != NULL) {
        printf("%d -> ", pAtual->dado);
        pAtual = pAtual->prox;
    }

    printf("\\\n");
}

void insere(celula **le, int dado) {
    celula *novoNo = (celula *)malloc(sizeof(celula));
    novoNo->dado = dado;
    novoNo->prox = NULL;

    if (*le == NULL) {
        *le = (celula *)malloc(sizeof(celula));
        (*le)->prox = NULL;
    }

    celula *aux = *le;

    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = novoNo;
}

void imprimir(int qtdTestes, int qtdChaves, celula *listas, int j){
    printf("%d -> ", j);
    imprime(listas);
}

int main(){

    int qtdTestes, qtdEnd, qtdChaves, chaves;
    scanf("%d", &qtdTestes);

    for(int i = 0; i < qtdTestes; i++){
        celula *listas[100] = {NULL};
         scanf("%d %d", &qtdEnd, &qtdChaves);
         for(int j = 0; j < qtdChaves; j++){
            scanf("%d", &chaves);
            int indice = chaves%qtdEnd;
            insere(&listas[indice], chaves);
         }
        for(int j = 0; j < qtdEnd; j++){
            imprimir(qtdTestes, qtdChaves, listas[j], j);
            if(j+1 == qtdEnd && i+1 != qtdTestes) printf("\n");
         }
         free(*listas);
    }

    return 0;
}