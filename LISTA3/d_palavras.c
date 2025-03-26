#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10000

typedef struct No {
    char* key;
    int count;
    struct No* prox;
} No;

typedef struct TabelaHash {
    No* table[TAM];
} TabelaHash;

int hash(char* key) {
    unsigned int hashValue = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hashValue = 31 * hashValue + key[i];
    }
    return hashValue % TAM;
}

TabelaHash* create_table() {
    TabelaHash* hashTable = malloc(sizeof(TabelaHash));
    for (int i = 0; i < TAM; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

void insert(TabelaHash* hashTable, char* key) {
    int index = hash(key);
    No* current = hashTable->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            current->count++;
            return;
        }
        current = current->prox;
    }
    No* novoNo = malloc(sizeof(No));
    novoNo->key = strdup(key);
    novoNo->count = 1;
    novoNo->prox = hashTable->table[index];
    hashTable->table[index] = novoNo;
}

typedef struct {
    char* palavra;
    int count;
} Count;

int compare(const void* a, const void* b) {
    const Count* A = (const Count*)a;
    const Count* B = (const Count*)b;
    return A->count - B->count;
}

int search(TabelaHash* hashTable, char* key) {
    unsigned int index = hash(key);
    No* current = hashTable->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->count;
        }
        current = current->prox;
    }
    return 0; 
}

void reset_count(TabelaHash* hashTable, char* key) {
    unsigned int index = hash(key);
    No* current = hashTable->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            current->count = 0;
            return;
        }
        current = current->prox;
    }
}

int main() {
    TabelaHash* hashTable = create_table();
    char palavra[1000];
    int opt;

    while (scanf("%d %s", &opt, palavra) != EOF) {
        if(opt == 1){
            insert(hashTable, palavra);
        }if(opt == 3){
            reset_count(hashTable, palavra);
        }if(opt == 2){
            printf("%d\n", search(hashTable, palavra));
        }
    }

    return 0;
}