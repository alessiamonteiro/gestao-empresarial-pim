#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "buscar-usuarios.h"

#define VERDADEIRO 0

int acao;

struct Usuario
{
    char nome[21];
    char senha[21];
};

struct Usuario usuarios[50];

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
    printf("\nMENU \n selecione o número referente a ação que deseja!\n 1- Login \n 2- Criar Usuario \n 3- Buscar Usuarios");
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
    
    //TODO deixar de percorrer o array e passar a percorrer o usuarios.txt
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
        
        //TODO mover logica de inserir dados no usuarios.txt para arquivo separado
        if (valida_usuario_disponivel == VERDADEIRO)
        {
            strcpy(usuarios[i].nome, user);
            strcpy(usuarios[i].senha, senha_usuario);

            FILE *txt_usuarios; 
            txt_usuarios = fopen("usuarios.txt", "a");

            int id_ultimo_usuario = buscar_usuarios();
            int id_proximo_usuario = 0;

            if (id_ultimo_usuario != -1) {
                id_proximo_usuario = id_ultimo_usuario + 1;
            }

            if (txt_usuarios == NULL)
            {
                printf("Erro na abertura do arquivo!");
                return;
            }

            fprintf(txt_usuarios, "%i,%s,%s\n", id_proximo_usuario, usuarios[i].nome, usuarios[i].senha);
            fclose(txt_usuarios);

            printf("Dados gravados com sucesso!");

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

void buscar_usuarios_todos() {
    system("reset");
    printf("lista de usuarios: \n");
    int err = buscar_usuarios();

    if (err == -1) {
        buscar_usuarios();
    }
}

int main(void)
{
    printf("------------------- Seja bem-vindo a nossa plataforma de gestão empresarial! :) --------------------\n");
    menu();
}