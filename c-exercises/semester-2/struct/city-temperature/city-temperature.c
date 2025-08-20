#include <stdio.h>
#include <string.h>

#define NUM_CIDADES 6
#define NUM_DIAS 7
#define PERIODOS 3

typedef struct {
    char nome[20];
    float temperaturas[NUM_DIAS][PERIODOS];
    char estado[3];
} Cidade;

/* Funções */
void lerTemperaturas(Cidade cidades[]);
float mediaCidade(Cidade cidade);
float mediaDiaEstado(Cidade cidades[], int dia, char estado[]);
float mediaEstado(Cidade cidades[], char estado[]);
int diaMaisQuente(Cidade cidade);
int cidadeMaisQuenteEstado(Cidade cidades[], char estado[]);
void cidadesAcimaMediaEstado(Cidade cidades[], float mediaEstado, char estado[]);
void cidadesExtremosPorDiaEstado(Cidade cidades[], int dia, char estado[]);

int main() {
    Cidade cidades[NUM_CIDADES];
    int i, d;
    float mediaReg, mediaMS, mediaSP;
    int indiceMaisQuenteGeral, indiceMaisQuenteMS, indiceMaisQuenteSP;

    strcpy(cidades[0].nome, "Tres Lagoas"); strcpy(cidades[0].estado, "MS");
    strcpy(cidades[1].nome, "Brasilandia"); strcpy(cidades[1].estado, "MS");
    strcpy(cidades[2].nome, "Selviria"); strcpy(cidades[2].estado, "MS");
    strcpy(cidades[3].nome, "Ilha Solteira"); strcpy(cidades[3].estado, "SP");
    strcpy(cidades[4].nome, "Andradina"); strcpy(cidades[4].estado, "SP");
    strcpy(cidades[5].nome, "Castilho"); strcpy(cidades[5].estado, "SP");

    /* Leitura das temperaturas */
    lerTemperaturas(cidades);

    /* Média por cidade */
    printf("\n--- MEDIA DE TEMPERATURA POR CIDADE ---\n");
    for(i = 0; i < NUM_CIDADES; i++){
        printf("%s (%s): %.2f°C\n", cidades[i].nome, cidades[i].estado, mediaCidade(cidades[i]));
    }

    /* Média diária por estado */
    printf("\n--- MEDIA DE TEMPERATURA POR DIA NO MS ---\n");
    for(d = 0; d < NUM_DIAS; d++){
        printf("Dia %d: %.2f°C\n", d+1, mediaDiaEstado(cidades, d, "MS"));
    }
    printf("\n--- MEDIA DE TEMPERATURA POR DIA NO SP ---\n");
    for(d = 0; d < NUM_DIAS; d++){
        printf("Dia %d: %.2f°C\n", d+1, mediaDiaEstado(cidades, d, "SP"));
    }

    /* Médias semanais por estado e geral */
    mediaMS = mediaEstado(cidades, "MS");
    mediaSP = mediaEstado(cidades, "SP");
    mediaReg = mediaEstado(cidades, "ALL");

    printf("\n--- MEDIA SEMANAL MS: %.2f°C ---\n", mediaMS);
    printf("\n--- MEDIA SEMANAL SP: %.2f°C ---\n", mediaSP);
    printf("\n--- MEDIA SEMANAL REGIONAL: %.2f°C ---\n", mediaReg);

    /* Dia mais quente por cidade */
    printf("\n--- DIA MAIS QUENTE DE CADA CIDADE ---\n");
    for(i = 0; i < NUM_CIDADES; i++){
        printf("%s: Dia %d\n", cidades[i].nome, diaMaisQuente(cidades[i]) + 1);
    }

    /* Cidade mais quente geral e por estado */
    indiceMaisQuenteGeral = cidadeMaisQuenteEstado(cidades, "ALL");
    indiceMaisQuenteMS = cidadeMaisQuenteEstado(cidades, "MS");
    indiceMaisQuenteSP = cidadeMaisQuenteEstado(cidades, "SP");

    printf("\n--- CIDADE MAIS QUENTE GERAL ---\n%s com %.2f°C\n", cidades[indiceMaisQuenteGeral].nome, mediaCidade(cidades[indiceMaisQuenteGeral]));
    printf("\n--- CIDADE MAIS QUENTE MS ---\n%s com %.2f°C\n", cidades[indiceMaisQuenteMS].nome, mediaCidade(cidades[indiceMaisQuenteMS]));
    printf("\n--- CIDADE MAIS QUENTE SP ---\n%s com %.2f°C\n", cidades[indiceMaisQuenteSP].nome, mediaCidade(cidades[indiceMaisQuenteSP]));

    /* Cidades acima da média por estado */
    printf("\n--- CIDADES ACIMA DA MEDIA MS ---\n");
    cidadesAcimaMediaEstado(cidades, mediaMS, "MS");
    printf("\n--- CIDADES ACIMA DA MEDIA SP ---\n");
    cidadesAcimaMediaEstado(cidades, mediaSP, "SP");
    printf("\n--- CIDADES ACIMA DA MEDIA REGIONAL ---\n");
    cidadesAcimaMediaEstado(cidades, mediaReg, "ALL");

    /* Cidades mais quentes e frias por dia por estado */
    for(d = 0; d < NUM_DIAS; d++){
        printf("\n--- DIA %d MS ---\n", d+1);
        cidadesExtremosPorDiaEstado(cidades, d, "MS");
        printf("\n--- DIA %d SP ---\n", d+1);
        cidadesExtremosPorDiaEstado(cidades, d, "SP");
        printf("\n--- DIA %d GERAL ---\n", d+1);
        cidadesExtremosPorDiaEstado(cidades, d, "ALL");
    }

    return 0;
}

