#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define VERDADEIRO 0

int acao;

typedef struct
{
    char nome[21];
    char senha[21];
} Usuario;

Usuario usuarios[50];

void menu();
void opcoes_menu();
void login();
void cadastro();
void preencher_valor_inicial_usuarios();
void home();       

void menu()
{
    printf("\nMENU \n selecione o número referente a ação que deseja!\n 1- Login \n 2- Criar Usúario \n");
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

    default:
        printf("opção invalida, por favor digite novamente:\n");
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

    for (int i = 0; i <= 50; i++)
    {
        int compara_nome = strcmp(usuarios[i].nome, user);
        int compara_senha = strcmp(usuarios[i].senha, senha_usuario);

        if (compara_nome == VERDADEIRO && compara_senha == VERDADEIRO)
        {
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
    printf("---------------- CADASTRO ---------------\n");
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

    for (int i = 0; i <= 50; i++)
    {
        int valida_usuario_existente = strcmp(usuarios[i].nome, user);

        int valida_usuario_disponivel = strcmp(usuarios[i].nome, "");

        if (valida_usuario_existente == VERDADEIRO)
        {
            printf("usuario ja existente, digite outro user\n");
            system("sleep 03");
            cadastro();
            break;
        }

        if (valida_usuario_disponivel == VERDADEIRO)
        {
            strcpy(usuarios[i].nome, user);
            strcpy(usuarios[i].senha, senha_usuario);
            printf("Cadastro realizado com sucesso!\n");
            system("sleep 02");
            login();
            break;
        }
    }
}

void home()
{
    system("reset");
    printf("------------------------ HOME -----------------------------");
}

void preencher_valor_inicial_usuarios() {
    for (int i = 0; i <= 50; i++)
    {
        strcpy(usuarios[i].nome, "");
        strcpy(usuarios[i].senha, "");
    }

    strcpy(usuarios[0].nome, "alessia");
    strcpy(usuarios[0].senha, "jaos");
}

int main()
{
    preencher_valor_inicial_usuarios();
    printf("------------------- Seja bem-vindo a nossa plataforma de gestão empresarial! :) --------------------\n");
    menu();
}