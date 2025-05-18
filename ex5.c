#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

void removerInicio(No** lista) {
    if (*lista == NULL) {
        printf("Lista vazia. Não há elementos para remover.\n");
        return;
    }
    No* temp = *lista;
    *lista = (*lista)->proximo;
    free(temp);
}

int main(){
    No* lista = NULL;
    int valor;

    printf("Digite um valor para inserir no início da lista (ou -1 para sair): ");
    scanf("%d", &valor);
    while (valor != -1) {
        No* novo = (No*)malloc(sizeof(No));
        novo->valor = valor;
        novo->proximo = lista;
        lista = novo;
        printf("Digite um valor para inserir no início da lista (ou -1 para sair): ");
        scanf("%d", &valor);
    }

    printf("Valores da lista antes de remover:\n");
    No* temp = lista;
    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->proximo;
    }
    printf("\n");

    removerInicio(&lista);

    printf("Valores da lista após remover o primeiro elemento:\n");
    temp = lista;
    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->proximo;
    }
    printf("\n");

    return 0;
}