/* Declaração das funções */
void lerTemperaturas(Cidade cidades[]) {
    int i, d, p; 
    for(i = 0; i < NUM_CIDADES; i++){
        printf("Digite as temperaturas de %s (%s) - manhã, tarde, noite para cada dia:\n", cidades[i].nome, cidades[i].estado);
        for(d = 0; d < NUM_DIAS; d++){
            printf("Dia %d: ", d+1);
            for(p = 0; p < PERIODOS; p++){
                scanf("%f", &cidades[i].temperaturas[d][p]);
            }
        }
    }
}

float mediaCidade(Cidade cidade) {
    int d, p; 
    float soma = 0;
    for(d = 0; d < NUM_DIAS; d++){
        for(p = 0; p < PERIODOS; p++){
            soma += cidade.temperaturas[d][p];
        }
    }
    return soma / (NUM_DIAS * PERIODOS);
}

/* Média diária por estado */
float mediaDiaEstado(Cidade cidades[], int dia, char estado[]) {
    int i, p; 
    float soma = 0;
    int cont = 0;
    for(i = 0; i < NUM_CIDADES; i++){
        if(strcmp(estado, "ALL") == 0 || strcmp(cidades[i].estado, estado) == 0){
            for(p = 0; p < PERIODOS; p++){
                soma += cidades[i].temperaturas[dia][p];
            }
            cont += PERIODOS;
        }
    }
    return soma / cont;
}

/* Média semanal por estado */
float mediaEstado(Cidade cidades[], char estado[]) {
    int i; 
    float soma = 0;
    int cont = 0;
    for(i = 0; i < NUM_CIDADES; i++){
        if(strcmp(estado, "ALL") == 0 || strcmp(cidades[i].estado, estado) == 0){
            soma += mediaCidade(cidades[i]);
            cont++;
        }
    }
    return soma / cont;
}

/* Dia mais quente por cidade */
int diaMaisQuente(Cidade cidade) {
    int d, p, diaMax = 0;
    float maxTemp = -1000.0, somaDia, mediaDiaTemp;
    for(d = 0; d < NUM_DIAS; d++){
        somaDia = 0;
        for(p = 0; p < PERIODOS; p++){
            somaDia += cidade.temperaturas[d][p];
        }
        mediaDiaTemp = somaDia / PERIODOS;
        if(mediaDiaTemp > maxTemp){
            maxTemp = mediaDiaTemp;
            diaMax = d;
        }
    }
    return diaMax;
}

/* Cidade mais quente por estado ou geral */
int cidadeMaisQuenteEstado(Cidade cidades[], char estado[]) {
    int i;
    int indice = -1;
    float maiorMedia = -1000.0, mediaTemp;
    for(i = 0; i < NUM_CIDADES; i++){
        if(strcmp(estado, "ALL") == 0 || strcmp(cidades[i].estado, estado) == 0){
            mediaTemp = mediaCidade(cidades[i]);
            if(mediaTemp > maiorMedia){
                maiorMedia = mediaTemp;
                indice = i;
            }
        }
    }
    return indice;
}

/* Cidades acima da média por estado ou geral */
void cidadesAcimaMediaEstado(Cidade cidades[], float mediaEstado, char estado[]) {
    int i;
    for(i = 0; i < NUM_CIDADES; i++){
        if((strcmp(estado, "ALL") == 0 || strcmp(cidades[i].estado, estado) == 0) && mediaCidade(cidades[i]) > mediaEstado){
            printf("%s ", cidades[i].nome);
        }
    }
    printf("\n");
}

/* Cidades mais quentes e frias por dia por estado ou geral */
void cidadesExtremosPorDiaEstado(Cidade cidades[], int dia, char estado[]) {
    int i, p;
    float maxTemp = -1000, minTemp = 1000;
    float soma, media;

    /* Encontrar extremos */
    for(i = 0; i < NUM_CIDADES; i++){
        if(strcmp(estado, "ALL") == 0 || strcmp(cidades[i].estado, estado) == 0){
            soma = 0;
            for(p = 0; p < PERIODOS; p++){
                soma += cidades[i].temperaturas[dia][p];
            }
            media = soma / PERIODOS;
            if(media > maxTemp) maxTemp = media;
            if(media < minTemp) minTemp = media;
        }
    }

    /* Imprimir cidades com essas médias */
    printf("Mais quente: ");
    for(i = 0; i < NUM_CIDADES; i++){
        if(strcmp(estado, "ALL") == 0 || strcmp(cidades[i].estado, estado) == 0){
            soma = 0;
            for(p = 0; p < PERIODOS; p++){
                soma += cidades[i].temperaturas[dia][p];
            }
            media = soma / PERIODOS;
            if(media == maxTemp) printf("%s ", cidades[i].nome);
        }
    }

    printf("\nMais fria: ");
    for(i = 0; i < NUM_CIDADES; i++){
        if(strcmp(estado, "ALL") == 0 || strcmp(cidades[i].estado, estado) == 0){
            soma = 0;
            for(p = 0; p < PERIODOS; p++){
                soma += cidades[i].temperaturas[dia][p];
            }
            media = soma / PERIODOS;
            if(media == minTemp) printf("%s ", cidades[i].nome);
        }
    }
    printf("\n");
}