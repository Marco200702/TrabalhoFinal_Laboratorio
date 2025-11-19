#include <stdio.h>
#include <string.h>

//LISTA 2 - ETAPA 1 - EXERCÍCIO 1:
//Implemente uma função que receba um vetor de inteiros e seu tamanho e retorne a soma de todos os elementos.
//No main, peça para o usuário digitar os elementos do vetor e exiba o resultado.


int soma_de_vetor(int vetor[], int tamanho){
    int soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma += vetor[i];
    }
    return soma;
}

int main() {
    int tamanho;
    printf("\nInsira quantos valores os vetor deve ter: ");
    scanf("%i", &tamanho);

    if (tamanho <= 0){
        printf("Tamanho invalido");
        return 1;
    }

    int vetor[tamanho];

    printf("Digite os %d valores do vetor: \n", tamanho);
    for(int i = 0; i < tamanho; i++){
        printf("Elemento %d: ", i + 1);
        scanf("%i", &vetor[i]);
    }

    int resultado = soma_de_vetor(vetor, tamanho);
    printf("A soma do vetor eh: %i\n\n", resultado);

    return 0;
}
