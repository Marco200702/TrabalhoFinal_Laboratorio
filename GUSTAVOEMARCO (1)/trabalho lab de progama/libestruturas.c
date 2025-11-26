#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libestruturas.h"

void inicializaPilha(Pilha* p) { p->topo = NULL; }

void liberaPilha(Pilha* p) {
    NodeP* cur = p->topo;
    while (cur) {
        NodeP* tmp = cur->prox;
        free(cur);
        cur = tmp;
    }
    p->topo = NULL;
}

void push(Pilha* p, int v) {
    NodeP* n = malloc(sizeof(NodeP));
    n->valor = v;
    n->prox = p->topo;
    p->topo = n;
}

int pop(Pilha* p) {
    if (!p->topo) return 0;
    NodeP* t = p->topo;
    int v = t->valor;
    p->topo = t->prox;
    free(t);
    return v;
}

int topPilha(Pilha* p) {
    if (!p->topo) return 0;
    return p->topo->valor;
}

char* snapshotPilha(Pilha* p) {
    char* buf = malloc(256);
    strcpy(buf, "[");
    NodeP* cur = p->topo;
    while (cur) {
        char temp[32];
        sprintf(temp, "%d", cur->valor);
        strcat(buf, temp);
        if (cur->prox) strcat(buf, ", ");
        cur = cur->prox;
    }
    strcat(buf, "]");
    return buf;
}

void inicializaFila(Fila* f) { f->frente = f->tras = NULL; }

void liberaFila(Fila* f) {
    NodeF* cur = f->frente;
    while (cur) {
        NodeF* tmp = cur->prox;
        free(cur);
        cur = tmp;
    }
    f->frente = f->tras = NULL;
}

void enqueue(Fila* f, int v) {
    NodeF* n = malloc(sizeof(NodeF));
    n->valor = v;
    n->prox = NULL;
    if (!f->tras) { f->frente = f->tras = n; }
    else { f->tras->prox = n; f->tras = n; }
}

int dequeue(Fila* f) {
    if (!f->frente) return 0;
    NodeF* t = f->frente;
    int v = t->valor;
    f->frente = t->prox;
    if (!f->frente) f->tras = NULL;
    free(t);
    return v;
}

char* snapshotFila(Fila* f) {
    char* buf = malloc(256);
    strcpy(buf, "[");
    NodeF* cur = f->frente;
    while (cur) {
        char temp[32];
        sprintf(temp, "%d", cur->valor);
        strcat(buf, temp);
        if (cur->prox) strcat(buf, ", ");
        cur = cur->prox;
    }
    strcat(buf, "]");
    return buf;
}
