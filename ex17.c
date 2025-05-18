#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char bin[32];
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

void enfileirar(Fila* f, const char* bin) {
    No* novo = malloc(sizeof(No));
    strcpy(novo->bin, bin);
    novo->prox = NULL;
    if (!f->inicio) f->inicio = f->fim = novo;
    else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

char* desenfileirar(Fila* f) {
    if (!f->inicio) return NULL;
    No* temp = f->inicio;
    char* res = strdup(temp->bin);
    f->inicio = temp->prox;
    if (!f->inicio) f->fim = NULL;
    free(temp);
    return res;
}

void gerar_binarios(int N) {
    Fila f = {NULL, NULL};
    enfileirar(&f, "1");
    for (int i = 0; i < N; i++) {
        char* s = desenfileirar(&f);
        printf("%s\n", s);

        char s1[32], s2[32];
        sprintf(s1, "%s0", s);
        sprintf(s2, "%s1", s);
        enfileirar(&f, s1);
        enfileirar(&f, s2);
        free(s);
    }
}

int main() {
    gerar_binarios(10);
    return 0;
}
