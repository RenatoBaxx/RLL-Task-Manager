#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void dashboard(int userID) {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de tasks.\n");
        return;
    }

    char buffer[200];
    int taskUserID, taskID;
    char taskNome[50], taskDataEntrega[15], taskResumo[100];
    int taskFound = 0; 
    printf("--------- Minhas Tasks ---------\n");

    while (fgets(buffer, 200, file)) {
        sscanf(buffer, "TaskID: %d, UserID: %d, Nome: %[^,], Data: %[^,], Resumo: %[^\n]", &taskID, &taskUserID, taskNome, taskDataEntrega, taskResumo);

        if (taskUserID == userID) {
            taskFound = 1;  
            printf("Task ID: %d\n", taskID);
            printf("Nome: %s\n", taskNome);
            printf("Data de Entrega: %s\n", taskDataEntrega);
            printf("Resumo: %s\n", taskResumo);
            printf("----------------------------------\n");
        }
    }

    if (!taskFound) {
        printf("Nenhuma task associada a esse usuário.\n");
    }

    fclose(file);
}
