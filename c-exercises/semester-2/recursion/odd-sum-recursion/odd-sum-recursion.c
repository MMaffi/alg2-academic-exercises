#include <stdio.h>

/* Função Recursiva */
int somaI(int vet[], int n) {

    int x;

    if(n == 0) {
        return 0;
    } else {
        x = somaI(vet, n-1);
        if (vet[n-1] % 2 != 0) {
            return x + vet[n-1];
        }
        return x;
    }

}

int main(void) {

    int vetor[100];
    int soma;
    int n, i;

    printf("Informe a quantidade de elementos do vetor: ");
    scanf("%d", &n);

    printf("Agora informe os valores do vetor: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    soma = somaI(vetor, n);
    
    printf("A soma é: %d\n", soma);

    return 0;
}