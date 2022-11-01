#include "../headers.h"

struct Criar_usuario_model mapear_criar_usuario_model(char buffer[1024]);

struct Criar_usuario_model criar_usuario_service(char usuario[22], char senha[22]) {
    char response[1024] = {};
    char url[60] = "POST/usuarios";
    strcat(url, "?user=");
    strcat(url, usuario);

    strcat(url, "&pass=");
    strcat(url, senha);

    socket_client(url, response);
    puts(response);

    return mapear_criar_usuario_model(response);
}

struct Criar_usuario_model mapear_criar_usuario_model(char buffer[1024]) {
    int coluna = 1;
    char erro[2];
    char mensagem[151];
    char usuario[22];

    struct Criar_usuario_model model = {0, ""};
    for (int i = 0; i < strlen(buffer); i++)
    {
        if (buffer[i] == ';') {
            coluna += 1;
            continue;
        }

        if (coluna == 1) {
            strncat(erro, &buffer[i], 1);
        }

        // mensagem
        if (coluna == 2) {
            strncat(mensagem, &buffer[i], 1);
        }

        //usuario
        if (coluna == 3) {
            strncat(usuario, &buffer[i], 1);
        }
    }

    model.erro = atoi(erro);
    model.mensagem = mensagem;
    model.usuario = usuario;
    return model;
}