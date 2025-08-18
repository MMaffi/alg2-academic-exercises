#include <stdio.h>
#include <string.h>

/* Declaração do registro */
typedef struct {
    char nome[50];
    char estado[50];
    int populacao;
} regcity;

/* Função para listar cidades MS */
void listacidadesMS( regcity cidades[], int qtdcity ) {

    int i;

    for (i = 0; i < qtdcity; i++) {
        if (strcmp(cidades[i].estado, "Mato Grosso do Sul") == 0 ||
            strcmp(cidades[i].estado, "MATO GROSSO DO SUL") == 0 ||
            strcmp(cidades[i].estado, "mato grosso do sul") == 0) {

            printf("%s - população: %d\n", cidades[i].nome, cidades[i].populacao);

        }
    }

}

/* Função para listar cidade de maior população */
void maiorpopcity(regcity cidades[], int qtdcity) {

    int i = 0;
    regcity maior;

    maior = cidades[i];

    for (i = 1; i < qtdcity; i++) {

        if (cidades[i].populacao > maior.populacao) {
            maior = cidades[i];
        }

    }

    printf("%s - %s - População: %d\n", maior.nome, maior.estado, maior.populacao);

}

/* Função MAIN */
int main(void) {

    int n, i;
    regcity cities[1000];

    printf("Informe a quantidade de cidades: ");
    scanf("%d", &n);

    printf("Informe as informações das cidades (Nome Estado População)\n");
    for (i = 0; i < n; i++) {
        printf("Nome: ");
        scanf(" %[^\n]", cities[i].nome);
        printf("Estado: ");
        scanf(" %[^\n]", cities[i].estado);
        printf("População: ");
        scanf("%d", &cities[i].populacao);
    }

    printf("\nCidades do Mato Grosso do Sul:\n");
    listacidadesMS(cities, n);

    printf("\nA cidade de maior população é:\n");
    maiorpopcity(cities, n);

    return 0;
}