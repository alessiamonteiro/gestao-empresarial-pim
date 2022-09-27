#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../../headers.h"

void mapear_resposta();

void buscar_usuarios_controller(char buffer[1024])
{
    //TODO criar buscar_usuarios_usecase -> controller deve chamar usecase
    struct Buscar_usuarios_model repository_retorno = buscar_usuarios_repository();
    mapear_resposta(buffer, repository_retorno);
}

void mapear_resposta(char buffer[1024], struct Buscar_usuarios_model repository_retorno) {
    char quantidade_usuarios[21];
    char erro_repository[2];

    sprintf(erro_repository, "%d", repository_retorno.erro);
    sprintf(quantidade_usuarios, "%d", repository_retorno.quantidade_usuarios);

    strcat(buffer, erro_repository);
    strcat(buffer, ";");

    strcat(buffer, repository_retorno.mensagem);

    strcat(buffer, ";");

    if (repository_retorno.erro == true && repository_retorno.quantidade_usuarios == 0)
    {
        strcat(buffer, "\n");
        return;
    }

    strcat(buffer, quantidade_usuarios);
    strcat(buffer, ";");
  
    for (int i = 0; i < repository_retorno.quantidade_usuarios; i++)
    {
        strcat(buffer, repository_retorno.usuarios[i].id);
        strcat(buffer, ",");

        strcat(buffer, repository_retorno.usuarios[i].usuario);
        strcat(buffer, ",");

        strcat(buffer, repository_retorno.usuarios[i].senha);
        strcat(buffer, ";");
    }

    strcat(buffer, "\n");
}