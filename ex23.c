#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int val;
    struct No* prox;
} No;

No* rotacionar_lista(No* cabeca, int k) {
    if (!cabeca || k == 0) return cabeca;
    No* atual = cabeca;
    int tamanho = 1;
    while (atual->prox) {
        atual = atual->prox;
        tamanho++;
    }
    atual->prox = cabeca; 

    k = k % tamanho;
    for (int i = 0; i < tamanho - k; i++)
        atual = atual->prox;

    No* nova_cabeca = atual->prox;
    atual->prox = NULL;
    return nova_cabeca;
}

void imprimir(No* n) {
    while (n) {
        printf("%d ", n->val);
        No* temp = n;
        n = n->prox;
        free(temp);
    }
}

int main() {
    No* h = malloc(sizeof(No));
    h->val = 1; h->prox = malloc(sizeof(No));
    h->prox->val = 2; h->prox->prox = malloc(sizeof(No));
    h->prox->prox->val = 3; h->prox->prox->prox = NULL;

    h = rotacionar_lista(h, 2);
    imprimir(h);
    return 0;
}