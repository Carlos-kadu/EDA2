#include <stdio.h>

int main() {
    int v[10000], n, i, verificador;
    long long int media;
    media = 0;
    scanf("%d", &n);
    verificador = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for (i = 0; i < n; i++) {
        media += v[i];
    }

    media = media / n;

    for (i = 0; i < n; i++) {
        if (v[i] > media) {
            printf("%d ", v[i]);
            verificador++;
        }
    }
    if (verificador == 0) {
        printf("0");
    }

    printf("\n");

    return 0;
}
