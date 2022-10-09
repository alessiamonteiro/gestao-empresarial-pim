#include "../headers.h"
#include "../constantes.h"

void login_page() {
    char user[22];
    char senha_usuario[22];

    system("clear");
    puts(TEXTO_TITULO_LOGIN);

    puts("\nusuario: \n");
    scanf("%s", user);

    puts("senha:\n");
    scanf("%s", senha_usuario);

    struct Login_usuario_model usecase_retorno = login_usuario_service(user, senha_usuario);

    if (usecase_retorno.erro == true)
    {
        puts(usecase_retorno.mensagem);
        system("sleep 03");
        login_page();
        return;
    }

    strcpy(usuario_logado, usecase_retorno.login_usuario.usuario);
    strcpy(senha_usuario_logado, usecase_retorno.login_usuario.senha);

    puts(usecase_retorno.mensagem);
    system("sleep 03");
    home_page();
    return;
}