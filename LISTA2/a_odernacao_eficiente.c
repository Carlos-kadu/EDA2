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

int main(){
    int qtd;
    scanf("%d", &qtd);

    int v[qtd];

    for(int i=0; i<qtd; i++){
        scanf("%d", &v[i]);
    }

    mergesort(v, 0, qtd-1);

    for(int i=0; i<qtd; i++){
        printf("%d ", v[i]);
    }

    printf("\n");


    return 0;
}
