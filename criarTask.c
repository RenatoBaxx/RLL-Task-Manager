#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

// Função para gerar um novo ID de task
int gerarTaskID() {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        return 1;  // Se o arquivo não existe ou está vazio, o ID será 1
    }

    char buffer[200];
    int ultimoID = 0;
    while (fgets(buffer, 200, file)) {
        int taskID;
        sscanf(buffer, "TaskID: %d,", &taskID);
        if (taskID > ultimoID) {
            ultimoID = taskID; 
        }
    }

    fclose(file);
    return ultimoID + 1; 
}

int validarData(int dia, int mes, int ano) {
    if (ano < 2024) return 0;
    if (mes < 1 || mes > 12) return 0;
    if (dia < 1 || dia > 31) return 0;
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) return 0;
    if (mes == 2) {
        int anoBissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
        if (anoBissexto && dia > 29) return 0;
        if (!anoBissexto && dia > 28) return 0;
    }
    return 1;
}

void criarTask(int userID) {
    char nome[50], resumo[100];
    int dia, mes, ano;

    printf("Digite o nome da task: ");
    scanf(" %[^\n]", nome);

    do {
        printf("Digite o dia de entrega (1-31): ");
        scanf("%d", &dia);
        printf("Digite o mês de entrega (1-12): ");
        scanf("%d", &mes);
        printf("Digite o ano de entrega (>=2024): ");
        scanf("%d", &ano);

        if (!validarData(dia, mes, ano)) {
            printf("Data inválida. Tente novamente.\n");
        }
    } while (!validarData(dia, mes, ano));

    printf("Digite um resumo da task: ");
    scanf(" %[^\n]", resumo);

    // Gera um novo ID de task
    int taskID = gerarTaskID();

    FILE *file = fopen("tasks.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de tasks.\n");
        return;
    }

    fprintf(file, "TaskID: %d, UserID: %d, Nome: %s, Data: %02d/%02d/%d, Resumo: %s\n", taskID, userID, nome, dia, mes, ano, resumo);
    printf("Task criada com sucesso!\n");

    fclose(file);
}
