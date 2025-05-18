#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

int inserir_posicao_especifica(No** lista, int valor, int posicao) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if (posicao == 0) {
        novo->proximo = *lista;
        *lista = novo;
        return 1;
    }

    No* temp = *lista;
    for (int i = 0; i < posicao - 1 && temp != NULL; i++) {
        temp = temp->proximo;
    }

    if (temp == NULL) {
        free(novo);
        return 0; 
    }

    novo->proximo = temp->proximo;
    temp->proximo = novo;

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
    printf("Digite um valor para inserir na lista: ");
    scanf("%d", &valor);
    int posicao;
    printf("Digite a posição para inserir o valor: ");
    scanf("%d", &posicao);
    if (inserir_posicao_especifica(&lista, valor, posicao)) {
        printf("Valor %d inserido na posição %d.\n", valor, posicao);
    } else {
        printf("Falha ao inserir o valor na posição %d.\n", posicao);
    }
    printf("Valores da lista:\n");
    No* temp = lista;
    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->proximo;
    }

}