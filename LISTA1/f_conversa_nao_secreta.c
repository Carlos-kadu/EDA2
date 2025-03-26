#include <stdio.h>

int main() {
    int origemX = 0, origemY = 0, nLinhas, nColunas, cordX, cordY, numQuad, direcao, tempo = 0;

    scanf("%d %d", &nLinhas, &nColunas);
    scanf("%d %d", &cordX, &cordY);
    scanf("%d", &numQuad);

    for (int i = 0; i < numQuad; i++) {

        scanf("%d", &direcao);

        if (direcao == 1)
            origemY++; // norte
        else if (direcao == 2)
            origemY--; // sul
        else if (direcao == 3)
            origemX++; // leste
        else if (direcao == 4)
            origemX--; // oeste

        if (origemY >= cordY - 1 && origemY <= cordY + 1 && origemX >= cordX - 1 && origemX <= cordX + 1) tempo++;
    }

    printf("%d\n", tempo);

    return 0;
}
