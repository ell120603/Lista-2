#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct {
    No* topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = NULL;
}

int esta_vazia(Pilha* p) {
    return p->topo == NULL;
}

void push(Pilha* p, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

int pop(Pilha* p) {
    if (esta_vazia(p)) return -1;
    No* temp = p->topo;
    int valor = temp->dado;
    p->topo = temp->prox;
    free(temp);
    return valor;
}

int topo(Pilha* p) {
    if (esta_vazia(p)) return -1;
    return p->topo->dado;
}

void destruir(Pilha* p) {
    while (!esta_vazia(p)) pop(p);
}

void ordenar_pilha(Pilha* original) {
    Pilha auxiliar;
    inicializar(&auxiliar);

    while (!esta_vazia(original)) {
        int tmp = pop(original);

        while (!esta_vazia(&auxiliar) && topo(&auxiliar) > tmp) {
            push(original, pop(&auxiliar));
        }

        push(&auxiliar, tmp);
    }

    while (!esta_vazia(&auxiliar)) {
        push(original, pop(&auxiliar));
    }
}
int main() {
    Pilha p;
    inicializar(&p);

    push(&p, 3);
    push(&p, 1);
    push(&p, 4);
    push(&p, 2);

    ordenar_pilha(&p);

    printf("Pilha ordenada (menor no topo):\n");
    while (!esta_vazia(&p)) {
        printf("%d\n", pop(&p));
    }

    return 0;
}
