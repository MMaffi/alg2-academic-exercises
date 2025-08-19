#include <stdio.h>

/* Protótipo da função interativa */
int pot(int x, int n);

int main(void) {

    int x, n, calculo;

    printf("Informe o valor da potencia: ");
    scanf("%d", &x);

    printf("Informe a potência: ");
    scanf("%d", &n);

    calculo = pot(x, n);

    printf("O valor de %d elevado a %d é: %d\n", x, n, calculo);

    return 0;
}

/* Função interativa */
int pot(int x, int n) {

    int calc, i;

    calc = 1;

    for ( i = 0; i < n; i++ ) {
        calc = calc * x;
    }

    return calc;

}