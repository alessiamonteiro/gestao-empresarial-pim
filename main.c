#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "./core/headers/buscar-usuarios.repository.h"
#include "./core/headers/criar-usuario.repository.h"
#include "./core/headers/login-usuario.usecase.h"

const int VERDADEIRO = 0;
const int ERRO = -1;

#define TEXTO_TITULO_HOME "---------------- HOME ----------------\n"
#define TEXTO_TITULO_CADASTRO "-------------- CADASTRO --------------\n"
#define TEXTO_TITULO_LOGIN "\n ---------------- LOGIN ----------------"
#define TEXTO_BEM_VINDO "------------------- Seja bem-vindo a nossa plataforma de gestão empresarial! :) --------------------\n"
#define TEXTO_OPCAO_INVALIDA "opção invalida, por favor digite novamente:\n"
#define TEXTO_OPCOES_MENU "\nMENU \n selecione o número referente a ação que deseja!\n 1- Login \n 2- Criar Usuario \n 3- Buscar Usuarios\n"

int acao;

void menu();
void opcoes_menu();
void login();
void cadastro();
void preencher_valor_inicial_usuarios();
void home();
void buscar_usuarios_todos();

char usuario_logado[21];
char senha_usuario_logado[21];

void menu()
{
    puts(TEXTO_OPCOES_MENU);
    scanf("%i", &acao);
    opcoes_menu(acao);
}

void opcoes_menu(int acao)
{
    switch (acao)
    {
    case 1:
        login();
        break;

    case 2:
        cadastro();
        break;

    case 3:
        buscar_usuarios_todos();
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

    struct Login_usuario_usecase usecase_retorno = login_usuario_usecase(user, senha_usuario);

    if (usecase_retorno.erro == true) {
        puts(usecase_retorno.mensagem);
        system("sleep 02");
        login();
        return;
    }

    strcpy(usuario_logado, usecase_retorno.login_usuario.usuario);
    strcpy(senha_usuario_logado, usecase_retorno.login_usuario.senha);
    puts(usecase_retorno.mensagem);
    system("sleep 02");
    menu();
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
    puts("digite sua senha:\n");
    scanf("%s", senha_usuario);
    puts("digite sua senha:\n");
    scanf("%s", confirmacao_senha);

    if (strlen(user) > 15 || strlen(senha_usuario) > 15)
    {
        puts(" usuario ou senha digitados possuem um numero maior de caracteres possiveis, (máximo 15 caracteres), digite novamente\n");
        login();
        return;
    }

    int valida_confirmacao_senha = strcmp(confirmacao_senha, senha_usuario);

    if (valida_confirmacao_senha != VERDADEIRO)
    {
        puts("senhas digitadas incorretamente, digite novamente\n");
        system("sleep 02");
        cadastro();
        return;
    }

    // TODO mover para usecase de criar-usuario.usecase.c
    struct Buscar_usuarios_repository retorno = buscar_usuarios_repository();

    for (int i = 0; i <= retorno.quantidade_usuarios - 1; i++)
    {
        int valida_usuario_existente = strcmp(retorno.usuarios[i].usuario, user);

        if (valida_usuario_existente == VERDADEIRO)
        {
            puts("usuario ja existe, digite outro usuario\n");
            system("sleep 03");
            cadastro();
            break;
        }

        criar_usuario_repository(user, senha_usuario, retorno.quantidade_usuarios);
        login();
        break;
    }
    // criar-usuario.usecase.c
}

void home()
{
    system("reset");
    printf(TEXTO_TITULO_HOME);
}

void buscar_usuarios_todos()
{
    system("reset");
    puts("lista de usuarios: \n\n");
    struct Buscar_usuarios_repository retorno = buscar_usuarios_repository();

    for (int i = 0; i < retorno.quantidade_usuarios - 1; i++)
    {
        printf("id: %s, usuario: %s, senha: %s \n",
               retorno.usuarios[i].id,
               retorno.usuarios[i].usuario,
               retorno.usuarios[i].senha);
    }
}

int main()
{
    puts(TEXTO_BEM_VINDO);
    menu();
}