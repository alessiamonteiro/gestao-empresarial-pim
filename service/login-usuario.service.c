#include "../headers.h"

struct Login_usuario_model mapear_login_usuario_model(char buffer[1024]);

struct Login_usuario_model login_usuario_service(char usuario[22], char senha[22])
{
    char response[1024] = {};
    char url[60] = "GET/login";
    strcat(url, "?user=");
    strcat(url, usuario);

    strcat(url, "&pass=");
    strcat(url, senha);

    socket_client(url, response);
    return mapear_login_usuario_model(response);
}

struct Login_usuario_model mapear_login_usuario_model(char buffer[1024])
{
    int coluna = 1;
    char erro[2] = "0";
    char mensagem[151] = "";
    char usuario[22] = "";
    char senha[22] = "";
    
    struct Login_usuario login_usuario = {};
    struct Login_usuario_model model = {};

    strcpy(erro, &buffer[0]);
    model.erro = atoi(erro);
    
    for (int i = 0; i < strlen(buffer); i++)
    {
        if (buffer[i] == ';')
        {
            coluna += 1;
            continue;
        }

        switch (coluna)
        {
        case 2:
            strncat(mensagem, &buffer[i], 1);
            break;
        
        case 3:
            strncat(usuario, &buffer[i], 1);
            break;
        
        case 4:
            strncat(senha, &buffer[i], 1);
            break;
        
        default:
            break;
        }
    }

    strcpy(login_usuario.usuario, usuario);
    strcpy(login_usuario.senha, senha);
    strcpy(model.mensagem, mensagem);

    model.login_usuario = login_usuario;
    return model;
}
