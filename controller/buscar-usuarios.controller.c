#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../headers.h"

void mapear_resposta();

void buscar_usuarios_controller(char buffer[1024])
{
    struct Buscar_usuarios_model model = buscar_usuarios_usecase();
    mapear_resposta(buffer, model);
}

void mapear_resposta(char buffer[1024], struct Buscar_usuarios_model model) {
    char quantidade_usuarios[21];
    char erro_repository[2];

    sprintf(erro_repository, "%d", model.erro);
    sprintf(quantidade_usuarios, "%d", model.quantidade_usuarios);

    strcat(buffer, erro_repository);
    strcat(buffer, ";");

    strcat(buffer, model.mensagem);
    strcat(buffer, ";");

    if (model.erro == true && model.quantidade_usuarios == 0)
    {
        strcat(buffer, "\n");
        return;
    }

    strcat(buffer, quantidade_usuarios);
    strcat(buffer, ";");
  
    for (int i = 0; i < model.quantidade_usuarios; i++)
    {
        strcat(buffer, model.usuarios[i].id);
        strcat(buffer, ",");

        strcat(buffer, model.usuarios[i].usuario);
        strcat(buffer, ",");

        strcat(buffer, model.usuarios[i].senha);
        strcat(buffer, ";");
    }

    strcat(buffer, "\n");
}