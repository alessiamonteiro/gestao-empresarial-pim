#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../headers.h"

void mapear_criar_usuario_response(char buffer[1024], struct Criar_usuario_model model);

void criar_usuario_controller(char * usuario, char * senha, char buffer[1024]) {
    struct Criar_usuario_model model = criar_usuario_usecase(usuario, senha);
    mapear_criar_usuario_response(buffer, model);
    puts(buffer);
}

void mapear_criar_usuario_response(char buffer[1024], struct Criar_usuario_model model) {
    char erro[2];

    sprintf(erro, "%d", model.erro);
    strcat(buffer, erro);
    strcat(buffer, ";");

    strcat(buffer, model.mensagem);
    strcat(buffer, ";");

    strcat(buffer, model.usuario);
    strcat(buffer, ";");
}