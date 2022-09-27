#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers.h"

#define COLUNA_ID 1
#define COLUNA_USUARIO 2
#define COLUNA_SENHA 3

struct Usuario usuarios[] = {};

struct Buscar_usuarios_model repository_retorno= {
    0,
    "",
    0,
};

struct Buscar_usuarios_model buscar_usuarios_repository()
{
    FILE *textfile;

    char ch;
    char usuario[21] = "";
    char senha[21] = "";
    char id[5] = "";

    int coluna = 1;
    int contador_registros = 0;

    textfile = fopen("usuarios.txt", "r");

    if (textfile == NULL)
    {
        puts("Ocorreu um erro ao abrir o arquivo");
        repository_retorno.erro = 1;
        repository_retorno.mensagem = "[ERRO] buscar_usuarios_repository";
        repository_retorno.quantidade_usuarios = 0;
        repository_retorno.usuarios = usuarios;
        return repository_retorno;
    }

    while ((ch = fgetc(textfile)) != EOF)
    {
        if (ch == '\n')
        {
            if (coluna == COLUNA_SENHA)
            {
                strcpy(usuarios[contador_registros].senha, senha);
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
            strcpy(usuarios[contador_registros].id, id);
            continue;
        }

        if (ch == ',' && coluna == COLUNA_USUARIO)
        {
            coluna += 1;
            strcpy(usuarios[contador_registros].usuario, usuario);
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

    repository_retorno.erro = 0;
    repository_retorno.mensagem = "[OK] buscar_usuarios_repository";
    repository_retorno.quantidade_usuarios = contador_registros;
    repository_retorno.usuarios = usuarios;

    return repository_retorno;
}