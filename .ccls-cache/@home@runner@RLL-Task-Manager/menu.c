#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void menu() {
  int opcao = 0;

  printf("---------[RRL-Task-Manager]----------\n");
  printf("-------------------------------------\n");
  printf("1- Minha Dashboard\n");
  printf("2- Adicionar Task\n");
  printf("3- Editar Task\n");
  printf("4- Criar Equipe\n");
  printf("5- Editar Equipe\n");
  printf("6- Ver Equipes\n");
  printf("7- Sair\n");
  printf("-------------------------------------\n");
  printf("Digite a opção desejada: ");
  scanf("Digite a opção desejada: %d", &opcao);
}

int main(void) {
  login();
  menu();
  return 0;
}