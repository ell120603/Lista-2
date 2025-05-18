#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct No {
    char dado;
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

void push(Pilha* p, char c) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = c;
    novo->prox = p->topo;
    p->topo = novo;
}

char pop(Pilha* p) {
    if (esta_vazia(p)) return '\0';
    No* temp = p->topo;
    char c = temp->dado;
    p->topo = temp->prox;
    free(temp);
    return c;
}

void destruir(Pilha* p) {
    while (!esta_vazia(p)) pop(p);
}

int verificar_palindromo(const char* str) {
    Pilha p;
    inicializar(&p);

    int len = strlen(str);
    int i, meio = len / 2;


    for (i = 0; i < meio; i++) {
        push(&p, str[i]);
    }

    if (len % 2 != 0) {
        i++;
    }

    
    while (str[i] != '\0') {
        char topo_pilha = pop(&p);
        if (topo_pilha != str[i]) {
            destruir(&p);
            return 0;  
        }
        i++;
    }

    destruir(&p);
    return 1;  
}
int main() {
    const char* teste1 = "radar";
    const char* teste2 = "level";
    const char* teste3 = "hello";
    const char* teste4 = "madam";

    printf("\"%s\" -> %s\n", teste1, verificar_palindromo(teste1) ? "Palíndromo" : "Não é");
    printf("\"%s\" -> %s\n", teste2, verificar_palindromo(teste2) ? "Palíndromo" : "Não é");
    printf("\"%s\" -> %s\n", teste3, verificar_palindromo(teste3) ? "Palíndromo" : "Não é");
    printf("\"%s\" -> %s\n", teste4, verificar_palindromo(teste4) ? "Palíndromo" : "Não é");

    return 0;
}
