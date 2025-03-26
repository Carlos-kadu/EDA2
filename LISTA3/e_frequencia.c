#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char ch;
    int freq;
} Frequencia;

int compara(const void *a, const void *b) {
    Frequencia *cf1 = (Frequencia *)a;
    Frequencia *cf2 = (Frequencia *)b;

    if (cf1->freq == cf2->freq)
        return cf1->ch - cf2->ch;
    return cf1->freq - cf2->freq;
}

int main() {
    char linha[1000];
    Frequencia caracFreq[128];

    while (scanf("%s", linha) != EOF) {
        int freq[128] = {0};

        int tam = strlen(linha);
        for (int i = 0; i < tam; i++) {
            if (linha[i] != '\n')
                freq[(int)linha[i]]++;
        }

        int count = 0;
        for (int i = 0; i < 128; i++) {
            if (freq[i] > 0) {
                caracFreq[count].ch = (char)i;
                caracFreq[count].freq = freq[i];
                count++;
            }
        }

        qsort(caracFreq, count, sizeof(Frequencia), compara);

        for (int i = 0; i < count; i++) {
            printf("%d %d\n", (int)caracFreq[i].ch, caracFreq[i].freq);
        }

        printf("\n");
    }
    
    return 0;
}
