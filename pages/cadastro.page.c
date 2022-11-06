#include "../headers.h"
#include "../constantes.h"

bool possui_caracteres_invalidos(char string[]);

// poderia estar em um arquivo de utils
bool possui_caracteres_invalidos(char string[])
{
    return strstr(string, ";") ||
           strstr(string, "&") ||
           strstr(string, "=") ||
           strstr(string, ",");
}
// poderia estar em um arquivo de utils

void cadastro_page(int erro)
{
    system("clear");
    char user[22];
    char senha_usuario[22];
    char confirmacao_senha[22];
    const int VERDADEIRO = 0;

    puts(TEXTO_TITULO_CADASTRO_USUARIO);

    printf("\n REGRAS \n");
    printf(" 1. O usuario e senha devem conter no máximo 20 caracteres\n");
    printf(" 2. Nao podem ser utilizados os seguintes caracteres ; & = ,\n");
    printf(" 3. A senha e a confirmação de senha digitadas devem ser idênticas\n");

    switch (erro)
    {
    case ERRO_USUARIO_INVALIDO:
        puts(TEXTO_ERRO_CADASTRO_USUARIO_INVALIDO);
        break;

    case ERRO_SENHA_INVALIDA:
        puts(TEXTO_ERRO_CADASTRO_SENHA_INVALIDA);
        break;
    
    case ERRO_CADASTRO_USUARIO:
        puts(TEXTO_ERRO_CADASTRO_USUARIO);
        break;

    default:
        break;
    }

    puts("\n Digite seu user:");
    scanf("%s", user);

    if (possui_caracteres_invalidos(user) || strlen(user) > 20)
    {
        cadastro_page(ERRO_USUARIO_INVALIDO);
        return;
    }

    puts("\n Digite sua senha: ");
    scanf("%s", senha_usuario);

    if (possui_caracteres_invalidos(senha_usuario) || strlen(user) > 20)
    {
        cadastro_page(ERRO_SENHA_INVALIDA);
        return;
    }

    puts("\n Confirme sua senha: ");
    scanf("%s", confirmacao_senha);

    int valida_confirmacao_senha = strcmp(confirmacao_senha, senha_usuario);

    if (valida_confirmacao_senha != VERDADEIRO)
    {
        cadastro_page(ERRO_SENHA_INVALIDA);
        return;
    }

    struct Criar_usuario_model model = criar_usuario_service(user, senha_usuario);
    puts("\n");
    puts(model.mensagem);
    system("sleep 03");

    if (model.erro == true)
    {
        cadastro_page(ERRO_CADASTRO_USUARIO);
    }
    else
    {
        login_page();
    }
}