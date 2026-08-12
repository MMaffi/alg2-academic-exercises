#include <stdio.h>

/* Protótipo da função */
int potR(int x, int n);

int main(void) {

    int x, n, calculo;

    printf("Informe o valor da potencia: ");
    scanf("%d", &x);

    printf("Informe a potência: ");
    scanf("%d", &n);

    calculo = potR(x, n);

    printf("O valor de %d elevado a %d é: %d\n", x, n, calculo);

    return 0;
}

/* Declaração da função */
int potR(int x, int n) {

    if ( n == 0 ) {
        return 1;
    } else {
        return x * potR( x, n-1 );
    }

}