#include <stdio.h>
#include <string.h>

#define TAM_NOME 50
#define MAX_EQUIPES 100

//funçao de criar equipes

int equipe_existe(const char *nome_equipe, char equipes[][TAM_NOME], int total_equipes) {
    for (int i = 0; i < total_equipes; i++) {
        if (strcmp(nome_equipe, equipes[i]) == 0) {
            return 1; 
        }
    }
    return 0;  
}

void criar_equipe() {
    char nome_equipe[TAM_NOME];
    char equipes[MAX_EQUIPES][TAM_NOME];
    int total_equipes = 0;
    FILE *file;

    file = fopen("equipes.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "Equipe: %s\n", equipes[total_equipes]) != EOF) {
            total_equipes++;
        }
        fclose(file);
    }

    while (1) {
        printf("Digite o nome da nova equipe: ");
        scanf("%s", nome_equipe);

        if (equipe_existe(nome_equipe, equipes, total_equipes)) {
            printf("Erro: A equipe '%s' já existe! Tente novamente.\n", nome_equipe);
        } else {
            break; 
        }
    }

    file = fopen("equipes.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    fprintf(file, "Equipe: %s\n", nome_equipe);
    fclose(file);

    printf("Equipe '%s' criada com sucesso!\n", nome_equipe);
}
void criar_equipe();

