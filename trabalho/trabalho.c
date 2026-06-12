#include <stdio.h>
int main () {
    int opcao = 0;
    do {
        printf("MENU PRINCIPAL\n");
        printf("1 - Cadastrar registro\n");
        printf("2 - Listar registros\n");
        printf("3 - Buscar registro pelo identificador unico\n");
        printf("4 - Atualizar registro\n");
        printf("5 - Remover registro\n");
        printf("6 - Sair\n");
        printf("Escolha uma opcao > ");
        scanf("%i", &opcao);
        while(getchar() != '\n');

    switch(opcao) {
        case 1: printf("\n"); break;
        case 2: printf("\n"); break;
        case 3: printf("\n"); break;
        case 4: printf("\n"); break;
        case 5: printf("\n"); break;
        case 6: printf("\nSaindo do sistema... Ate logo!\n"); break;
        default: printf("Opcao invalida! Tente novamente.\n");
    }
    
    } while (opcao != 6);

    return 0;
}