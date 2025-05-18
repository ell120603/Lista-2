#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_MAX 100

typedef struct {
    int dados[TAMANHO_MAX];
    int inicio;   
    int fim;      
    int tamanho;    
} Fila;


void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}


bool esta_vazia(Fila *f) {
    return f->tamanho == 0;
}

bool esta_cheia(Fila *f) {
    return f->tamanho == TAMANHO_MAX;
}


bool enfileirar(Fila *f, int valor) {
    if (esta_cheia(f)) {
        printf("Erro: fila cheia!\n");
        return false;
    }
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % TAMANHO_MAX;
    f->tamanho++;
    return true;
}


bool desenfileirar(Fila *f, int *valor_removido) {
    if (esta_vazia(f)) {
        printf("Erro: fila vazia!\n");
        return false;
    }
    *valor_removido = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % TAMANHO_MAX;
    f->tamanho--;
    return true;
}

bool frente(Fila *f, int *valor_frente) {
    if (esta_vazia(f)) {
        printf("Erro: fila vazia!\n");
        return false;
    }
    *valor_frente = f->dados[f->inicio];
    return true;
}
int main() {
    Fila f;
    inicializar(&f);

    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);

    int valor;
    if (frente(&f, &valor)) {
        printf("Frente da fila: %d\n", valor);  
    }

    while (!esta_vazia(&f)) {
        desenfileirar(&f, &valor);
        printf("Removido: %d\n", valor);
    }

    return 0;
}
