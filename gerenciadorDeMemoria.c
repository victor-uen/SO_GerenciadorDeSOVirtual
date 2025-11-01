#include <stdio.h>
#include <stdlib.h>

#define TAM_MEMORIA 3
#define TAM_REFERENCIAS 12
#define TAM_DISCO 10

typedef struct {
    int paginas[TAM_MEMORIA];
    int contador;
} Memoria;

int disco[TAM_DISCO];

void inicializar_memoria(Memoria *memoria) {
    for (int i = 0; i < TAM_MEMORIA; i++)
        memoria->paginas[i] = -1;
    memoria->contador = 0;

    for (int i = 0; i < TAM_DISCO; i++)
        disco[i] = i;
}

void exibir_memoria(Memoria *memoria) {
    printf("Memória: ");
    for (int i = 0; i < TAM_MEMORIA; i++) {
        if (memoria->paginas[i] == -1)
            printf("[ ] ");
        else
            printf("[%d] ", memoria->paginas[i]);
    }
    printf("\n");
}

int main() {
    Memoria memoria;
    inicializar_memoria(&memoria);
    printf("Memória inicializada com sucesso!\n");
    return 0;
}