#ifndef HEADERS_DOT_H /* This is an "include guard" */
#define HEADERS_DOT_H /* prevents the file from being included twice. */
                                         /* Including a header file twice causes all kinds */
                                         /* of interesting problems.*/

/**
 * This is a function declaration.
 * It tells the compiler that the function exists somewhere.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include <monetary.h>

struct Funcionario
{
    int id;
    char nome[150];
    char cpf[13];
    char rg[13];
    int cargo;
    float salario;
    int possui_ferias;
    bool esta_de_ferias;
};

struct Usuario
{
    char id[5];
    char usuario[22];
    char senha[22];
};

struct Cargo{
    int id;
    char cargo[50];
};

struct Buscar_usuarios_model
{   
    int erro;
    char * mensagem;
    int quantidade_usuarios;
    struct Usuario * usuarios;
};

struct Buscar_funcionarios_model
{
    int erro;
    char * mensagem;
    int quantidade_funcionarios;
    struct Funcionario * funcionarios;
};

struct Buscar_cargos_model
{   
    int erro;
    char * mensagem;
    int quantidade_cargos;
    struct Cargo cargos[50];
};

struct Criar_usuario_model 
{
    int erro;
    char * mensagem;
    char * usuario;
};

struct Criar_funcionario_model 
{
    int erro;
    char * mensagem;
    char * nome_funcionario;
};

struct Criar_relatorio_model
{
    int erro;
    char * mensagem;
};


struct Login_usuario
{
    char usuario[22];
    char senha[22];
};


struct Login_usuario_model
{
    int erro;
    char mensagem[151];
    struct Login_usuario login_usuario;
};

void socket_client(char requisicao[], char responsta[]);

//   controllers    //
void buscar_usuarios_controller(char[1024]);

void login_usuario_controller(char[1024]);

void buscar_funcionarios_controller(char buffer[1024]);

void criar_usuario_controller(char buffer[1024]);

void criar_funcionario_controller(char buffer[1024]);

void criar_relatorio_funcionarios_controller(char buffer[1024]);

//   useCases    //
struct Buscar_usuarios_model buscar_usuarios_usecase();

struct Buscar_funcionarios_model buscar_funcionarios_usecase();

struct Criar_usuario_model criar_usuario_usecase(char[22], char[22]);

struct Criar_funcionario_model criar_funcionario_usecase(struct Funcionario);

struct Login_usuario_model login_usuario_usecase(char[22], char[22]);

struct Criar_relatorio_model criar_relatorio_funcionarios_usecase();

// repositories //
struct Criar_funcionario_model criar_funcionario_repository(struct Funcionario);

struct Buscar_usuarios_model buscar_usuarios_repository();

struct Buscar_cargos_model buscar_cargos_repository();

struct Buscar_funcionarios_model buscar_funcionarios_repository();

struct Criar_usuario_model criar_usuario_repository(char[22], char[22], int);

struct Criar_relatorio_model criar_relatorio_funcionarios_repository(struct Buscar_funcionarios_model buscar_funcionarios_model, struct Buscar_cargos_model buscar_cargos_model);

//   services    //
struct Buscar_funcionarios_model buscar_funcionarios_service();

struct Buscar_usuarios_model buscar_usuarios_service();

struct Criar_funcionario_model criar_funcionario_service(struct Funcionario funcionario);

struct Criar_usuario_model criar_usuario_service(char[22], char[22]);

struct Login_usuario_model login_usuario_service(char[22], char[22]);

struct Criar_relatorio_model criar_relatorio_funcionarios_service();

void router(char buffer[1024]);

// pages //
void menu_page(bool erro);
void login_page();
void cadastro_page();
void home_page(bool erro);
void buscar_usuarios_page();
void buscar_funcionarios_page();
void perfil_page();
void cadastro_funcionario_page();
void relatorios_page(bool erro);

char usuario_logado[22];
char senha_usuario_logado[22];

void montar_caminho_arquivo(char caminho_arquivo[150], char sufixo[75]);

void delay(int segundos);

#endif /* HEADERS_DOT_H */