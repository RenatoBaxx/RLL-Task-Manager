#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void menu(int userID) {
    int opcao = 0;

    do {
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

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                dashboard(userID); 
                break;
            case 2:
                criarTask(userID);  
                break;
            case 3:
                editarTask(userID); 
                break;
            case 4:
                printf("Criando Equipe...\n");

                break;
            case 5:
                printf("Editando Equipe...\n");

                break;
            case 6:
                printf("Exibindo Equipes...\n");

                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 7);
}

int main(void) {
    printf("Bem Vindo ao sistema RRL-Task-Manager\n");
    printf("-------------------------------------\n");
    printf("1- Login\n");
    printf("2- Registrar\n");
    printf("3- Sair\n");
    printf("-------------------------------------\n");
    printf("Digite a opção desejada: ");

    int opcaoinicio = 0;
    int userID = -1; 
    scanf("%d", &opcaoinicio);

    if (opcaoinicio == 1) {
        login(); 
        userID = 1; 
    } else if (opcaoinicio == 2) {
        Register();
        printf("Agora faça o login para acessar o sistema.\n");
        return 0;  
    } else if (opcaoinicio == 3) {
        printf("Saindo...\n");
        return 0;
    } else {
        printf("Opção inválida. Encerrando programa...\n");
        return 0;
    }


    if (userID != -1) {
        menu(userID);
    }

    return 0;
}