#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Register() {
  char nome[50];
  char cpf[12];
  char senha[20];
  int id = 0;
  int cpf_existe = 0;

  FILE *file = fopen("users.txt", "a+");
  if (file == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }

  printf("Digite seu CPF (apenas números): ");
  scanf("%s", cpf);

  FILE *file_check = fopen("users.txt", "r");
  if (file_check == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    fclose(file);
    return;
  }

  char buffer[100];
  char cpf_registrado[12];

  while (fgets(buffer, 100, file_check) != NULL) {
    sscanf(buffer, "ID: %*d, Nome: %*s, CPF: %s", cpf_registrado);
    if (strcmp(cpf_registrado, cpf) == 0) {
      cpf_existe = 1;
      break;
    }
    id++;
  }

  fclose(file_check);

  if (cpf_existe) {
    printf("CPF já registrado! Tente novamente com outro CPF.\n");
    fclose(file);
    return;
  }

  printf("Digite seu nome: ");
  scanf("%s", nome);
  printf("Digite sua senha: ");
  scanf("%s", senha);

  fprintf(file, "ID: %d, Nome: %s, CPF: %s, Senha: %s\n", id + 1, nome, cpf,
          senha);

  printf("Cadastro realizado com sucesso! Seu ID é: %d\n", id + 1);

  fclose(file);
}
