#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> 
typedef struct {
    char *itens;
    int topo;
    int capacidade;
} Pilha;


Pilha* criarPilha(int capacidade) {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->capacidade = capacidade;
    pilha->topo = -1;
    pilha->itens = (char*)malloc(pilha->capacidade * sizeof(char));
    return pilha;
}


int estaVazia(Pilha* pilha) {
    return pilha->topo == -1;
}


int estaCheia(Pilha* pilha) {
    return pilha->topo == pilha->capacidade - 1;
}

void empilhar(Pilha* pilha, char item) {
    if (estaCheia(pilha)) {
        printf("Erro: Pilha cheia\n");
        return;
    }
    pilha->itens[++pilha->topo] = item;
}


char desempilhar(Pilha* pilha) {
    if (estaVazia(pilha)) {
        printf("Erro: Pilha vazia\n");
        return '\0'; 
    return pilha->itens[pilha->topo--];
}
}


char topo(Pilha* pilha) {
    if (estaVazia(pilha)) {
        printf("Erro: Pilha vazia\n");
        return '\0'; 
    }
    return pilha->itens[pilha->topo];
}


char* inverterString(const char* texto) {
    int tamanho = strlen(texto);
    Pilha* pilha = criarPilha(tamanho);
    char* textoInvertido = (char*)malloc((tamanho + 1) * sizeof(char));

   
    for (int i = 0; i < tamanho; i++) {
        empilhar(pilha, texto[i]);
    }


    for (int i = 0; i < tamanho; i++) {
        textoInvertido[i] = desempilhar(pilha);
    }
    textoInvertido[tamanho] = '\0'; 

   
    free(pilha->itens);
    free(pilha);

    return textoInvertido;
}

int main() {
    const char* stringOriginal1 = "hello";
    char* stringInvertida1 = inverterString(stringOriginal1);
    printf("String original: %s\n", stringOriginal1);
    printf("String invertida: %s\n", stringInvertida1);
    free(stringInvertida1);

    const char* stringOriginal2 = "Brasil";
    char* stringInvertida2 = inverterString(stringOriginal2);
    printf("String original: %s\n", stringOriginal2);
    printf("String invertida: %s\n", stringInvertida2);
    free(stringInvertida2);

    return 0;
}