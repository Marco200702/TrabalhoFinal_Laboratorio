#ifndef LIB_TEST_H
#define LIB_TEST_H

#include <stdio.h>
#include "libestruturas.h"

typedef struct {
    char operacao[20];
    int valor1;
    int esperado;
}Teste;

int ler_Teste(FILE *in, Teste *texto);
int executar_Teste(Teste *texto, Pilha *pilha, Fila *fila);
void registrar_Resultado(FILE *out, Teste *texto, int num, int sucesso);

#endif
