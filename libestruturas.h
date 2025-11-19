#ifndef TRABALHOLIB_H
#define TRABALHOLIB_H


// ESTRUTURAS DA FILA
typedef struct NoFila{
    int valor;
    struct NoFila *proximo;
}NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
}Fila;

// FUNÇÕES DA FILA
void inicializarFila(Fila *fila);
void enqueue(Fila *fila, int valor);
int dequeue(Fila *fila);
int filaVazia(Fila *fila);
void liberarFila(Fila *fila);


// ###########################################


// ESTRUTURAS DA PILHA
typedef struct NoPilha {
    int valor;
    struct NoPilha *proximo;
} NoPilha;

typedef struct{
    NoPilha *topoPilha;
} Pilha;

// FUNÇÕES DA PILHA
void iniciarPilha(Pilha *pilha);
void push(Pilha *pilha, int valor);
int pop(Pilha *pilha);
int top(Pilha *pilha);
int pilhaVazia (Pilha *pilha);
void liberarPilha (Pilha *pilha);

#endif