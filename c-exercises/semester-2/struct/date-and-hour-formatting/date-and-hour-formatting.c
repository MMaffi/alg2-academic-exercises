#include <stdio.h>

/* Declaração de estruturas */
typedef struct reg_data {
    int dia;
    int mes;
    int ano;
} reg_data;

typedef struct reg_horario {
    int hora;
    int minuto;
    int segundo;
} reg_horario;

/* Protótipo de funções */
reg_data le_data();
void escreve_data( reg_data data );

reg_horario le_hora();
void escreve_hora( reg_horario hora );

/* Função MAIN */
int main(void) {

    reg_data data;
    reg_horario hora;

    data = le_data();

    escreve_data( data );

    printf("\n-------------------------------------------------------\n\n");

    hora = le_hora();

    escreve_hora( hora );

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

void escreve_data( reg_data data ) {

    printf("A data digitada formatada é: ");
    printf("%02d/%02d/%02d\n", data.dia, data.mes, data.ano);

}

reg_horario le_hora() {

    reg_horario hora;

    printf("Informe a hora: ");
    scanf("%d", &hora.hora);

    printf("Informe o minuto: ");
    scanf("%d", &hora.minuto);

    printf("Informe o segundo: ");
    scanf("%d", &hora.segundo);

    return hora;

}

void escreve_hora( reg_horario hora ) {

    printf("A data digitada formatada é: ");
    printf("%02d:%02d:%02d\n", hora.hora, hora.minuto, hora.segundo);

}
