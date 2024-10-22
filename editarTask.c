#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void editarTask(int userID) {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de tasks.\n");
        return;
    }

    FILE *tempFile = fopen("tasks_temp.txt", "w");
    if (tempFile == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(file);
        return;
    }

    char buffer[200];
    int taskUserID, taskID, taskFound = 0;
    char taskNome[50], taskDataEntrega[15], taskResumo[100];

    printf("--------- Minhas Tasks ---------\n");
    while (fgets(buffer, 200, file)) {
        sscanf(buffer, "TaskID: %d, UserID: %d, Nome: %[^,], Data: %[^,], Resumo: %[^\n]", &taskID, &taskUserID, taskNome, taskDataEntrega, taskResumo);
        if (taskUserID == userID) {
            taskFound = 1;
            printf("ID: %d | Nome: %s | Data: %s\n", taskID, taskNome, taskDataEntrega);
        }
    }

    if (!taskFound) {
        printf("Nenhuma task associada a esse usuário.\n");
        fclose(file);
        fclose(tempFile);
        remove("tasks_temp.txt"); 
        return;
    }

   
    printf("Digite o ID da task que deseja editar: ");
    int taskToEdit;
    scanf("%d", &taskToEdit);

    rewind(file);  
    taskFound = 0;

    while (fgets(buffer, 200, file)) {
        sscanf(buffer, "TaskID: %d, UserID: %d, Nome: %[^,], Data: %[^,], Resumo: %[^\n]", &taskID, &taskUserID, taskNome, taskDataEntrega, taskResumo);

        if (taskUserID == userID && taskID == taskToEdit) {
            taskFound = 1;

            int opcao;
            printf("Task encontrada: %s\n", taskNome);
            printf("O que deseja editar?\n");
            printf("1. Nome\n");
            printf("2. Data de Entrega\n");
            printf("3. Resumo\n");
            printf("4. Excluir Task\n");
            printf("Digite a opção: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    printf("Digite o novo nome da task: ");
                    scanf(" %[^\n]", taskNome);
                    break;

                case 2: {
                    int dia, mes, ano;
                    do {
                        printf("Digite o novo dia de entrega (1-31): ");
                        scanf("%d", &dia);
                        printf("Digite o novo mês de entrega (1-12): ");
                        scanf("%d", &mes);
                        printf("Digite o novo ano de entrega (>=2024): ");
                        scanf("%d", &ano);

                        if (!validarData(dia, mes, ano)) {
                            printf("Data inválida. Tente novamente.\n");
                        }
                    } while (!validarData(dia, mes, ano));
                    sprintf(taskDataEntrega, "%02d/%02d/%d", dia, mes, ano);
                    break;
                }

                case 3:
                    printf("Digite o novo resumo da task: ");
                    scanf(" %[^\n]", taskResumo);
                    break;

                case 4:
                    printf("Task excluída com sucesso!\n");
                    continue;  
                default:
                    printf("Opção inválida.\n");
            }
        }

        
        fprintf(tempFile, "TaskID: %d, UserID: %d, Nome: %s, Data: %s, Resumo: %s\n", taskID, taskUserID, taskNome, taskDataEntrega, taskResumo);
    }

    if (!taskFound) {
        printf("Nenhuma task encontrada com esse ID.\n");
    }

    fclose(file);
    fclose(tempFile);

    
    remove("tasks.txt");
    rename("tasks_temp.txt", "tasks.txt");
}
