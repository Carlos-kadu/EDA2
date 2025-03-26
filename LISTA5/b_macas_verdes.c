#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int tipo;
    int esq;
    int dir;
} No;

typedef struct Nivel {
    int verde;
    int vermelho;
} Nivel;

int main() {
    int N;
    scanf("%d", &N);

    No *nos = malloc(N * sizeof(No));
    Nivel *niveis = calloc(N, sizeof(Nivel));

    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &nos[i].tipo, &nos[i].esq, &nos[i].dir);
    }

    int *fila = malloc(N * sizeof(int));
    int frente = 0, tras = 0;

    fila[tras++] = 0;
    niveis[0].verde = (nos[0].tipo == 1);
    niveis[0].vermelho = (nos[0].tipo == 2);

    int nivelAtual = 0;

    while (frente < tras) {
        int tamanhoNivel = tras - frente;
        int inicioProximoNivel = tras;

        for (int i = 0; i < tamanhoNivel; i++) {
            int indiceNo = fila[frente++];

            if (nos[indiceNo].esq != 0) {
                fila[tras++] = nos[indiceNo].esq - 1;
                int indiceEsq = nos[indiceNo].esq - 1;
                niveis[nivelAtual + 1].verde += (nos[indiceEsq].tipo == 1);
                niveis[nivelAtual + 1].vermelho += (nos[indiceEsq].tipo == 2);
            }
            if (nos[indiceNo].dir != 0) {
                fila[tras++] = nos[indiceNo].dir - 1;
                int indiceDir = nos[indiceNo].dir - 1;
                niveis[nivelAtual + 1].verde += (nos[indiceDir].tipo == 1);
                niveis[nivelAtual + 1].vermelho += (nos[indiceDir].tipo == 2);
            }
        }
        nivelAtual++;
    }

    for (int i = 0; i < nivelAtual; i++) {
        if (niveis[i].verde != 0 || niveis[i].vermelho != 0) {
            printf("%d %d\n", niveis[i].verde, niveis[i].vermelho);
        }
    }
    
    return 0;
}