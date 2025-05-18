#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

void remover_todas_ocorrencias(No** cabeca, int val) {
    while (*cabeca && (*cabeca)->valor == val) {
        No* temp = *cabeca;
        *cabeca = (*cabeca)->prox;
        free(temp);
    }
    No* atual = *cabeca;
    while (atual && atual->prox) {
        if (atual->prox->valor == val) {
            No* temp = atual->prox;
            atual->prox = temp->prox;
            free(temp);
        } else {
            atual = atual->prox;
        }
    }
}

int main() {
    No* h = malloc(sizeof(No));
    h->valor = 1;
    h->prox = malloc(sizeof(No));
    h->prox->valor = 2;
    h->prox->prox = malloc(sizeof(No));
    h->prox->prox->valor = 1;
    h->prox->prox->prox = NULL;

    remover_todas_ocorrencias(&h, 1);
    while (h) {
        printf("%d ", h->valor);
        No* tmp = h;
        h = h->prox;
        free(tmp);
    }
    return 0;
}