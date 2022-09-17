#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "buscar-usuarios.h"
#include "criar-usuario.h"

const int VERDADEIRO = 0;
const int ERRO = -1;

#define TEXTO_TITULO_HOME "---------------- HOME ----------------\n"
#define TEXTO_TITULO_CADASTRO "-------------- CADASTRO --------------\n"
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
    system("reset");
    printf(TEXTO_OPCOES_MENU);
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
        printf(TEXTO_OPCAO_INVALIDA);
        menu();
        break;
    }
}

void login()
{
    char user[21];
    char senha_usuario[21];

    system("reset");
    printf("\n ---------------- LOGIN ------------------");
    printf("\nusuario: \n");
    scanf("%s", user);
    printf("senha:\n");
    scanf("%s", senha_usuario);

    struct Buscar_usuarios_retorno retorno = buscar_usuarios();

    for (int i = 0; i <= retorno.quantidade_usuarios - 1; i++)
    {
        int compara_nome = strcmp(retorno.usuarios[i].usuario, user);
        int compara_senha = strcmp(retorno.usuarios[i].senha, senha_usuario);

        if (compara_nome == VERDADEIRO && compara_senha == VERDADEIRO)
        {
            strcpy(usuario_logado, user);
            strcpy(senha_usuario_logado, user);
            printf("login realizado com sucesso\n");
            system("sleep 02");
            menu();
            return;
        }
    }

    printf("usuario ou senha incorretos\n");
    system("sleep 02");
    login();
}

void cadastro()
{
    char user[21];
    char senha_usuario[21];
    char confirmacao_senha[21];

    system("reset");
    printf(TEXTO_TITULO_CADASTRO);
    printf("Digite seu user:\n");
    scanf("%s", user);
    printf("digite sua senha:\n");
    scanf("%s", senha_usuario);
    printf("digite sua senha:\n");
    scanf("%s", confirmacao_senha);

    if (strlen(user) > 15 || strlen(senha_usuario) > 15)
    {
        printf(" usuario ou senha digitados possuem um numero maior de caracteres possiveis, (máximo 15 caracteres), digite novamente\n");
        login();
        return;
    }

    int valida_confirmacao_senha = strcmp(confirmacao_senha, senha_usuario);

    if (valida_confirmacao_senha != VERDADEIRO)
    {
        printf("senhas digitadas incorretamente, digite novamente\n");
        system("sleep 02");
        cadastro();
        return;
    }

    struct Buscar_usuarios_retorno retorno = buscar_usuarios();

    for (int i = 0; i <= retorno.quantidade_usuarios - 1; i++)
    {
        int valida_usuario_existente = strcmp(retorno.usuarios[i].usuario, user);

        if (valida_usuario_existente == VERDADEIRO)
        {
            printf("usuario ja existe, digite outro usuario\n");
            system("sleep 03");
            cadastro();
            break;
        }

        criar_usuario(user, senha_usuario, retorno.quantidade_usuarios);
        login();
        break;
    }
}

void home()
{
    system("reset");
    printf(TEXTO_TITULO_HOME);
}

void buscar_usuarios_todos()
{
    system("reset");
    printf("lista de usuarios: \n\n");
    struct Buscar_usuarios_retorno retorno = buscar_usuarios();

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
    printf(TEXTO_BEM_VINDO);
    menu();
}