#include <stdio.h>
#include <string.h>

struct Instrucao {
    int codigo;
    char palavraChave[16];
};

int main() {
    int n;
    scanf("%d", &n);

    struct Instrucao instrucoes[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d %s", &instrucoes[i].codigo, instrucoes[i].palavraChave);
    }

    int codigoConsulta;

    while (scanf("%d", &codigoConsulta) != EOF) {
        int encontrado = 0; 
        for (int i = 0; i < n; ++i) {
            if (codigoConsulta == instrucoes[i].codigo) {
                printf("%s\n", instrucoes[i].palavraChave);
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            printf("undefined\n");
        }
    }

    return 0;
}
