#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_MAX 100


typedef struct {
    int dados[TAMANHO_MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

bool esta_vazia(Pilha *p) {
    return p->topo == -1;
}


bool push(Pilha *p, int valor) {
    if (p->topo >= TAMANHO_MAX - 1) {
        printf("Erro: pilha cheia!\n");
        return false;
    }
    p->dados[++(p->topo)] = valor;
    return true;
}


bool pop(Pilha *p, int *valor_removido) {
    if (esta_vazia(p)) {
        printf("Erro: pilha vazia!\n");
        return false;
    }
    *valor_removido = p->dados[(p->topo)--];
    return true;
}

bool topo(Pilha *p, int *valor_topo) {
    if (esta_vazia(p)) {
        printf("Erro: pilha vazia!\n");
        return false;
    }
    *valor_topo = p->dados[p->topo];
    return true;
}
int main() {
    Pilha p;
    inicializar(&p);

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);

    int valor;
    if (topo(&p, &valor))
        printf("Topo: %d\n", valor);  

    while (!esta_vazia(&p)) {
        pop(&p, &valor);
        printf("Removido: %d\n", valor);
    }

    return 0;
}
