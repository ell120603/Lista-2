#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int val;
    struct No* prox;
} No;

No* inverter_grupo(No* cabeca, int k) {
    No *atual = cabeca, *prev = NULL, *prox = NULL;
    int count = 0;
    while (atual && count < k) {
        prox = atual->prox;
        atual->prox = prev;
        prev = atual;
        atual = prox;
        count++;
    }
    if (prox)
        cabeca->prox = inverter_grupo(prox, k);
    return prev;
}

void imprimir(No* n) {
    while (n) {
        printf("%d ", n->val);
        No* tmp = n;
        n = n->prox;
        free(tmp);
    }
}

int main() {
    No* h = malloc(sizeof(No));
    h->val = 1; h->prox = malloc(sizeof(No));
    h->prox->val = 2; h->prox->prox = malloc(sizeof(No));
    h->prox->prox->val = 3; h->prox->prox->prox = malloc(sizeof(No));
    h->prox->prox->prox->val = 4; h->prox->prox->prox->prox = NULL;

    No* nova = inverter_grupo(h, 2);
    imprimir(nova);
    return 0;
}