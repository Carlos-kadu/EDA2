#include <stdio.h>

void atualizarCoordenadas(int *x, int *y, int direcao) {
    if (direcao == 1) (*y)++;
    else if (direcao == 2) (*y)--;
    else if (direcao == 3) (*x)++;
    else (*x)--;
}

int main() {
    int nColunas, nLinhas, xPA = 1, yPA = 1, xPB, yPB, valoresPA, valoresPB, qtd, i;

    scanf("%d %d", &nColunas, &nLinhas);
    xPB = nColunas;
    yPB = nLinhas;

    scanf("%d", &qtd);

    for (i = 0; i < qtd; i++) {
        scanf("%d %d", &valoresPA, &valoresPB);

        atualizarCoordenadas(&xPA, &yPA, valoresPA);
        atualizarCoordenadas(&xPB, &yPB, valoresPB);

        if (xPA == xPB && yPA == yPB) {
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", xPA, yPA, i + 1);
            break;
        }
        
        if (xPA > nColunas || xPA < 1 || yPA > nLinhas || yPA < 1) {
            printf("PA saiu na posicao (%d,%d) no passo %d\n", xPA, yPA, i + 1);
            break;
        }
        
        if (xPB > nColunas || xPB < 1 || yPB > nLinhas || yPB < 1) {
            printf("PB saiu na posicao (%d,%d) no passo %d\n", xPB, yPB, i + 1);
            break;
        }
    }

    if (i == qtd)
        printf("Nao se encontraram\n");

    return 0;
}
