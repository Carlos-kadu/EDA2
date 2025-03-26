#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int esq, int meio, int dir){
    int *aux = malloc((dir-esq+1)*sizeof(int));
    int i = esq, j = meio+1, k = 0;

    while(i <= meio && j <= dir){
        if(v[i] < v[j]){
            aux[k] = v[i];
            k++;
            i++;
        } else{
            aux[k] = v[j];
            k++;
            j++;
        }
    }

    while(i<=meio){
        aux[k] = v[i];
        k++;
        i++;
    }

    while(j<=dir){
        aux[k] = v[j];
        k++;
        j++;
    }
	
	for(i=esq, k=0; i<=dir; k++, i++) v[i] = aux[k];

	free(aux);
}


void mergesort(int *v, int esq, int dir){
    int meio = (esq + dir)/2;

    if(esq < dir){
        mergesort(v, esq, meio);
        mergesort(v, meio+1, dir);
        merge(v, esq, meio, dir);
    }
}


int main(){

    int qtdLinhas = 8, vetor[800000], qtdElementos, cont=0;

    for(int i = 0; i < qtdLinhas; i++){
        scanf("%d", &qtdElementos);

        for(int j = 0+cont; j < qtdElementos+cont; j++){
            scanf("%d", &vetor[j]);
        }

        cont += qtdElementos;
    }

    mergesort(vetor, 0, cont-1);

    for(int i = 0; i < cont; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}