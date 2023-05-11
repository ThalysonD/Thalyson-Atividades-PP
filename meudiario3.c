#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME_ARQUIVO 100
#define MAX_LINHA 100

char nome_arquivo[MAX_NOME_ARQUIVO];
FILE *arquivo;

void novo_arquivo(char *nome_arquivo);
void acrescentar_arquivo(char *nome_arquivo);
void carregar_arquivo(char *nome_arquivo);
void apagar_arquivo(char *nome_arquivo);
void visualizar(char *filename);
size_t tamanho(char *filename);

int main() {
    int opcao = -1;
    while (opcao != 0) {
        printf("Meu Diário\n");
        printf("==========\n");
        printf("[Arquivo: %s]\n", nome_arquivo);
        printf("1. Novo\n");
        printf("2. Acrescentar\n");
        printf("3. Carregar\n");
        printf("4. Apagar\n");
        printf("5. Visualizar\n");
        printf("6. Tamanho [bytes]\n");
        printf("0. Sair\n");
        printf("Digite opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                novo_arquivo(nome_arquivo);
                break;
            case 2:
                acrescentar_arquivo(nome_arquivo);
                break;
            case 3:
                carregar_arquivo(nome_arquivo);
                break;
            case 4:
                apagar_arquivo(nome_arquivo);
                break;
            case 5:
                visualizar(nome_arquivo);
                break;
            case 6:
                printf("Tamanho do arquivo em bytes: %ld\n", tamanho(nome_arquivo));
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    }

    return 0;
}

void novo_arquivo(char *nome_arquivo) {
    printf("Digite o nome do arquivo: ");
    fgets(nome_arquivo, MAX_NOME_ARQUIVO, stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = 0; // Remove o caractere de nova linha

    if ((arquivo = fopen(nome_arquivo, "w")) == NULL) {
        printf("Erro ao criar o arquivo!\n");
    } else {
        printf("Arquivo criado com sucesso!\n");
        fclose(arquivo);
    }
}

void acrescentar_arquivo(char *nome_arquivo) {
    if ((arquivo = fopen(nome_arquivo, "a")) == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    } else {
        printf("Digite o texto a ser adicionado no arquivo (Digite uma linha vazia para finalizar):\n");
        char linha[MAX_LINHA];
        while (fgets(linha, MAX_LINHA, stdin) != NULL) {
            if(strcmp(linha, "\n") == 0) {
                break;
            }
            fprintf(arquivo, "%s", linha);
        }
        fclose(arquivo);
    }
}

void carregar_arquivo(char *nome_arquivo) {
    if ((arquivo = fopen(nome_arquivo, "r")) == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    } else {
        printf("Conteúdo do arquivo:\n");
        char linha[MAX_LINHA];
        while (fgets(linha, MAX_LINHA, arquivo) != NULL) {
            printf("%s", linha);
        }
        fclose(arquivo);
    }
}

void apagar_arquivo(char *nome_arquivo) {

if (remove(nome_arquivo) == 0) {

printf("Arquivo apagado com sucesso!\n");

nome_arquivo[0] = '\0'; // Limpa o nome do arquivo ativo

} else {

printf("Erro ao apagar o arquivo!\n");

}

}

void visualizar(char *filename) {

if ((arquivo = fopen(filename, "r")) == NULL) {

printf("Erro ao abrir o arquivo!\n");

} else {

printf("Conteúdo do arquivo:\n");

char linha[MAX_LINHA];

while (fgets(linha, MAX_LINHA, arquivo) != NULL) {

printf("%s", linha);

}

fclose(arquivo);

}

}

size_t tamanho(char *filename) {

FILE *arquivo;

if ((arquivo = fopen(filename, "rb")) == NULL) {

printf("Erro ao abrir o arquivo!\n");

return 0;

}

fseek(arquivo, 0, SEEK_END);

size_t tamanho = ftell(arquivo);

fclose(arquivo);

return tamanho;

}
