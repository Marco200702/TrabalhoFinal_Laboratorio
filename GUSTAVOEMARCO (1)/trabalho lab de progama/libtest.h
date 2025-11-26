#ifndef LIBTEST_H
#define LIBTEST_H

#include <stdio.h>
#include "libestruturas.h"

typedef struct {
    char operacao[32];
    int valor;
    char esperado[256];
} Teste;

int executarTeste(Teste* t, Pilha* p, Fila* f, char* actual, size_t size);
void registrarResultado(FILE* out, int numero, Teste* t, const char* actual, int sucesso);

#endif
