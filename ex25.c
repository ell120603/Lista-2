#include <stdio.h>
#define MAX 100

typedef struct {
    int dados[MAX];
    int topo1, topo2;
} DuasPilhas;

void inicializar(DuasPilhas* p) {
    p->topo1 = -1;
    p->topo2 = MAX;
}

void push1(DuasPilhas* p, int v) {
    if (p->topo1 + 1 < p->topo2) p->dados[++p->topo1] = v;
}

void push2(DuasPilhas* p, int v) {
    if (p->topo2 - 1 > p->topo1) p->dados[--p->topo2] = v;
}

int pop1(DuasPilhas* p) { return p->dados[p->topo1--]; }
int pop2(DuasPilhas* p) { return p->dados[p->topo2++]; }

int main() {
    DuasPilhas p;
    inicializar(&p);
    push1(&p, 1); push2(&p, 9);
    printf("Pop1: %d, Pop2: %d\\n", pop1(&p), pop2(&p));
    return 0;
}