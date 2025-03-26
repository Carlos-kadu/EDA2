#include <stdio.h>
#include <stdlib.h>

void vizinho_visitado(int loc, int n, int adj[][n], int visitado[]) {
    for (int i = 0; i < n; i++) {
        if (adj[loc][i] == 1) {
            visitado[i] = 1;
        }
    }
}

int main() {
    int n, m, j;
    scanf("%d %d %d", &n, &m, &j);

    int (*adj)[n] = malloc(n * n * sizeof(int));
    int *visitado = malloc(n * sizeof(int));
    int *check = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
        visitado[i] = 0;
        check[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int a, num_visinhos;
        scanf("%d", &num_visinhos);
        for (int k = 0; k < num_visinhos; k++) {
            scanf("%d", &a);
            adj[i][a] = 1;
        }
    }

    for (int i = 0; i < m; i++) {
        int loc;
        scanf("%d", &loc);
        visitado[loc] = 1;
        vizinho_visitado(loc, n, adj, visitado);
    }

    for (int i = 0; i < j; i++) {
        int q;
        scanf("%d", &q);
        if (visitado[q]) {
            printf("Eu vou estar la\n");
        } else {
            printf("Nao vou estar la\n");
        }
    }

    return 0;
}
