#include <stdio.h>
#include <stdlib.h> // Importante para usar malloc e free

int trapping_rain_water(int* altura, int n) {
    int *esquerda = (int*)malloc(n * sizeof(int));
    int *direita = (int*)malloc(n * sizeof(int));

    if (!esquerda || !direita) {
        fprintf(stderr, "Erro na alocação de memória\n");
        free(esquerda);
        free(direita);
        return -1; 
    }

    esquerda[0] = altura[0];
    for (int i = 1; i < n; i++)
        esquerda[i] = altura[i] > esquerda[i-1] ? altura[i] : esquerda[i-1];

    direita[n-1] = altura[n-1];
    for (int i = n-2; i >= 0; i--)
        direita[i] = altura[i] > direita[i+1] ? altura[i] : direita[i+1];

    int agua = 0;
    for (int i = 0; i < n; i++) {
        int menor = esquerda[i] < direita[i] ? esquerda[i] : direita[i];
        agua += menor - altura[i];
    }

    free(esquerda); 
    free(direita);  
    return agua;
}

int main() {
    int h[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(h)/sizeof(h[0]);
    printf("Agua retida: %d\n", trapping_rain_water(h, n));
    return 0;
}