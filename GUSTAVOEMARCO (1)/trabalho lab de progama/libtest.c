#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libtest.h"

static void trim(char* s) {
    char* p = s;
    while (*p==' '||*p=='\n'||*p=='\t'||*p=='\r') p++;
    if (p!=s) memmove(s,p,strlen(p)+1);
    int L=strlen(s);
    while(L>0 && (s[L-1]==' '||s[L-1]=='\n'||s[L-1]=='\t'||s[L-1]=='\r')) s[--L]='\0';
}

int executarTeste(Teste* t, Pilha* p, Fila* f, char* actual, size_t size) {
    actual[0]='\0';

    if (strcmp(t->operacao,"PUSH")==0) {
        push(p,t->valor);
        if (t->esperado[0]=='[') {
            char* s = snapshotPilha(p);
            strncpy(actual,s,size-1); actual[size-1]='\0'; free(s);
        } else sprintf(actual,"%d", topPilha(p));
    }
    else if (strcmp(t->operacao,"POP")==0) {
        int v=pop(p);
        if(v==0) strcpy(actual,"0/NULL");
        else sprintf(actual,"%d",v);
    }
    else if (strcmp(t->operacao,"TOP")==0) {
        int v=topPilha(p);
        if(v==0) strcpy(actual,"0/NULL");
        else sprintf(actual,"%d",v);
    }
    else if (strcmp(t->operacao,"ENQUEUE")==0) {
        enqueue(f,t->valor);
        if(t->esperado[0]=='[') {
            char* s=snapshotFila(f);
            strncpy(actual,s,size-1); actual[size-1]='\0'; free(s);
        } else sprintf(actual,"%d", t->valor);
    }
    else if (strcmp(t->operacao,"DEQUEUE")==0) {
        int v=dequeue(f);
        if(v==0) strcpy(actual,"0/NULL");
        else sprintf(actual,"%d",v);
    }
    else if (strcmp(t->operacao,"VISUALIZAR")==0) {
        char* s = snapshotFila(f);
        strncpy(actual,s,size-1); actual[size-1]='\0'; free(s);
    }

    trim(actual);
    char exp[256]; strncpy(exp,t->esperado,255); exp[255]='\0'; trim(exp);

    return strcmp(actual,exp)==0;
}

void registrarResultado(FILE* out, int numero, Teste* t, const char* actual, int sucesso) {
    char op[128];
    if (strcmp(t->operacao,"PUSH")==0)
        sprintf(op,"PUSH(%d)", t->valor);
    else if (strcmp(t->operacao,"ENQUEUE")==0)
        sprintf(op,"ENQUEUE(%d)", t->valor);
    else
        sprintf(op,"%s()", t->operacao);

    fprintf(out,"Teste %d: %s = %s -> %s\n",
            numero, op, t->esperado, sucesso ? "OK" : "ERROR");
}
