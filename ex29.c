#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int val;
    struct No* prox;
} No;

No* inverter(No* cabeca) {
    No* prev = NULL;
    while (cabeca) {
        No* prox = cabeca->prox;
        cabeca->prox = prev;
        prev = cabeca;
        cabeca = prox;
    }
    return prev;
}

int eh_palindromo(No* cabeca) {
    if (!cabeca || !cabeca->prox) return 1;
    No *lenta = cabeca, *rapida = cabeca;
    while (rapida->prox && rapida->prox->prox) {
        lenta = lenta->prox;
        rapida = rapida->prox->prox;
    }
    No* segunda = inverter(lenta->prox);
    No* p1 = cabeca, *p2 = segunda;
    while (p2) {
        if (p1->val != p2->val) return 0;
        p1 = p1->prox;
        p2 = p2->prox;
    }
    return 1;
}

int main() {
    No* h = malloc(sizeof(No));
    h->val = 1; h->prox = malloc(sizeof(No));
    h->prox->val = 2; h->prox->prox = malloc(sizeof(No));
    h->prox->prox->val = 1; h->prox->prox->prox = NULL;
    printf("Palindromo: %d\\n", eh_palindromo(h));
    return 0;
}