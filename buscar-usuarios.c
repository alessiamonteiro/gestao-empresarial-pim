#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "buscar-usuarios.h"

#define MAX_LINE_LENGTH 1000
#define COLUNA_ID 1
#define COLUNA_USUARIO 2
#define COLUNA_SENHA 3

int buscar_usuarios()
{
  FILE *textfile;

  char ch;
  char usuario[21] = "";
  char senha[21] = "";
  char id[3] = "";

  int coluna = 1;
  int contador_registros = 0;

  textfile = fopen("usuarios.txt", "r");

  if (textfile == NULL)
  {
    puts("Ocorreu um erro ao abrir o arquivo");
    return -1;
  }

  while ((ch = fgetc(textfile)) != EOF)
  {

    if (ch == '\n')
    {
      if (coluna == COLUNA_SENHA)
      {
        printf("senha: %s\n", senha);
      }

      contador_registros += 1;
      coluna = COLUNA_ID;
      strcpy(id, "");
      strcpy(usuario, "");
      strcpy(senha, "");
      continue;
    }

    if (ch == ',' && coluna == COLUNA_ID)
    {
      coluna += 1;
      printf("\nid: %s ", id);
      continue;
    }

    if (ch == ',' && coluna == COLUNA_USUARIO)
    {
      coluna += 1;
      printf("nome: %s ", usuario);
      continue;
    }

    if (coluna == COLUNA_ID)
    {
      strncat(id, &ch, 1);
    }

    if (coluna == COLUNA_USUARIO)
    {
      strncat(usuario, &ch, 1);
    }

    if (coluna == COLUNA_SENHA)
    {
      strncat(senha, &ch, 1);
    }
  }

  contador_registros += 1;
  return contador_registros;
}