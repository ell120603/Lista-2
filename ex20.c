#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

No* novo_no(int val) {
    No* n = malloc(sizeof(No));
    n->valor = val;
    n->prox = NULL;
    return n;
}

No* unir_listas_ordenadas(No* a, No* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->valor < b->valor) {
        a->prox = unir_listas_ordenadas(a->prox, b);
        return a;
    } else {
        b->prox = unir_listas_ordenadas(a, b->prox);
        return b;
    }
}

void imprimir(No* n) {
    while (n) {
        printf("%d ", n->valor);
        n = n->prox;
    }
}

int main() {
    No* l1 = novo_no(1);
    l1->prox = novo_no(3);
    l1->prox->prox = novo_no(5);

    No* l2 = novo_no(2);
    l2->prox = novo_no(4);
    l2->prox->prox = novo_no(6);

    No* unida = unir_listas_ordenadas(l1, l2);
    imprimir(unida);
    return 0;
}