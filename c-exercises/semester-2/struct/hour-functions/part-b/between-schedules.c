#include <stdio.h>

/* Declaraçuão de estrutras */
typedef struct reg_horario {
    int hora;
    int minuto;
    int segundo;
} reg_horario;

/* Protótipos de funções */
reg_horario le_hora();

void escreve_hora( reg_horario hora );

int verifica_hora(reg_horario hora1, reg_horario hora2, reg_horario hora3);

int main(void) {

    reg_horario hora1, hora2, hora3;
    int verifica;

    printf("Escreva o primeiro horário! \n");
    hora1 = le_hora();

    printf("Escreva o segundo horário! \n");
    hora2 = le_hora();

    printf("Escreva o terceiro horário! \n");
    hora3 = le_hora();

    verifica = verifica_hora(hora1, hora2, hora3);

    if (verifica == 1) {

        printf("A hora ");
        escreve_hora(hora3);
        printf("ESTÁ entre as outras horas digitadas!\n");

    } else {

        printf("A hora ");
        escreve_hora(hora3);
        printf("NÃO ESTÁ entre as outras horas digitadas!\n");

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

    printf("%02d:%02d:%02d ", hora.hora, hora.minuto, hora.segundo);

}

int verifica_hora(reg_horario hora1, reg_horario hora2, reg_horario hora3) {

    int seg1, seg2, seg3;
    int eh_entre;

    seg1 = (hora1.hora * 3600) + (hora1.minuto * 60) + hora1.segundo;
    seg2 = (hora2.hora * 3600) + (hora2.minuto * 60) + hora2.segundo;
    seg3 = (hora3.hora * 3600) + (hora3.minuto * 60) + hora3.segundo;

    if ((seg3 > seg1 && seg3 < seg2) || (seg3 < seg1 && seg3 > seg2)) {
        eh_entre = 1;
    } else {
        eh_entre = 0;
    }

    return eh_entre;

}