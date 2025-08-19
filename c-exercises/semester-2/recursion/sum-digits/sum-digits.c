#include <stdio.h>

int soma_digitos(int n);

int main(void) {

    int numero, res;

    printf("Informe um número positivo: ");
    scanf("%d", &numero);

    res = soma_digitos(numero);

    printf("A soma dos dígitos de %d é: %d\n", numero, res);

    return 0;
}

int soma_digitos(int n) {
    if (n == 0) {
        return 0;
    } else {
        return (n % 10) + soma_digitos(n / 10);
    }
}