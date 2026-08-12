#include <stdio.h>
#include <string.h>

typedef struct reg_data {
    int dia;
    int mes;
    int ano;
} reg_data;

reg_data le_data();

int dia_semana(reg_data data);
void escreve_data( reg_data data);

int main(void) {

    reg_data data;
    int h;
    char texto_dia[50];

    data = le_data();

    h = dia_semana( data );

    switch (h) {
        case 0:
            strcpy(texto_dia, "Sábado");
            break;
        case 1:
            strcpy(texto_dia, "Domingo");
            break;
        case 2:
            strcpy(texto_dia, "Segunda-Feira");
            break;
        case 3:
            strcpy(texto_dia, "Terça-Feira");
            break;
        case 4:
            strcpy(texto_dia, "Quarta-Feira");
            break;
        case 5:
            strcpy(texto_dia, "Quinta-Feira");
            break;
        case 6:
            strcpy(texto_dia, "Sexta-Feira");
            break;
        default:
            printf("Dia Inválido");
            break;
    }

    printf("Segundo a data informada\n");
    escreve_data( data );
    printf("É uma: %s\n", texto_dia);
    return 0;
}

/* Declaração de funções */
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

int dia_semana(reg_data data) {
    int q = data.dia;
    int m = data.mes;
    int K, J, h;

    /* Ajuste para janeiro e fevereiro */
    if (m == 1) {
        m = 13;
        data.ano -= 1;
    } else if (m == 2) {
        m = 14;
        data.ano -= 1;
    }

    K = data.ano % 100;
    J = data.ano / 100;

    h = (q + (13*(m + 1))/5 + K + (K/4) + (J/4) + 5*J) % 7;

    return h; /* 0 = sábado, 1 = domingo, ..., 6 = sexta */
}

void escreve_data( reg_data data) {

    printf("O dia: ");
    printf("%02d/%02d/%02d\n", data.dia, data.mes, data.ano);

}
