#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../headers/buscar-usuarios.controller.h"
#include "../../dataprovider/headers/buscar-usuarios.repository.h"

void buscar_usuarios_controller(char buffer[1024])
{
    struct Buscar_usuarios_repository repository_retorno = buscar_usuarios_repository();
    char quantidade_usuarios[21];
    char erro_repository[2];

    sprintf(erro_repository, "%d", repository_retorno.erro);
    sprintf(quantidade_usuarios, "%d", repository_retorno.quantidade_usuarios);

    strcat(buffer, erro_repository);
    strcat(buffer, ",");

    strcat(buffer, repository_retorno.mensagem);
    strcat(buffer, ",");

    strcat(buffer, quantidade_usuarios);

    if (repository_retorno.erro == true && repository_retorno.quantidade_usuarios == 0)
    {
        strcat(buffer, ";");
        return;
    }
 
    strcat(buffer, ",");
  
    for (int i = 0; i < repository_retorno.quantidade_usuarios; i++)
    {
        strcat(buffer, repository_retorno.usuarios[i].id);
        strcat(buffer, ",");

        strcat(buffer, repository_retorno.usuarios[i].usuario);
        strcat(buffer, ",");

        strcat(buffer, repository_retorno.usuarios[i].senha);
        strcat(buffer, ";");
    }
}