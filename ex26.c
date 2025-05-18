#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int avaliar_posfixa(const char* expr) {
    int stack[100], topo = -1;
    char* copia = strdup(expr);
    char* token = strtok(copia, " ");
    while (token) {
        if (isdigit(token[0])) stack[++topo] = atoi(token);
        else {
            int b = stack[topo--];
            int a = stack[topo--];
            switch (token[0]) {
                case '+': stack[++topo] = a + b; break;
                case '-': stack[++topo] = a - b; break;
                case '*': stack[++topo] = a * b; break;
                case '/': stack[++topo] = a / b; break;
            }
        }
        token = strtok(NULL, " ");
    }
    int resultado = stack[topo];
    free(copia);
    return resultado;
}

int main() {
    const char* expr = "3 4 + 2 *";
    printf("Resultado: %d\\n", avaliar_posfixa(expr));
    return 0;
}