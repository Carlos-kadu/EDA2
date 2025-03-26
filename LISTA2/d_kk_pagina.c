#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int esqu, int meio, int dire){
	int *aux = malloc((dire-esqu+1)*sizeof(int));
	int i=esqu, j=meio+1, k=0;
	
	while(i<=meio && j<=dire){
		if(v[i] <= v[j]){
            aux[k] = v[i];  
            k++;
            i++;
        } 
		else {
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

	while(j<=dire){
        aux[k] = v[j];
        k++;
        j++;
    }
	
	for(i=esqu, k=0; i<=dire; k++, i++) v[i]=aux[k];

	free(aux);
}

void mergesort(int *v, int esqu, int dire){
	int meio=(esqu+dire)/2;
    
	if(esqu<dire){
		mergesort(v, esqu, meio);
		mergesort(v, meio+1, dire);
		merge(v, esqu, meio, dire);
	}
}

void troca(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int particiona(int *v, int e, int d){

	int c=v[d];
	
	int k=e, j=e;

	while(k<d){
		if(v[k]<=c){
			troca(&v[k], &v[j]);
			j++;
		}
		k++;
	}

	troca(&v[d], &v[j]);
	return j;
}

int quickselect(int *v, int e, int d, int k){
	if(e<d){
		int j = particiona(v, e, d);
		if(k<j) quickselect(v, e, j-1, k);
		if(k>j) quickselect(v, j+1, d, k);
	}
    
}

int main(){
    int qtdProdutos, pg, qtdPorPg;

    int qtd = scanf("%d %d %d", &qtdProdutos, &pg, &qtdPorPg);
    if(qtd != 3) return 1;
    int count = pg*qtdPorPg;

    int vetor[qtdProdutos];

    for(int i = 0; i < qtdProdutos; i++){
        int qtdID = scanf("%d", &vetor[i]);
        if(qtdID != 1) return 1;
    }

    int esq = quickselect(vetor, 0, qtdProdutos-1, count);
    int dir = quickselect(vetor, esq, qtdProdutos-1, count+qtdPorPg);
    //printf("Qtd pagina: %d ", qtdPorPg+count);

    //printf("Esquerda e direita: %d %d\n", esq, dir);

    mergesort(vetor, esq, dir);

    for(int i = 0; i < qtdPorPg; i++){
        printf("%d\n", vetor[count]);
        count++;
    }

    return 0;
}
