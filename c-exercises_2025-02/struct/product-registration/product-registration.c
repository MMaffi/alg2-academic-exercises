#include <stdio.h>

typedef struct {

    int codigo;
    char descricao[100];
    int min_estoque;
    int atual_estoque;
    float preco;

} regprod;

void verificaestoque(regprod products[], int n) {
    int i;

    for (i = 0; i < n; i++) {

        if (products[i].min_estoque > products[i].atual_estoque) {
            printf("\nCódigo: %d\n", products[i].codigo);
            printf("Descrição: %s\n", products[i].descricao);
            printf("Estoque mínimo: %d\n", products[i].min_estoque);
            printf("Estoque Atual: %d\n", products[i].atual_estoque);
            printf("Preço: R$%.2f\n", products[i].preco);

            printf("\n-------------------\n");
        }

    }
}

int main(void) {

    int n, i;
    regprod produtos[50];

    printf("Informe a quantidade de produtos: ");
    scanf("%d", &n);

    printf("Informe os produtos: \n");
    for (i = 0; i < n; i++) {
        printf("Produto %d\n", i + 1);
        printf("Código: ");
        scanf("%d", &produtos[i].codigo);
        printf("Desrição: ");
        scanf(" %[^\n]", produtos[i].descricao);
        printf("Estoque Mínimo: ");
        scanf("%d", &produtos[i].min_estoque);
        printf("Estoque Atual: ");
        scanf("%d", &produtos[i].atual_estoque);
        printf("Preço: ");
        scanf("%f", &produtos[i].preco);
    }

    printf("\nLista de produtos com esoque atual menor que estoque mínimo:\n");
    verificaestoque(produtos, n);

    return 0;
}