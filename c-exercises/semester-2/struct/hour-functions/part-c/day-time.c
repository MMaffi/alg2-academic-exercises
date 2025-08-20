#include <stdio.h>

/* Declaraçuão de estrutras */
typedef struct reg_horario {
    int hora;
    int minuto;
    int segundo;
} reg_horario;

/* Protótipos de funções */
reg_horario le_hora();

void escreve_hora(reg_horario hora);

int verifica_hora(reg_horario hora1, reg_horario hora2);

int main(void) {

    reg_horario hora1, hora2;
    int primeiro;

    printf("Escreva o primeiro horário! \n");
    hora1 = le_hora();

    printf("Escreva o segundo horário! \n");
    hora2 = le_hora();

    primeiro = verifica_hora(hora1, hora2);

    if (primeiro == 1) {
        printf("O horário ");
        escreve_hora(hora1);
        printf(" vem primeiro no dia!\n");
    } else {
        printf("O horário ");
        escreve_hora(hora2);
        printf(" vem primeiro no dia!\n");
    }

    return 0;
}

/* Declaração de variáveis */
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

    printf("%02d:%02d:%02d", hora.hora, hora.minuto, hora.segundo);

}

int verifica_hora(reg_horario hora1, reg_horario hora2) {

    int segundos1, segundos2, primeiro;

    segundos1 = (hora1.hora * 3600) + (hora1.minuto * 60) + hora1.segundo;
    segundos2 = (hora2.hora * 3600) + (hora2.minuto * 60) + hora2.segundo;

    if (segundos1 < segundos2) {
        primeiro = 1;
    } else {
        primeiro = 2;
    }

    return primeiro;

}