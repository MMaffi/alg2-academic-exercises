#include <stdio.h>

/* Protótipo da função */
int maior_valor(int vet[], int n);

int main(void) {

    int vetor[100];
    int n, i;
    int maior;

    printf("Informe a quantidade de elementos do vetor: ");
    scanf("%d", &n);

    printf("Informe os valores do vetor: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    maior = maior_valor(vetor, n);

    printf("O maior valor do vetor é: %d\n", maior);

    return 0;
}

/* Declaração da função recursiva */
int maior_valor(int vet[], int n) {

    int maior;

    if ( n == 1 ) {
        return vet[0];
    } else {
        maior = maior_valor(vet, n-1);
        if (vet[n-1] > maior) {
            return vet[n-1];
        } else {
            return maior;
        }
    }

}