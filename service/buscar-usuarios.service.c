#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../headers.h"

void mapear_resposta();

char buscar_usuarios_response[1024] = {};

struct Usuario usuario_model[1024] = {};
struct Buscar_usuarios_model model = {0, "", 0};

struct Buscar_usuarios_model buscar_usuarios_service()
{
    socket_client("GET/usuarios", buscar_usuarios_response);
    mapear_resposta();
    return model;
}

void mapear_resposta()
{
    int coluna = 0;
    int coluna_usuario = 1;
    char mensagem[1024];
    int contador_registros = 0;
    char quantidade_usuarios_char[10];

    char usuario[300] = "";
    char senha[300] = "";
    char id[5] = "";

    model.mensagem = "";
    model.erro = atoi(&buscar_usuarios_response[0]);

    for (int i = 0; i < strlen(buscar_usuarios_response); i++)
    {
        if (buscar_usuarios_response[i] == '\n')
            continue;

        if (buscar_usuarios_response[i] == ';' && coluna == 0)
        {
            coluna += 1;
            continue;
        }

        if (buscar_usuarios_response[i] == ';' && coluna == 1)
        {
            coluna += 1;
            model.mensagem = mensagem;
            continue;
        }

        if (buscar_usuarios_response[i] == ';' && coluna == 2)
        {
            model.quantidade_usuarios = atoi(quantidade_usuarios_char);
            coluna += 1;
            continue;
        }

        if (coluna == 1)
        {
            strncat(mensagem, &buscar_usuarios_response[i], 1);
        }

        if (coluna == 2)
        {
            strncat(quantidade_usuarios_char, &buscar_usuarios_response[i], 1);
        }

        if (coluna == 3)
        {

            if (buscar_usuarios_response[i] == ',' && coluna_usuario == 1)
            {
                coluna_usuario += 1;
                strcpy(usuario_model[contador_registros].id, id);
                continue;
            }

            if (buscar_usuarios_response[i] == ',' && coluna_usuario == 2)
            {
                coluna_usuario += 1;
                strcpy(usuario_model[contador_registros].usuario, usuario);
                continue;
            }

            if (buscar_usuarios_response[i] == ';' && coluna_usuario == 3)
            {
                strcpy(usuario_model[contador_registros].senha, senha);
                coluna_usuario = 1;
                contador_registros += 1;
                strcpy(id, "");
                strcpy(usuario, "");
                strcpy(senha, "");
                continue;
            }

            if (coluna_usuario == 1)
            {
                strncat(id, &buscar_usuarios_response[i], 1);
            }

            if (coluna_usuario == 2)
            {
                strncat(usuario, &buscar_usuarios_response[i], 1);
            }

            if (coluna_usuario == 3)
            {
                strncat(senha, &buscar_usuarios_response[i], 1);
            }
        }
    }

    model.usuarios = usuario_model;
}