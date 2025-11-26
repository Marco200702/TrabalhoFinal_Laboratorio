#ifndef LIBESTRUTURAS_H
#define LIBESTRUTURAS_H

typedef struct NodeP {
    int valor;
    struct NodeP* prox;
} NodeP;

typedef struct {
    NodeP* topo;
} Pilha;

void inicializaPilha(Pilha* p);
void liberaPilha(Pilha* p);
void push(Pilha* p, int v);
int pop(Pilha* p);
int topPilha(Pilha* p);
char* snapshotPilha(Pilha* p);

typedef struct NodeF {
    int valor;
    struct NodeF* prox;
} NodeF;

typedef struct {
    NodeF* frente;
    NodeF* tras;
} Fila;

void inicializaFila(Fila* f);
void liberaFila(Fila* f);
void enqueue(Fila* f, int v);
int dequeue(Fila* f);
char* snapshotFila(Fila* f);

#endif
