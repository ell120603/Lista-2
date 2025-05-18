#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

int buscarElemento(No* lista, int valor) {
    No* temp = lista;
    while (temp != NULL) {
        if (temp->valor == valor) {
            return 1;
            printf("Elemento encontrado: %d\n", valor);
        }
        temp = temp->proximo;
    }
    return 0; 
    printf("Elemento não encontrado: %d\n", valor);
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

    printf("Digite um valor para buscar na lista: ");
    scanf("%d", &valor);
    if (buscarElemento(lista, valor)) {
        printf("Elemento encontrado: %d\n", valor);
    } else {
        printf("Elemento não encontrado: %d\n", valor);
    }

    return 0;
}