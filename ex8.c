#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

int impressao_reversa_pilha(No* lista) {
    No* pilha[100]; 
    int topo = -1;

    No* temp = lista;
    while (temp != NULL) {
        pilha[++topo] = temp;
        temp = temp->proximo;
    }

    while (topo >= 0) {
        printf("%d ", pilha[topo--]->valor);
    }
    printf("\n");

    return 1; 
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

    printf("Valores da lista em ordem reversa:\n");
    impressao_reversa_pilha(lista);

    return 0;
}   