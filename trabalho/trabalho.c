#include <stdio.h>
#include <string.h>

#define MAXIMO_REGISTROS 10
#define TAMANHO_NOME      50
#define TAMANHO_CATEGORIA 30

typedef struct {
    int    identificador;
    char   nome[TAMANHO_NOME];
    char   categoria[TAMANHO_CATEGORIA];
    float  preco;
    int    quantidade;
} Produto;

int main () {
    Produto estoque[MAXIMO_REGISTROS];
    int total = 0;
    int opcao = 0;
    int busca_id = 0;
    int indice = -1;
    int i = 0;
    int novo_id = 0;
    char novonome[TAMANHO_NOME];
    char novacategoria[TAMANHO_CATEGORIA];
    float novopreco = 0.0f;
    int novaquantidade = 0;
    int identificadorrepetido = 0;
    
    do {
        printf("MENU PRINCIPAL\n");
        printf("1 - Cadastrar registro\n");
        printf("2 - Listar registros\n");
        printf("3 - Buscar registro pelo identificador unico\n");
        printf("4 - Atualizar registro\n");
        printf("5 - Remover registro\n");
        printf("6 - Sair\n");
        printf("Registros: %d / %d\n", total, MAXIMO_REGISTROS);
        printf("Escolha uma opcao > ");

        if (scanf("%d", &opcao) != 1) {
            opcao = -1;
        }
        while (getchar() != '\n');

    switch(opcao) {
        case 1:
            if (total >= MAXIMO_REGISTROS) {
                printf("Estoque cheio! O sistema ja possui %d registros.\n", MAXIMO_REGISTROS);
            } else {
                printf("\n       CADASTRO DE PRODUTO\n");
                printf("=================================\n");
                printf("Entre com um identificador unico para o registro > ");
                while (scanf("%d", &novo_id) != 1 || novo_id <= 0) {
                    while (getchar() != '\n');
                    printf("Entrada invalida. Entre com um inteiro positivo: ");
                }
                while (getchar() != '\n');
                identificadorrepetido = 0;
                for (i = 0; i < total; i++) {
                    if (estoque[i].identificador == novo_id) {
                        identificadorrepetido = 1;
                        break;
                    }
                }
                if (identificadorrepetido) {
                    printf("Ja existe um registro para o ID %d.\n", novo_id);
                } else {
                    printf("Entre com um nome para registro, com ate %d caracteres > ", TAMANHO_NOME - 1);
                    fgets(novonome, TAMANHO_NOME, stdin);
                    novonome[strcspn(novonome, "\n")] = '\0';
                    while (strlen(novonome) == 0) {
                        printf("Entrada invalida. O nome nao pode ser vazio. ");
                        fgets(novonome, TAMANHO_NOME, stdin);
                        novonome[strcspn(novonome, "\n")] = '\0';
                    }
                    printf("Entre com uma categoria para registro, com ate %d caracteres > ", TAMANHO_CATEGORIA - 1);
                    fgets(novacategoria, TAMANHO_CATEGORIA, stdin);
                    novacategoria[strcspn(novacategoria, "\n")] = '\0';
                    while (strlen(novacategoria) == 0) {
                        printf("Entrada invalida. A categoria nao pode ser vazia. ");
                        fgets(novacategoria, TAMANHO_CATEGORIA, stdin);
                        novacategoria[strcspn(novacategoria, "\n")] = '\0';
                    }
                    printf("Entre com um preco para registro > R$ ");
                    while (scanf("%f", &novopreco) != 1 || novopreco < 0.0f) {
                        while (getchar() != '\n');
                        printf("Entrada invalida. Entre com um preco maior ou igual a 0. ");
                    }
                    printf("  Quantidade em estoque: ");
                    while (scanf("%d", &novaquantidade) != 1 || novaquantidade < 0) {
                        while (getchar() != '\n');
                        printf("Entrada invalida. Entre com uma quantidade maior ou igual a 0. ");
                    }

                    estoque[total].identificador = novo_id;
                    estoque[total].preco = novopreco;
                    estoque[total].quantidade = novaquantidade;
                    strncpy(estoque[total].nome,      novonome,      TAMANHO_NOME - 1);
                    strncpy(estoque[total].categoria, novacategoria, TAMANHO_CATEGORIA - 1);
                    estoque[total].nome[TAMANHO_NOME - 1]           = '\0';
                    estoque[total].categoria[TAMANHO_CATEGORIA - 1] = '\0';
                    total++;

                    printf("O registro para o ID %d foi realizado com sucesso!\n", novo_id);
                }
            }
            break;
        case 2: 
            if (total == 0) {
                printf("\n Nao ha registros cadastrados.\n");
            } else {
                printf("\nLISTA DE PRODUTOS \n");
                for (i = 0; i < total; i++) {
                    printf("=================================\n");
                    printf("ID: %d\n", estoque[i].identificador);
                    printf("Nome: %s\n", estoque[i].nome);
                    printf("Categoria: %s\n", estoque[i].categoria);
                    printf("Preco: R$ %.2f\n", estoque[i].preco);
                    printf("Quantidade: %d\n", estoque[i].quantidade);
                }
                printf("=================================\n");
                printf("Total: %d produto(s).\n", total);
            }
            break;
        case 3: 
            if (total == 0) {
                printf("\nNao ha registros cadastrados.\n");
            } else {
                printf("\nEntre com o ID unico > ");
                while (scanf("%d", &busca_id) != 1 || busca_id <= 0) {
                    while (getchar() != '\n');
                    printf("Entrada invalida. Entre com um ID maior que 0 > ");
                }
                indice = -1;
                for (i = 0; i < total; i++) {
                    if (estoque[i].identificador == busca_id) {
                        indice = i;
                        break;
                    }
                }
                if (indice == -1) {
                    printf("Nao ha um registro para ID: %d.\n", busca_id);
                } else {
                    printf("\n==========================\n");
                    printf("    PRODUTO ENCONTRADO\n");
                    printf("==========================\n");
                    printf("ID Unico  : %d\n", estoque[indice].identificador);
                    printf("Nome      : %s\n", estoque[indice].nome);
                    printf("Categoria : %s\n", estoque[indice].categoria);
                    printf("Preco     : R$ %.2f\n", estoque[indice].preco);
                    printf("Quantidade: %d\n", estoque[indice].quantidade);
                    printf("==========================\n");
                }
            }
            break;
        case 4:
            if (total == 0) {
                printf("Nao ha registros cadastrados.\n");
            } else {
                printf("Entre com o ID unico do registro para atualiza-lo > ");
                while (scanf("%d", &busca_id) != 1 || busca_id <= 0) {
                    while (getchar() != '\n');
                    printf("Entrada invalida. Entre com um ID maior que 0 > ");
                }
                while (getchar() != '\n');
                indice = -1;
                for (i = 0; i < total; i++) {
                    if (estoque[i].identificador == busca_id) {
                        indice = i;
                        break;
                    }
                }
                if (indice == -1) {
                    printf("Nao ha um registro para ID: %d.\n", busca_id);
                } else {
                    printf("Entre com um novo nome > ");
                    fgets(estoque[indice].nome, TAMANHO_NOME, stdin);
                    estoque[indice].nome[strcspn(estoque[indice].nome, "\n")] = '\0';
                    while (strlen(estoque[indice].nome) == 0) {
                        printf("Entrada invalida. O nome nao pode ser vazio. ");
                        fgets(estoque[indice].nome, TAMANHO_NOME, stdin);
                        estoque[indice].nome[strcspn(estoque[indice].nome, "\n")] = '\0';
                    }

                    printf("Entre com uma nova categoria > ");
                    fgets(estoque[indice].categoria, TAMANHO_CATEGORIA, stdin);
                    estoque[indice].categoria[strcspn(estoque[indice].categoria, "\n")] = '\0';
                    while (strlen(estoque[indice].categoria) == 0) {
                        printf("Entrada invalida. A categoria nao pode ser vazia. ");
                        fgets(estoque[indice].categoria, TAMANHO_CATEGORIA, stdin);
                        estoque[indice].categoria[strcspn(estoque[indice].categoria, "\n")] = '\0';
                    }

                    printf("Entre com um novo preco > R$ ");
                    while (scanf("%f", &estoque[indice].preco) != 1 || estoque[indice].preco < 0.0f) {
                        while (getchar() != '\n');
                        printf("Entrada invalida. Entre com um preco maior ou igual a 0 > ");
                    }

                    printf("Entre com uma nova quantidade > ");
                    while (scanf("%d", &estoque[indice].quantidade) != 1 || estoque[indice].quantidade < 0) {
                        while (getchar() != '\n');
                        printf("Entrada invalida. Entre com uma quantidade maior ou igual a 0 > ");
                    }
                    
                    printf("Registro de ID %d atualizado!\n", busca_id);
                }
            }
            break;
        case 5: 
            if (total == 0) {
                printf("\n Nao ha registros cadastrados.\n");
            } else {
                printf("\n Entre com o ID que deseja remover >  ");
                while (scanf("%d", &busca_id) != 1 || busca_id <= 0) {
                   while (getchar() != '\n');
                   printf("Entrada invalida. Entre com um ID maior que 0 > ");
                }
                indice = -1;
                for (i = 0; i < total; i++) {
                    if (estoque[i].identificador == busca_id) { 
                      indice = i;
                      break; 
                    }
                }
                if (indice == -1) {
                   printf("Nao ha um registro para ID: %d.\n", busca_id);
                } else {
                    for (i = indice; i < total - 1; i++) {
                        estoque[i] = estoque[i + 1];
                    }
                    total--;
                    printf("Registro de ID %d removido. Ainda restam %d registros.\n", busca_id, total);
                }
            }
            break;
        case 6: printf("\nSaindo do sistema... Ate logo!\n"); break;
        default: printf("Opcao invalida! Tente novamente.\n");
    }
    } while (opcao != 6);

    return 0;
}