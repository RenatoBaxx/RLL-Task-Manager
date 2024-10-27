#include <stdio.h>
#include <string.h>

#define MAX_EQUIPES 100
#define TAM_NOME 50

void editar_equipe() {
    FILE *file;
    char equipes[MAX_EQUIPES][TAM_NOME];
    int total_equipes = 0;
    int i, escolha;
    char novo_nome[TAM_NOME];

    file = fopen("equipes.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fscanf(file, "Equipe: %s\n", equipes[total_equipes]) != EOF) {
        total_equipes++;
    }
    fclose(file);

    printf("Equipes disponíveis:\n");
    for (i = 0; i < total_equipes; i++) {
        printf("%d - %s\n", i + 1, equipes[i]);
    }

    printf("Digite o número da equipe que deseja editar: ");
    scanf("%d", &escolha);
    escolha--;

    if (escolha < 0 || escolha >= total_equipes) {
        printf("Escolha inválida!\n");
        return;
    }

    printf("Digite o novo nome para a equipe %s: ", equipes[escolha]);
    scanf("%s", novo_nome);

    strcpy(equipes[escolha], novo_nome);

    file = fopen("equipes.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    for (i = 0; i < total_equipes; i++) {
        fprintf(file, "Equipe: %s\n", equipes[i]);
    }
    fclose(file);

    printf("Equipe editada com sucesso!\n");
}
