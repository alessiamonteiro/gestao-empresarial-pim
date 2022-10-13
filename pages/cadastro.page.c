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

void cadastro_page()
{
    char user[22];
    char senha_usuario[22];
    char confirmacao_senha[22];

    const int VERDADEIRO = 0;

    // struct Funcionario x = {0, "João Pedro", "01236547898", "012365478", 1, 2000, 0, 0, 1562930130, 1562930130, 1562930130};    
    // struct Criar_funcionario_model z = criar_funcionario_repository(1, x);

    printf(TEXTO_TITULO_CADASTRO);

    printf("\n REGRAS \n");
    printf(" 1. O usuario e senha devem conter no máximo 20 caracteres \n");
    printf(" 2. Nao podem ser utilizados os seguintes caracteres ; & = ,");

    puts("\n\n Digite seu user:");
    scanf("%s", user);

    if (possui_caracteres_invalidos(user) || strlen(user) > 20)
    {
        puts("\n ATENCAO \n usuario inválido, se atente com as regras");
        system("sleep 03");
        cadastro_page();
        return;
    }

    puts("\n Digite sua senha: ");
    scanf("%s", senha_usuario);

    if (possui_caracteres_invalidos(senha_usuario) || strlen(user) > 20)
    {
        puts("\n ATENCAO \n senha inválida, se atente com as regras");
        system("sleep 03");
        cadastro_page();
        return;
    }

    puts("\n Confirme sua senha: ");
    scanf("%s", confirmacao_senha);

    int valida_confirmacao_senha = strcmp(confirmacao_senha, senha_usuario);

    if (valida_confirmacao_senha != VERDADEIRO)
    {
        puts(TEXTO_ERRO_CONFIRMACAO_SENHA);
        system("sleep 02");
        cadastro_page();
        return;
    }

    struct Criar_usuario_model model = criar_usuario_service(user, senha_usuario);
    puts("\n");
    puts(model.mensagem);
    system("sleep 03");

    if (model.erro == true)
    {
        cadastro_page();
    }
    else
    {
        login_page();
    }
}