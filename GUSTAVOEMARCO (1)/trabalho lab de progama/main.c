#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "libestruturas.h"
#include "libtest.h"

static int parseLinha(const char* linha, Teste* t) {
    char buf[512]; strncpy(buf, linha, sizeof(buf)-1); buf[sizeof(buf)-1]='\0';
    size_t L = strlen(buf); while (L>0 && (buf[L-1]=='\n' || buf[L-1]=='\r')) buf[--L]='\0';
    char* pipe = strchr(buf, '|');
    if (pipe) {
        *pipe = '\0';
        char* left = buf; char* right = pipe+1;
        while (*left && isspace((unsigned char)*left)) left++;
        char* end = left + strlen(left) - 1; while (end>left && isspace((unsigned char)*end)) *end--='\0';
        while (*right && isspace((unsigned char)*right)) right++;
        end = right + strlen(right) - 1; while (end>right && isspace((unsigned char)*end)) *end--='\0';
        char op[64]; int val = 0;
        if (sscanf(left, "%s %d", op, &val) >= 1) {
            strncpy(t->operacao, op, 31); t->operacao[31]='\0';
            t->valor = val;
            strncpy(t->esperado, right, 255); t->esperado[255]='\0';
            return 1;
        }
    } else {
        char op[64];
        char *rest;
        if (sscanf(buf, "%s", op) != 1) return 0;
        rest = strchr(buf, ' ');
        if (!rest) {
            strncpy(t->operacao, op, 31); t->valor = 0; t->esperado[0]='\0'; return 1;
        }
        rest++; while (*rest && isspace((unsigned char)*rest)) rest++;
        int val, n;
        if (sscanf(rest, "%d%n", &val, &n) == 1) {
            t->valor = val;
            char* exp = rest + n; while (*exp && isspace((unsigned char)*exp)) exp++;
            strncpy(t->esperado, exp, 255); t->esperado[255]='\0';
        } else {
            t->valor = 0;
            strncpy(t->esperado, rest, 255); t->esperado[255]='\0';
        }
        strncpy(t->operacao, op, 31);
        return 1;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s arquivo_testes.txt [arquivo_resultados.txt]\n", argv[0]);
        return 1;
    }

    const char* arquivoEntrada = argv[1];
    const char* arquivoSaida = (argc >= 3) ? argv[2] : "result.txt";

    FILE* fin = fopen(arquivoEntrada, "r");
    if (!fin) { perror("Erro ao abrir arquivo de entrada"); return 1; }
    FILE* fout = fopen(arquivoSaida, "w");
    if (!fout) { perror("Erro ao abrir arquivo de saída"); fclose(fin); return 1; }

    Pilha p; Fila f;
    inicializaPilha(&p); inicializaFila(&f);

    char linha[512]; int numero = 0;
    while (fgets(linha, sizeof(linha), fin)) {
        int onlyws = 1; for (char* q = linha; *q; ++q) if (!isspace((unsigned char)*q)) { onlyws = 0; break; }
        if (onlyws) continue;
        Teste t; memset(&t, 0, sizeof(t));
        if (!parseLinha(linha, &t)) {
            numero++; fprintf(fout, "Teste %d: LINHA_INVALIDA = - -> ERROR\n", numero);
            continue;
        }
        char actual[256]; int sucesso = executarTeste(&t, &p, &f, actual, sizeof(actual));
        numero++; registrarResultado(fout, numero, &t, actual, sucesso);
    }

    liberaPilha(&p); liberaFila(&f);
    fclose(fin); fclose(fout);

    printf("Execução concluída. Resultados em: %s\n", arquivoSaida);
    return 0;
}
