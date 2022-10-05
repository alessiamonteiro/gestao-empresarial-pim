#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "./headers.h"
#include "./constantes.h"

const int VERDADEIRO = 0;
const int ERRO = -1;

void menu();
void login();
void cadastro();
void home();
void buscar_usuarios_todos();
void perfil();

char usuario_logado[21];
char senha_usuario_logado[21];

void menu()
{
    int acao;
    system("reset");
    puts(TEXTO_BEM_VINDO);
    puts(TEXTO_OPCOES_MENU);
    scanf("%i", &acao);

    switch (acao)
    {
    case 1:
        login();
        break;

    case 2:
        cadastro();
        break;

    default:
        puts(TEXTO_OPCAO_INVALIDA);
        menu();
        break;
    }
}

void login()
{
    char user[21];
    char senha_usuario[21];

    system("reset");
    puts(TEXTO_TITULO_LOGIN);

    puts("\nusuario: \n");
    scanf("%s", user);

    puts("senha:\n");
    scanf("%s", senha_usuario);

    struct Login_usuario_model usecase_retorno = login_usuario_service(user, senha_usuario);

    if (usecase_retorno.erro == true)
    {
        puts(usecase_retorno.mensagem);
        system("sleep 02");
        login();
        return;
    }

    strcpy(usuario_logado, usecase_retorno.login_usuario.usuario);
    strcpy(senha_usuario_logado, usecase_retorno.login_usuario.senha);
    puts(usecase_retorno.mensagem);
    system("sleep 02");
    home();
    return;
}

void cadastro()
{
    char user[21];
    char senha_usuario[21];
    char confirmacao_senha[21];

    system("reset");
    printf(TEXTO_TITULO_CADASTRO);

    puts("Digite seu user:\n");
    scanf("%s", user);

    puts("Digite sua senha:\n");
    scanf("%s", senha_usuario);

    puts("Confirme sua senha:\n");
    scanf("%s", confirmacao_senha);

    // TODO definir todas as validações que ocorreram na senha
    // nao da p utilizar ; , & = nas varias de senha e usuario
    if (strlen(user) > 15 || strlen(senha_usuario) > 15)
    {
        puts(" usuario ou senha digitados possuem um numero maior de caracteres possiveis, (máximo 15 caracteres), digite novamente\n");
        login();
        return;
    }

    int valida_confirmacao_senha = strcmp(confirmacao_senha, senha_usuario);

    if (valida_confirmacao_senha != VERDADEIRO)
    {
        puts(TEXTO_ERRO_CONFIRMACAO_SENHA);
        system("sleep 02");
        cadastro();
        return;
    }

    struct Criar_usuario_model model = criar_usuario_service(user, senha_usuario);
   
    puts(model.mensagem);
    system("sleep 03");

    if (model.erro == true) {
        cadastro();
    } else {
        login();
    }
}

void perfil()
{
    int acao;
    system("reset");
    printf("usuario: %s\n", usuario_logado);
    printf("senha: %s\n", senha_usuario_logado);

    puts("Digite 1 para voltar para a home");
    scanf("%i", &acao);

    switch (acao)
    {
    case 1:
        home();
        break;

    default:
        puts(TEXTO_OPCAO_INVALIDA);
        menu();
        break;
    }
}

void home()
{
    int acao;
    system("reset");
    printf(TEXTO_TITULO_HOME);
    puts(TEXTO_OPCOES_HOME);
    scanf("%i", &acao);

    switch (acao)
    {
    case 1:
        perfil();
        break;

    case 2:
        buscar_usuarios_todos();
        break;

    case 3:
        menu();
        break;

    default:
        puts(TEXTO_OPCAO_INVALIDA);
        menu();
        break;
    }
}

void buscar_usuarios_todos()
{
    system("reset");

    struct Buscar_usuarios_model model = buscar_usuarios_service();

    puts("\n\nlista de usuarios: \n");
    for (int i = 0; i < model.quantidade_usuarios; i++)
    {
        printf("id: %s, usuario: %s, senha: %s \n",
               model.usuarios[i].id,
               model.usuarios[i].usuario,
               model.usuarios[i].senha);
    }

    int acao;
    puts("\n\nDigite 1 para voltar para a home");
    scanf("%i", &acao);

    switch (acao)
    {
    case 1:
        home();
        break;
    
    default:
        home();
        // puts(TEXTO_OPCAO_INVALIDA);
        // menu();
        break;
    }

}

int main()
{
    menu();
}