#include <stdio.h>
#include <stdlib.h>

#define TAM_MEMORIA 3
#define TAM_REFERENCIAS 12

typedef struct {
    int paginas[TAM_MEMORIA];
    int contador;
} Memoria;

void inicializar_memoria(Memoria *memoria) {
    for (int i = 0; i < TAM_MEMORIA; i++) {
        memoria->paginas[i] = -1;
    }
    memoria->contador = 0;
}

int main() {
    Memoria memoria;
    inicializar_memoria(&memoria);
    printf("Memória inicializada.\n");
    return 0;
}