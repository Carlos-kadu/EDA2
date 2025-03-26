#include <stdio.h>
#include <stdlib.h>

typedef struct Semente{
    int semente;
    int nota;
} Semente;

void troca(Semente *a, Semente *b) {
    Semente temp = *a;
    *a = *b;
    *b = temp;
}

int menorNota(Semente a, Semente b) {
    return (a.nota == b.nota ? a.semente < b.semente : a.nota < b.nota);
}

int menorSemente(Semente a, Semente b) {
    return (a.semente == b.semente ? a.nota < b.nota : a.semente < b.semente);
}

void comparaTrocaNota(Semente *a, Semente *b) {
    if (menorNota(*b, *a)) 
        troca(a, b);
}

void comparaTrocaSemente(Semente *a, Semente *b) {
    if (menorSemente(*b, *a))
        troca(a, b);
}

int separaSemente(Semente *v, int l, int r){
    Semente pivo = v[r];
    int j = l;

    for(int i = l; i < r; i++)
        if(menorSemente(v[i], pivo))
        {
            troca(&v[i], &v[j]);
            j++;
        }
        
    troca(&v[j], &v[r]);
    return j;
}

void QuickMediana3(Semente *v, int l, int r){
    if(r - l <= 32) return;

    int mid = (l + r) / 2;

    troca(&v[mid], &v[r - 1]);
    comparaTrocaSemente(&v[l], &v[r - 1]);
    comparaTrocaSemente(&v[l], &v[r]);
    comparaTrocaSemente(&v[r - 1], &v[r]);

    int m = separaSemente(v, l, r);
    QuickMediana3(v, l, m - 1);
    QuickMediana3(v, m + 1, r);
}

void insertionSort(Semente *v, int l, int r){
    int j;
    for(int i = l + 1; i <= r; i++){
        Semente s = v[i];
        for(j = i; j > 0 && menorSemente(s, v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = s;
    }
}

void quicksort(Semente *v, int l, int r){
    QuickMediana3(v, l, r);
    insertionSort(v, l, r);
}

int separaNota(Semente *v, int l, int r){
    Semente pivo = v[r];
    int j = l;

    for(int i = l; i < r; i++)
        if(menorNota(v[i], pivo)){
            troca(&v[i], &v[j]);
            j++;
        }
        
    troca(&v[j], &v[r]);
    return j;
}

void quickselect(Semente *v, int l, int r, int k){
    int mid = (l + r) / 2;
    comparaTrocaNota(&v[mid], &v[r]);
    comparaTrocaNota(&v[l], &v[mid]);
    comparaTrocaNota(&v[r], &v[mid]);

    int m = separaNota(v, l, r);
    if(m > k)
        quickselect(v, l, m - 1, k);
    else if(m < k)
        quickselect(v, m + 1, r, k);
}

Semente *v;

int main(){

    int n;
    scanf(" %d",&n);

    v = (Semente *)malloc(sizeof(Semente) * 10000000);
    if (v == NULL) {
        return 1;
    }

    int i;
    for(i = 0; scanf("%d %d", &v[i].semente, &v[i].nota) == 2; i++);

    quickselect(v, 0, i - 1, n - 1);
    quicksort(v, 0, n - 1);

    for(int j=0; j < n; j++)
        printf("%d %d\n", v[j].semente, v[j].nota);

    free(v);

    return 0;
}
