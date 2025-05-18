#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

No* encontrar_meio(No* cabeca) {
    No* lento = cabeca;
    No* rapido = cabeca;

    while (rapido != NULL && rapido->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }
    return lento;
}

void inserir_no_final(No** cabeca, int novo_dado) {
    No* novo_no = (No*) malloc(sizeof(No));
    novo_no->dado = novo_dado;
    novo_no->prox = NULL;

    if (*cabeca == NULL) {
        *cabeca = novo_no;
        return;
    }

    No* atual = *cabeca;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo_no;
}

void imprimir_lista(No* cabeca) {
    No* temp = cabeca;
    while (temp != NULL) {
        printf("%d -> ", temp->dado);
        temp = temp->prox;
    }
    printf("NULL\n");
}

void liberar_lista(No* cabeca) {
    No* atual = cabeca;
    No* proximo;
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

int main() {
    No* lista = NULL;

    inserir_no_final(&lista, 1);
    inserir_no_final(&lista, 2);
    inserir_no_final(&lista, 3);
    inserir_no_final(&lista, 4);
    inserir_no_final(&lista, 5);

    printf("Lista original: ");
    imprimir_lista(lista);

    No* meio = encontrar_meio(lista);
    if (meio != NULL) {
        printf("O nó do meio é: %d\n", meio->dado);
    } else {
        printf("A lista está vazia.\n");
    }
    No* lista_par = NULL;
    inserir_no_final(&lista_par, 10);
    inserir_no_final(&lista_par, 20);
    inserir_no_final(&lista_par, 30);
    inserir_no_final(&lista_par, 40);

    printf("\nLista par original: ");
    imprimir_lista(lista_par);

    No* meio_par = encontrar_meio(lista_par);
    if (meio_par != NULL) {
        printf("O nó do meio da lista par é: %d\n", meio_par->dado);
    } else {
        printf("A lista par está vazia.\n");
    }

    liberar_lista(lista);
    liberar_lista(lista_par);

    return 0;
}