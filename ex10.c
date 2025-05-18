#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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

bool esta_vazia(Pilha* p) {
    return p->topo == NULL;
}

bool push(Pilha* p, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        return false;
    }
    novo->dado = valor;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}
bool pop(Pilha* p, int* valor_removido) {
    if (esta_vazia(p)) {
        printf("Erro: pilha vazia!\n");
        return false;
    }
    No* temp = p->topo;
    *valor_removido = temp->dado;
    p->topo = temp->prox;
    free(temp);
    return true;
}


bool topo(Pilha* p, int* valor_topo) {
    if (esta_vazia(p)) {
        printf("Erro: pilha vazia!\n");
        return false;
    }
    *valor_topo = p->topo->dado;
    return true;
}


void destruir(Pilha* p) {
    int valor;
    while (!esta_vazia(p)) {
        pop(p, &valor);
    }
}
int main() {
    Pilha p;
    inicializar(&p);

    push(&p, 5);
    push(&p, 15);
    push(&p, 25);

    int valor;
    if (topo(&p, &valor))
        printf("Topo: %d\n", valor);  

    while (!esta_vazia(&p)) {
        pop(&p, &valor);
        printf("Removido: %d\n", valor);
    }

    destruir(&p);  

    return 0;
}
