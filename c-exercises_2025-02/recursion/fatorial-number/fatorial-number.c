#include <stdio.h>

/* Protótipo da função */
int fatorial(int n);

int main(void) {

    int n, fat;

    printf("Informe um número: ");
    scanf("%d", &n);

    fat = fatorial( n );

    printf("O fatorial de %d é: %d\n", n, fat);

    return 0;
}

/* Declaração da função recursiva */
int fatorial(int n) {

    if (n == 0) {
        return 1;
    } else {
        return n * fatorial( n-1 );
    }

}