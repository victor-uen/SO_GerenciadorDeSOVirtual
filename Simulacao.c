#include <stdio.h>
#include <stdlib.h>

#define TAM_MEMORIA 3
#define TAM_DISCO 10
#define TOTAL_PAGINAS 10
#define TAM_REFERENCIAS 12

typedef struct {
    int paginas[TAM_MEMORIA];
    int contador;
} Memoria;

typedef struct {
    int pagina_virtual;
    int quadro_fisico;
    int presente;
} EntradaTabela;

int disco[TAM_DISCO];
EntradaTabela tabela_paginas[TOTAL_PAGINAS];

void inicializar_memoria(Memoria *memoria) {
    for (int i = 0; i < TAM_MEMORIA; i++)
        memoria->paginas[i] = -1;
    memoria->contador = 0;
    for (int i = 0; i < TAM_DISCO; i++)
        disco[i] = i;
}

void inicializar_tabela_paginas() {
    for (int i = 0; i < TOTAL_PAGINAS; i++) {
        tabela_paginas[i].pagina_virtual = i;
        tabela_paginas[i].quadro_fisico = -1;
        tabela_paginas[i].presente = 0;
    }
}

void exibir_memoria(Memoria *memoria) {
    printf("Memória: ");
    for (int i = 0; i < TAM_MEMORIA; i++)
        if (memoria->paginas[i] == -1)
            printf("[ ] ");
        else
            printf("[%d] ", memoria->paginas[i]);
    printf("\n");
}

int pagina_na_memoria(Memoria *memoria, int pagina) {
    for (int i = 0; i < TAM_MEMORIA; i++)
        if (memoria->paginas[i] == pagina)
            return 1;
    return 0;
}

int main() {
    Memoria memoria;
    inicializar_memoria(&memoria);
    inicializar_tabela_paginas();

    int referencias[TAM_REFERENCIAS] = {0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1};
    int page_faults = 0;

    for (int i = 0; i < TAM_REFERENCIAS; i++) {
        int pagina = referencias[i];
        printf("\nAcessando página %d...\n", pagina);

        if (!pagina_na_memoria(&memoria, pagina)) {
            printf("-> Page Fault! Página %d não está na memória.\n", pagina);
            page_faults++;
        } else {
            printf("-> Página %d já está carregada.\n", pagina);
        }

        exibir_memoria(&memoria);
    }

    printf("\nTotal de Page Faults: %d\n", page_faults);
    return 0;
}