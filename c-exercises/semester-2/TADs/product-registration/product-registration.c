#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 31

typedef struct {
    int codigo;
    char nome[MAX_STR];
    char categoria[MAX_STR];
    int quantidade;
    float preco;
} Produto;

typedef struct Node {
    Produto produto;
    struct Node *next;
} Node;

int main() {
    char nomeArquivo[100], nomeSaida[100];
    FILE *fp, *fpOut;
    Node *head = NULL, *tail = NULL, *novo;
	Node *atual;
    
    printf("Informe o nome do arquivo de produtos (entrada): ");
    scanf("%s", nomeArquivo);

    fp = fopen(nomeArquivo, "r");
    if (fp == NULL) {
        printf("\nErro ao abrir o arquivo %s\n", nomeArquivo);
        return 1;
    }

    while (!feof(fp)) {
        Produto p;
        if (fscanf(fp, "%d;%30[^;];%30[^;];%d;%f\n",
                   &p.codigo,
                   p.nome,
                   p.categoria,
                   &p.quantidade,
                   &p.preco) == 5) {

            novo = (Node *) malloc(sizeof(Node));
            if (!novo) {
                printf("Erro de memória\n");
                fclose(fp);
                return 1;
            }
            novo->produto = p;
            novo->next = NULL;

            if (head == NULL) {
                head = tail = novo;
            } else {
                tail->next = novo;
                tail = novo;
            }
        }
    }

    fclose(fp);

    atual = head;
    while (atual != NULL) {
        Produto p = atual->produto;
        printf("Código: %d | Nome: %s | Categoria: %s | Quantidade: %d | Preço: %.2f\n",
               p.codigo, p.nome, p.categoria, p.quantidade, p.preco);
        atual = atual->next;
    }

    printf("\nInforme o nome do arquivo de saída: ");
    scanf("%s", nomeSaida);

    fpOut = fopen(nomeSaida, "w");
    if (fpOut == NULL) {
        printf("\nErro ao criar o arquivo %s\n", nomeSaida);
        return 1;
    }

    atual = head;
    while (atual != NULL) {
        Produto p = atual->produto;
        fprintf(fpOut, "Código: %d | Nome: %s | Categoria: %s | Quantidade: %d | Preço: %.2f\n",
               p.codigo, p.nome, p.categoria, p.quantidade, p.preco);
        atual = atual->next;
    }

    fclose(fpOut);

    while (head != NULL) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }

    printf("\nProdutos salvos com sucesso em %s\n", nomeSaida);
    return 0;
}