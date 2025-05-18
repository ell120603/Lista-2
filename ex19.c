#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

int detectar_ciclo(No* inicio) {
    No* lento = inicio;
    No* rapido = inicio;
    while (rapido && rapido->prox) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
        if (lento == rapido) return 1;
    }
    return 0;
}

int main() {
    No* a = malloc(sizeof(No));
    No* b = malloc(sizeof(No));
    No* c = malloc(sizeof(No));
    a->valor = 1; a->prox = b;
    b->valor = 2; b->prox = c;
    c->valor = 3; c->prox = b; 

    printf("Ciclo: %d\\n", detectar_ciclo(a)); 
    return 0;
}