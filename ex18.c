#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int frente, fim, tamanho;
} Fila;

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void enfileirar(Fila* f, int val) {
    if (f->tamanho < MAX) {
        f->dados[f->fim] = val;
        f->fim = (f->fim + 1) % MAX;
        f->tamanho++;
    }
}

int desenfileirar(Fila* f) {
    if (f->tamanho == 0) return -1;
    int val = f->dados[f->frente];
    f->frente = (f->frente + 1) % MAX;
    f->tamanho--;
    return val;
}

void inverter_primeiros_k(Fila* f, int k) {
    Pilha p = {.topo = -1};
    for (int i = 0; i < k; i++) p.dados[++p.topo] = desenfileirar(f);
    while (p.topo >= 0) enfileirar(f, p.dados[p.topo--]);
    for (int i = 0; i < f->tamanho - k; i++) enfileirar(f, desenfileirar(f));
}

int main() {
    Fila f = {.frente = 0, .fim = 0, .tamanho = 0};
    for (int i = 1; i <= 10; i++) enfileirar(&f, i);
    inverter_primeiros_k(&f, 5);
    while (f.tamanho > 0) printf("%d ", desenfileirar(&f));
    return 0;
}
