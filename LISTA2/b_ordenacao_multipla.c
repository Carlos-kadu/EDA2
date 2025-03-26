#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float valor;
    int linha;
    int coluna;
} Celula;

void swap(Celula *a, Celula *b){
    Celula temp = *a;
    *a = *b;
    *b = temp;
}

void merge(Celula *v, int esqu, int meio, int dire){
    Celula *aux = malloc((dire - esqu + 1) * sizeof(Celula));
    int i = esqu, j = meio + 1, k = 0;

    while (i <= meio && j <= dire){
        if (v[i].valor >= v[j].valor){
            aux[k] = v[i];
            k++;
            i++;
        } else {
            aux[k] = v[j];
            k++;
            j++;
        }
    }

    while (i <= meio){
        aux[k] = v[i];
        k++;
        i++;
    }

    while (j <= dire){
        aux[k] = v[j];
        k++;
        j++;
    }

    for (i = esqu, k = 0; i <= dire; k++, i++)
        v[i] = aux[k];

    free(aux);
}

void mergesort(Celula *v, int esqu, int dire){
    int meio = (esqu + dire) / 2;

    if (esqu < dire){
        mergesort(v, esqu, meio);
        mergesort(v, meio + 1, dire);
        merge(v, esqu, meio, dire);
    }
}

int main(){
    int qtdTestes;

    scanf("%d", &qtdTestes);

    for (int teste = 0; teste < qtdTestes; teste++){
        int linha, coluna;

        scanf("%d %d", &linha, &coluna);

        Celula celulas[linha * coluna];

        for (int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                scanf("%f", &celulas[i * coluna + j].valor);
                celulas[i * coluna + j].linha = i + 1;
                celulas[i * coluna + j].coluna = j + 1;
            }
        }

        mergesort(celulas, 0, linha * coluna - 1);

        for (int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                printf("%d,%d ", celulas[i * coluna + j].linha, celulas[i * coluna + j].coluna);
            }
        }

        printf("\n");
    }

    return 0;
}
