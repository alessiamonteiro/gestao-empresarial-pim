#include "../headers.h"
#include "../constantes.h"

void cadastro_page(int erro)
{
    system("clear");
    char user[22];
    char senha_usuario[22];
    char confirmacao_senha[22];
    const int VERDADEIRO = 0;

    puts(TEXTO_TITULO_CADASTRO_USUARIO);

    printf("\n REGRAS \n");
    printf(" 1. O usuario e senha devem conter entre 3 e 20 caracteres\n");
    printf(" 2. Não podem ser utilizados espaços nem os seguintes caracteres ; & = ,\n");
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

    if (usuario_senha_invalido(user))
        return cadastro_page(ERRO_USUARIO_INVALIDO);

    puts("\n Digite sua senha: ");
    scanf("%s", senha_usuario);

    if (usuario_senha_invalido(senha_usuario))
        return cadastro_page(ERRO_SENHA_INVALIDA);

    puts("\n Confirme sua senha: ");
    scanf("%s", confirmacao_senha);

    int senhas_iguais = strcmp(confirmacao_senha, senha_usuario);

    if (senhas_iguais != VERDADEIRO)
        return cadastro_page(ERRO_SENHA_INVALIDA);

    struct Criar_usuario_model model = criar_usuario_service(user, senha_usuario);
    puts("\n");
    puts(model.mensagem);
    system("sleep 03");

    model.erro == true
        ? cadastro_page(ERRO_CADASTRO_USUARIO)
        : login_page();
}