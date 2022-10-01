#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../headers.h"

void mapear_response(char buffer[1024], struct Login_usuario_model model);

void login_usuario_controller(char * usuario, char * senha, char buffer[1024]) {
    struct Login_usuario_model model = login_usuario_usecase(usuario, senha);
    mapear_response(buffer, model);
}

void mapear_response(char buffer[1024], struct Login_usuario_model model) {
    char erro[2];

    sprintf(erro, "%d", model.erro);
    strcat(buffer, erro);
    strcat(buffer, ";");

    strcat(buffer, model.mensagem);
    strcat(buffer, ";");

    strcat(buffer, model.login_usuario.usuario);
    strcat(buffer, ";");

    strcat(buffer, model.login_usuario.senha);
    strcat(buffer, ";");
}