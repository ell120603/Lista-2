#include <stdio.h>
#include <stdlib.h>

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

char topo(Pilha* p) {
    if (esta_vazia(p)) return '\0';
    return p->topo->dado;
}

void destruir(Pilha* p) {
    while (!esta_vazia(p)) {
        pop(p);
    }
}

int verificar_balanceamento(const char* str) {
    Pilha p;
    inicializar(&p);

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        if (c == '(' || c == '[' || c == '{') {
            push(&p, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (esta_vazia(&p)) {
                destruir(&p);
                return 0;
            }

            char topo_pilha = pop(&p);

            if ((c == ')' && topo_pilha != '(') ||
                (c == ']' && topo_pilha != '[') ||
                (c == '}' && topo_pilha != '{')) {
                destruir(&p);
                return 0;
            }
        }
    }

    int resultado = esta_vazia(&p);
    destruir(&p);
    return resultado;
}
int main() {
    const char* teste1 = "({[]})";
    const char* teste2 = "([)]";
    const char* teste3 = "{[()]}[]";
    const char* teste4 = "{[(])}";

    printf("Teste 1: %s -> %s\n", teste1, verificar_balanceamento(teste1) ? "Válido" : "Inválido");
    printf("Teste 2: %s -> %s\n", teste2, verificar_balanceamento(teste2) ? "Válido" : "Inválido");
    printf("Teste 3: %s -> %s\n", teste3, verificar_balanceamento(teste3) ? "Válido" : "Inválido");
    printf("Teste 4: %s -> %s\n", teste4, verificar_balanceamento(teste4) ? "Válido" : "Inválido");

    return 0;
}
