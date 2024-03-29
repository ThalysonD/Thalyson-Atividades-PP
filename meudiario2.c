
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void novo(char **filename);
void acrescentar(char *filename);
void carregar(char **filename);
void apagar(char **filename);

int main() {
    char *filename = NULL;
    int opcao;
    while (1) {
        printf("Meu Diario\n");
        printf("==========\n");
        printf("[Arquivo: %s]\n", filename == NULL ? "vazio" : filename);
        printf("1. Novo\n");
        printf("2. Acrescentar\n");
        printf("3. Carregar\n");
        printf("4. Apagar\n");
        printf("0. Sair\n");
        printf("Digite opcao: ");
        scanf("%d", &opcao);
        while(getchar() != '\n'); // Limpa o buffer do teclado

        switch (opcao) {
            case 0:
                if (filename != NULL) {
                    free(filename);
                }
                printf("Ate a proxima!\n");
                return 0;
            case 1:
                novo(&filename);
                break;
            case 2:
                acrescentar(filename);
                break;
            case 3:
                carregar(&filename);
                break;
            case 4:
                apagar(&filename);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
}

void novo(char **filename) {
    FILE *arquivo;
    char linha[100];
    printf("Digite o nome do arquivo: ");
    if (*filename != NULL) {
        printf("Ja existe um arquivo aberto. Deseja fecha-lo (s/n)? ");
        char resposta;
        scanf("%c", &resposta);
        while(getchar() != '\n'); // Limpa o buffer do teclado
        if (resposta == 's') {
            free(*filename);
            *filename = NULL;
        } else {
            printf("Operacao cancelada.\n");
            return;
        }
    }
    *filename = (char*) malloc(sizeof(char) * 101);
    scanf("%100[^\n]", *filename);
    arquivo = fopen(*filename, "w");
    if (arquivo == NULL) {
        printf("Nao foi possivel criar o arquivo.\n");
        free(*filename);
        *filename = NULL;
        return;
    }
    printf("Digite o texto (para encerrar, digite uma linha vazia):\n");
    while (fgets(linha, 100, stdin) != NULL) {
        if (linha[0] == '\n') {
            break;
        }
        fprintf(arquivo, "%s", linha);
    }
    fclose(arquivo);
}

void acrescentar(char *filename) {
    FILE *arquivo;
    char linha[100];
    printf("Digite o nome do arquivo: ");
    if (filename == NULL) {
        filename = (char*) malloc(sizeof(char) * 101);
        scanf("%100[^\n]", filename);
    } else {
        printf("%s ja esta aberto.\n", filename);
    }
    arquivo = fopen(filename, "a");
    if (arquivo == NULL) {
        printf("Nao foi possível abrir o arquivo.\n");
        return;
        }
    printf("Digite o texto(para encerrar digite uma linha vazia)\n");
    while(fgets(linha, 100, stdin) != NULL){
        if(linha[0] == '\n'){
            break;
        }
        fprintf(arquivo, "%s", linha);
    }
    fclose(arquivo);
}
void carregar(char **filename) {

    FILE *arquivo;

    char linha[100];

    char *novo_nome = NULL;

    printf("Digite o nome do arquivo: ");

    if (*filename == NULL) {

        novo_nome = (char*) malloc(sizeof(char) * 101);

        scanf("%100[^\n]", novo_nome);

    } else {

        printf("%s ja esta aberto. Deseja fecha-lo (s/n)? ", *filename);

        char resposta;

        scanf("%c", &resposta);

        while(getchar() != '\n'); // Limpa o buffer do teclado

        if (resposta == 's') {

            free(*filename);

            *filename = NULL;

        } else {

            printf("Operacao cancelada.\n");

            return;

        }

        novo_nome = (char*) malloc(sizeof(char) * 101);

        scanf("%100[^\n]", novo_nome);

    }

    arquivo = fopen(novo_nome, "r");

    if (arquivo == NULL) {

        printf("Nao foi possivel abrir o arquivo.\n");

        free(novo_nome);

        novo_nome = NULL;

        return;

    }

    *filename = novo_nome;

    printf("Conteudo do arquivo:\n");

    while (fgets(linha, 100, arquivo) != NULL) {

        printf("%s", linha);

    }

    fclose(arquivo);

}

void apagar(char **filename) {

    if (*filename == NULL) {

        printf("Nao ha arquivo aberto.\n");

        return;

    }

    printf("Tem certeza que deseja apagar o arquivo %s (s/n)? ", *filename);

    char resposta;

    scanf("%c", &resposta);

    while(getchar() != '\n'); // Limpa o buffer do teclado

    if (resposta == 's') {

        if (remove(*filename) == 0) {

            printf("Arquivo apagado com sucesso.\n");

            free(*filename);

            *filename = NULL;

        } else {

            printf("Nao foi possivel apagar o arquivo.\n");

        }

    } else {

        printf("Operacao cancelada.\n");

    }

}