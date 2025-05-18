#include <stdio.h>
#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

typedef struct {
    Pilha entrada, saida;
} FilaComPilhas;

void push(Pilha* p, int val) { p->dados[++p->topo] = val; }
int pop(Pilha* p) { return p->dados[p->topo--]; }
int vazia(Pilha* p) { return p->topo == -1; }

void enfileirar(FilaComPilhas* f, int val) {
    push(&f->entrada, val);
}

int desenfileirar(FilaComPilhas* f) {
    if (vazia(&f->saida))
        while (!vazia(&f->entrada))
            push(&f->saida, pop(&f->entrada));
    return pop(&f->saida);
}

int main() {
    FilaComPilhas f = {{.topo = -1}, {.topo = -1}};
    enfileirar(&f, 1); enfileirar(&f, 2);
    printf("%d\\n", desenfileirar(&f));
    enfileirar(&f, 3);
    printf("%d\\n", desenfileirar(&f));
    printf("%d\\n", desenfileirar(&f));
    return 0;
}