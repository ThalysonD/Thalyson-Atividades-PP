#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_NOTE_LENGTH 1000

void clean_buffer() {
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}

size_t len(char * str) {
  size_t length = 0;
  while (*str != '\0') {
    length++;
    str++;
  }
  return length;
}

void ncopy(char * orig, char * dest, size_t n) {
  int i;
  for (i = 0; i < n && orig[i] != '\0'; i++) {
    dest[i] = orig[i];
  }
  dest[i] = '\0';
}

int fexists(const char * filename) {
  FILE * file = fopen(filename, "r");
  if (file != NULL) {
    fclose(file);
    return 1;
  }
  return 0;
}

void novo(char * filename) {
  printf("Digite o nome do arquivo a ser criado: ");
  scanf("%s", filename);
  clean_buffer();

  FILE * file = fopen(filename, "w");
  if (file == NULL) {
    printf("Erro ao criar o arquivo.\n");
    return;
  }

  printf("Arquivo %s criado com sucesso.\n", filename);

  fclose(file);
}

void acrescentar(char * filename) {
  if (!fexists(filename)) {
    printf("Arquivo %s não existe.\n", filename);
    return;
  }

  FILE * file = fopen(filename, "a");
  if (file == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  printf("Digite as notas a serem acrescentadas ao arquivo.\n");
  printf("Pressione Enter em uma linha vazia para encerrar.\n");

  char note[MAX_NOTE_LENGTH];
  while (1) {
    fgets(note, MAX_NOTE_LENGTH, stdin);
    if (note[0] == '\n') {
      break;
    }
    fputs(note, file);
  }

  fclose(file);
}

int main() {
  char filename[MAX_FILENAME_LENGTH] = "";
  int option;

  while (1) {
    printf("Meu Diário\n");
    printf("==========\n");
    printf("[Arquivo: %s]\n", filename);
    printf("1. Novo\n");
    printf("2. Acrescentar\n");
    printf("0. Sair\n");
    printf("Digite opção: ");
    scanf("%d", &option);
    clean_buffer();

    switch (option) {
      case 1:
        novo(filename);
        break;
      case 2:
        acrescentar(filename);
        break;
      case 0:
        printf("Encerrando o programa.\n");
        return 0;
      default:
        printf("Opção inválida.\n");
        break;
    }

    printf("\n");
  }

  return 0;
}