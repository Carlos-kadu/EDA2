#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int qtd = 0, j=0, vetor[1001];
    char sequencia[1001], sequenciaSemEspaco[1001];

    scanf("%d", &qtd);

    while (getchar() != '\n');

    scanf("%[^\n]s", sequencia);

    int qtdcaracteres = strlen(sequencia);
    for (int i = 0; i < qtdcaracteres; i++){
        if(sequencia[i] != ' '){
            sequenciaSemEspaco[j++] = sequencia[i];
        }
    }

    sequenciaSemEspaco[qtd] = '\0';
    
    for (int i = 0; i < qtd; i++){
        vetor[i] = sequenciaSemEspaco[i] - '0';
    }

    return 0;
}
