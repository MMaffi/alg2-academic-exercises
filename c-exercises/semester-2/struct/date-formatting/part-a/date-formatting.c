#include <stdio.h>
#include <string.h>

typedef struct reg_data {
    int dia;
    int mes;
    int ano;
} reg_data;

reg_data le_data();

void escreve_data( reg_data data, char mes[] );

int main (void) {

    reg_data data;
    char mes[15];

    data = le_data();

    switch (data.mes)
    {
    case 1:
        strcpy(mes, "janeiro");
        break;
    case 2:
        strcpy(mes, "fevereiro");
        break;
    case 3:
        strcpy(mes, "março");
        break;
    case 4:
        strcpy(mes, "abril");
        break;
    case 5:
        strcpy(mes, "maio");
        break;
    case 6:
        strcpy(mes, "junho");
        break;
    case 7:
        strcpy(mes, "julho");
        break;
    case 8:
        strcpy(mes, "agosto");
        break;
    case 9:
        strcpy(mes, "setembro");
        break;
    case 10:
        strcpy(mes, "outubro");
        break;
    case 11:
        strcpy(mes, "novembro");
        break;
    case 12:
        strcpy(mes, "dezembro");
        break;
    default:
        printf("Mês inválido");
    }

    escreve_data( data, mes );

    return 0;
}

/* Declarações de função */
reg_data le_data() {

    reg_data data;

    printf("Informe o dia: ");
    scanf("%d", &data.dia);

    printf("Informe o mês: ");
    scanf("%d", &data.mes);

    printf("Informe o ano: ");
    scanf("%d", &data.ano);

    return data;

}

void escreve_data( reg_data data, char mes[]) {

    printf("A data digitada é: ");
    printf("%02d de %s de %02d\n", data.dia, mes, data.ano);

}
