#include <studio.h>
#include <string.h>
#include "libtest.h"

//FUNÇÃO PARA LER TESTE
int ler_Teste(FILE *in, Teste *texto) {
    return fscanf(in, "%s %d", t->operacao, &t->valor1) == 2;
}

//FUNÇÃO PARA EXECUTAR O TEXTE
int executar_Teste(Teste *texto, Pilha *pilha, Fila *fila) {
    int resultado = 0;
    int esperado = 0;

    if (strcmp(texto->operacao, "PUSH") == 0) {
        push(pilha, t->valor1);
        return 1;
    } 
    else if (strcmp(texto->operacao, "POP") == 0) {
        resultado = pop(pilha);
        return resultado == texto->valor1;
    } 
    else if (strcmp(texto->operacao, "TOP") == 0) {
        resultado = top(pilha);
        return resultado == texto->valor1;
    } 
    else if (strcmp(texto->operacao, "ENQUEUE") == 0) {
        enqueue(fila, texto->valor1);
        return 1;
    } 
    else if (strcmp(texto->operacao, "DEQUEUE") == 0) {
        resultado = dequeue(fila);
        return resultado == texto->valor1;
    }
    return 0; // operação desconhecida
}

#FUNÇÃO PARA REGISTRAR O RESULTADO
void registrarResultado(FILE *out, Teste *texto, int num, int sucesso) {
    fprintf(out, "Teste %d: %s(%d) -> %s\n",
            num, texto->operacao, texto->valor1, sucesso ? "OK" : "ERRO");
}
