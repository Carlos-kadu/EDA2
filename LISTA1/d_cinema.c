#include <stdio.h>

int main() {
    int num_fileiras, lugares_por_fileira;
    char bilhete[4];

    scanf("%d %d", &num_fileiras, &lugares_por_fileira);

    char assentos[num_fileiras][lugares_por_fileira];

    for (int i = 0; i < num_fileiras; i++) {
        for (int j = 0; j < lugares_por_fileira; j++) {
            assentos[i][j] = '-';
        }
    }

    while (scanf("%s", bilhete) != EOF) {
        int fileira = bilhete[0] - 'A';
        int lugar = 0;
        for (int i = 1; bilhete[i] != '\0'; i++) {
            lugar = lugar * 10 + (bilhete[i] - '0');
        }
        lugar--; 
        assentos[fileira][lugar] = 'X';
    }

    printf("  ");
    for (int i = 1; i <= lugares_por_fileira; i++) {
        printf("%02d ", i);
    }
    printf("\n");
    for (int i = num_fileiras - 1; i >= 0; i--) { 
        printf("%c ", 'A' + i);
        for (int j = 0; j < lugares_por_fileira; j++) {
            printf("%s ", assentos[i][j] == 'X' ? "XX" : "--");
        }
        printf("\n");
    }

    return 0;
}
