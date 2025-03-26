#include <stdio.h>
#include <string.h>

void calc_posOrdem(char *preOrdem, char *emOrdem, int n, char *posOrdem, int *index) {
    if (n == 0) {
        return;
    }
    
    char raiz = preOrdem[0];
    int indexEmOrdem = 0;
    
    while (emOrdem[indexEmOrdem] != raiz) {
        indexEmOrdem++;
    }
    
    calc_posOrdem(preOrdem + 1, emOrdem, indexEmOrdem, posOrdem, index);
    calc_posOrdem(preOrdem + 1 + indexEmOrdem, emOrdem + indexEmOrdem + 1, n - indexEmOrdem - 1, posOrdem, index);
    
    posOrdem[(*index)++] = raiz;
}

int main() {
    int qtd;
    scanf("%d", &qtd);
    
    while (qtd) {
        int N;
        char preOrdem[53], emOrdem[53];
        
        scanf("%d %s %s", &N, preOrdem, emOrdem);
        
        char posOrdem[53];
        int index = 0;
        
        calc_posOrdem(preOrdem, emOrdem, N, posOrdem, &index);
        posOrdem[index] = '\0';
        
        printf("%s\n", posOrdem);
        qtd--;
    }
    
    return 0;
}
