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

reg_horario calc_tempo(reg_horario hora1, reg_horario hora2);

int main(void) {

    reg_horario hora1, hora2, tempo;

    printf("Escreva o primeiro horário! \n");
    hora1 = le_hora();

    printf("Escreva o segundo horário! \n");
    hora2 = le_hora();

    tempo = calc_tempo(hora1, hora2);

    escreve_hora(tempo);

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

    printf("O tempo decorrido entre os dois horários é: ");
    printf("%02d:%02d:%02d\n", hora.hora, hora.minuto, hora.segundo);

}

reg_horario calc_tempo(reg_horario hora1, reg_horario hora2) {

    reg_horario temp;
    int segundos1, segundos2, tempsec, resto;

    segundos1 = (hora1.hora * 3600) + (hora1.minuto * 60) + hora1.segundo;
    segundos2 = (hora2.hora * 3600) + (hora2.minuto * 60) + hora2.segundo;

    tempsec = segundos1 - segundos2;
    if (tempsec < 0) {
        tempsec = tempsec * -1;
    }

    temp.hora = tempsec / 3600;
    resto = tempsec % 3600;

    temp.minuto = resto / 60;
    temp.segundo = resto % 60;

    return temp;

}