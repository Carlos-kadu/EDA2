#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[51];
    char parentesco[51];
    char nome2[51];
} Parentesco;

int indice(char** pessoa, int qtdPessoa, const char* nome) {
    for (int i = 0; i < qtdPessoa; i++) {
        if (strcmp(pessoa[i], nome) == 0) {
            return i;
        }
    }
    return -1;
}

void dfs(int pessoa, int** adj, int* visitado, int qtdPessoa) {
    visitado[pessoa] = 1;
    for (int i = 0; i < qtdPessoa; i++) {
        if (adj[pessoa][i] && !visitado[i]) {
            dfs(i, adj, visitado, qtdPessoa);
        }
    }
}

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    Parentesco* parentescos = malloc(N * sizeof(Parentesco));
    char** pessoa = malloc(M * sizeof(char*));
    for (int i = 0; i < M; i++) {
        pessoa[i] = malloc(51 * sizeof(char));
    }

    int qtdPessoa = 0;

    for (int i = 0; i < N; i++) {
        scanf("%s %s %s", parentescos[i].nome, parentescos[i].parentesco, parentescos[i].nome2);

        if (indice(pessoa, qtdPessoa, parentescos[i].nome) == -1) {
            strcpy(pessoa[qtdPessoa++], parentescos[i].nome);
        }
        if (indice(pessoa, qtdPessoa, parentescos[i].nome2) == -1) {
            strcpy(pessoa[qtdPessoa++], parentescos[i].nome2);
        }
    }

    int** adj = malloc(qtdPessoa * sizeof(int*));
    for (int i = 0; i < qtdPessoa; i++) {
        adj[i] = calloc(qtdPessoa, sizeof(int));
    }

    for (int i = 0; i < N; i++) {
        int j = indice(pessoa, qtdPessoa, parentescos[i].nome);
        int k = indice(pessoa, qtdPessoa, parentescos[i].nome2);
        adj[j][k] = 1;
        adj[k][j] = 1;
    }

    int* visitado = calloc(qtdPessoa, sizeof(int));
    int familiares = 0;

    for (int i = 0; i < qtdPessoa; i++) {
        if (!visitado[i]) {
            dfs(i, adj, visitado, qtdPessoa);
            familiares++;
        }
    }

    familiares += (M - qtdPessoa);

    printf("%d\n", familiares);

    return 0;
}
