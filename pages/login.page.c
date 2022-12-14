#include "../headers.h"
#include "../constantes.h"

void login_page(int erro)
{
    char user[22];
    char senha_usuario[22];

    system("clear");
    puts(TEXTO_TITULO_LOGIN);

    if (erro == 1)
        puts(TEXTO_ERRO_LOGIN);

    puts("\nusuario: ");
    scanf("%s", user);

    puts("\nsenha: ");
    scanf("%s", senha_usuario);

    struct Login_usuario_model usecase_retorno = login_usuario_service(user, senha_usuario);

    if (usecase_retorno.erro == true)
        return login_page(1);

    strcpy(usuario_logado, user);
    strcpy(senha_usuario_logado, senha_usuario);

    puts(usecase_retorno.mensagem);
    system("sleep 03");
    home_page(false);
    return;
}