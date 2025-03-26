#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void quickSort(int *arr, int esq, int dir) {
    if (esq < dir) {
        int pivo = arr[dir];
        int i = esq - 1;

        for (int j = esq; j <= dir - 1; j++) {
            if (arr[j] < pivo) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[dir];
        arr[dir] = temp;

        int pi = i + 1;

        quickSort(arr, esq, pi - 1);
        quickSort(arr, pi + 1, dir);
    }
}

int main() {
    int N, X;
    scanf("%d %d", &N, &X);

    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    quickSort(A, 0, N - 1);

    int indiceA = 0;
    int tamanhoB = 0;
    int *B = (int *)malloc(N * sizeof(int));
    int combinadoCont = 0;
    int *combinado = (int *)malloc(N * sizeof(int));

    while (indiceA < N) {
        int min_A = A[indiceA++];

        if (tamanhoB > 0) {
            int max_B = B[tamanhoB - 1];
            if (abs(min_A - max_B) <= X && abs(min_A - max_B) > 0) {
                combinado[combinadoCont++] = min_A + max_B;
                tamanhoB--;
            } else {
                B[tamanhoB++] = min_A;
            }
        } else {
            B[tamanhoB++] = min_A;
        }
    }

    printf("%d\n", combinadoCont);
    if (combinadoCont > 0) {
        for (int i = 0; i < combinadoCont; i++) {
            if (i > 0) printf(" ");
            printf("%d", combinado[i]);
        }
        printf("\n");
    }

    return 0;
}
