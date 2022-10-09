#include "../headers.h"

void router(char buffer[1024]) {
    char *rota_login = strstr(buffer, "GET/login");
    char *rota_cadastro = strstr(buffer, "POST/usuarios");
    bool rota_buscar_usuarios = strcmp(buffer, "GET/usuarios") == 0;

    if (rota_buscar_usuarios)
    {
      buscar_usuarios_controller(buffer);
    }

    if (rota_login)
    {
      login_usuario_controller(buffer);
    }

    if (rota_cadastro)
    {
      criar_usuario_controller(buffer);
    }
}