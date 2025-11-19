#ifndef TRABALHOLIB_H
#define TRABALHOLIB_H


// ESTRUTURAS DA PILHA
typedef struct NoPilha {
    int valor;
    struct NoPilha *prox;
    
} NoPilha;

typedef struct{
    NoPilha *topoPilha;
} Pilha;

// FUNÇÕES DA PILHA
void iniciarPilha(Pilha *p);
void push(Pilha *p, int v);
int pop(Pilha *p);
int top(Pilha *p);
int pilhaVazia (Pilha *p);
void liberarPilha (Pilha *p);



// ESTRUTURAS DA FILA

typedef