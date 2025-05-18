#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int val[MAX];
    int min[MAX];
    int topo;
} PilhaMin;

void inicializar(PilhaMin* p) {
    p->topo = -1;
}

void push(PilhaMin* p, int v) {
    p->val[++p->topo] = v;
    if (p->topo == 0) p->min[p->topo] = v;
    else p->min[p->topo] = v < p->min[p->topo - 1] ? v : p->min[p->topo - 1];
}

int pop(PilhaMin* p) {
    return p->val[p->topo--];
}

int obter_minimo(PilhaMin* p) {
    return p->min[p->topo];
}

int main() {
    PilhaMin p;
    inicializar(&p);
    push(&p, 3); push(&p, 5); push(&p, 2);
    printf("Minimo: %d\\n", obter_minimo(&p));
    pop(&p);
    printf("Minimo: %d\\n", obter_minimo(&p));
    return 0;
}