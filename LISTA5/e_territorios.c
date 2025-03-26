#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *vizinhos;
    int count;
    int tam;
} Grafo;

void addAresta(Grafo *g, int u, int v) {
    if (g[u].count == g[u].tam) {
        g[u].tam *= 2;
        g[u].vizinhos = realloc(g[u].vizinhos, g[u].tam * sizeof(int));
    }
    g[u].vizinhos[g[u].count++] = v;
}

void dfs(Grafo *g, int no, int *visitado, int *valor) {
    visitado[no] = 1;
    *valor |= no;
    for (int i = 0; i < g[no].count; i++) {
        int vizinho = g[no].vizinhos[i];
        if (!visitado[vizinho]) {
            dfs(g, vizinho, visitado, valor);
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Grafo *g = malloc((N + 1) * sizeof(Grafo));
    for (int i = 1; i <= N; i++) {
        g[i].vizinhos = malloc(2 * sizeof(int));
        g[i].count = 0;
        g[i].tam = 2;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addAresta(g, u, v);
        addAresta(g, v, u);
    }

    int *visitado = calloc(N + 1, sizeof(int));
    int preco = 0;
    int primeiro = 1;

    for (int i = 1; i <= N; i++) {
        if (!visitado[i]) {
            int valor = 0;
            dfs(g, i, visitado, &valor);
            if (primeiro) {
                preco = valor;
                primeiro = 0;
            } else {
                preco ^= valor;
            }
        }
    }

    printf("%d\n", preco);

    return 0;
}
