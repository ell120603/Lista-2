#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct No {
    int valor;
    struct No* proximo;
} No;

int contarNos(No* lista) {
    int contador = 0;
    No* temp = lista;
    while (temp != NULL) {
        contador++;
        temp = temp->proximo;
    }
    return contador;
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

    printf("Número de nós na lista: %d\n", contarNos(lista));

    return 0;
}