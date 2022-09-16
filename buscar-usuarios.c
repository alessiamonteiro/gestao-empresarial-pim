#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "buscar-usuarios.h"

#define MAX_LINE_LENGTH 1000

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
      if (coluna == 3) {
        printf("senha: %s\n", senha);
      }

      contador_registros += 1;
      coluna = 1;
      strcpy(usuario, "");
      strcpy(senha, "");
      strcpy(id, "");
      continue;
    }

    if (ch == '\n')
    {
      contador_registros += 1;
      coluna = 1;
      strcpy(usuario, "");
      strcpy(senha, "");
      strcpy(id, "");
      continue;
    }

    if (ch == ',' && coluna == 1)
    {
      coluna += 1;
      printf("\nid: %s ", id);
      continue;
    }

    if (ch == ',' && coluna == 2)
    {
      coluna += 1;
      printf("nome: %s ", usuario);
      continue;
    }

    if (coluna == 1)
    {
      strncat(id, &ch, 1);
    }

    if (coluna == 2)
    {
      strncat(usuario, &ch, 1);
    }

    if (coluna == 3)
    {
      strncat(senha, &ch, 1);
    }
  }

  contador_registros += 1;
  return contador_registros;
}