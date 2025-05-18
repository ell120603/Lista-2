#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

int tamanho(No* n) {
    int t = 0;
    while (n) { t++; n = n->prox; }
    return t;
}

No* encontrar_intersecao(No* a, No* b) {
    int ta = tamanho(a);
    int tb = tamanho(b);
    while (ta > tb) { a = a->prox; ta--; }
    while (tb > ta) { b = b->prox; tb--; }
    while (a && b) {
        if (a == b) return a;
        a = a->prox;
        b = b->prox;
    }
    return NULL;
}

int main() {
    No* comum = malloc(sizeof(No));
    comum->valor = 8;
    comum->prox = NULL;

    No* a = malloc(sizeof(No));
    a->valor = 1; a->prox = comum;

    No* b = malloc(sizeof(No));
    b->valor = 7; b->prox = comum;

    No* inter = encontrar_intersecao(a, b);
    if (inter) printf("Intersecao em: %d\\n", inter->valor);
    else printf("Sem intersecao\\n");

    return 0;
}