#include <stdio.h>

/* Protótipo da função */
int soma(int n);

int main(void) {

    int n, sum;

    printf("Informe a quantidade de elementos da soma: ");
    scanf("%d", &n);

    sum = soma( n );

    printf("A soma de Gauss com %d elementos é: %d\n", n, sum);

    return 0;
}

/* Declaração da função recursiva */
int soma(int n) {

    if (n == 0) {
        return 0;
    } else {
        return n + soma( n-1 );
    }

}