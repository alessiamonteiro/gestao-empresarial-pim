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

// entidades //
struct Funcionario
{
    int id;
    char nome[150];
    char cpf[13];
    char rg[13];
    int cargo;
    float salario;
    int possui_ferias;
    int esta_de_ferias;
};

struct Cliente
{
    int id;
    char nome[150];
    char cpf_cnpj[19];
    float valor_produto;
    char data_entrega[11];
};

struct Usuario
{
    char id[5];
    char usuario[22];
    char senha[22];
};

struct Cargo
{
    int id;
    char cargo[50];
};

// model //
struct Buscar_usuarios_model
{
    int erro;
    char *mensagem;
    int quantidade_usuarios;
    struct Usuario *usuarios;
};

struct Buscar_funcionarios_model
{
    int erro;
    char *mensagem;
    int quantidade_funcionarios;
    struct Funcionario *funcionarios;
};

struct Buscar_clientes_model
{
    int erro;
    char *mensagem;
    int quantidade_clientes;
    struct Cliente *clientes;
};

struct Buscar_cargos_model
{
    int erro;
    char *mensagem;
    int quantidade_cargos;
    struct Cargo cargos[50];
};

struct Criar_usuario_model
{
    int erro;
    char *mensagem;
    char *usuario;
};

struct Criar_funcionario_model
{
    int erro;
    char *mensagem;
    char *nome_funcionario;
};

struct Criar_cliente_model
{
    int erro;
    char *mensagem;
    char *nome_cliente;
};

struct Criar_relatorio_model
{
    int erro;
    char *mensagem;
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

//   controller   //
void login_usuario_controller(char[1024]);
void buscar_usuarios_controller(char[1024]);
void criar_cliente_controller(char buffer[1024]);
void criar_usuario_controller(char buffer[1024]);
void buscar_clientes_controller(char buffer[1024]);
void criar_funcionario_controller(char buffer[1024]);
void buscar_funcionarios_controller(char buffer[1024]);
void criar_relatorio_funcionarios_controller(char buffer[1024]);
void criar_relatorio_clientes_controller(char buffer[1024]);

//   usecase    //
struct Criar_relatorio_model criar_relatorio_funcionarios_usecase();
struct Criar_usuario_model criar_usuario_usecase(char[22], char[22]);
struct Criar_cliente_model criar_cliente_usecase(struct Cliente cliente);
struct Criar_funcionario_model criar_funcionario_usecase(struct Funcionario);

struct Buscar_usuarios_model buscar_usuarios_usecase();
struct Buscar_clientes_model buscar_clientes_usecase();
struct Buscar_funcionarios_model buscar_funcionarios_usecase();
struct Criar_relatorio_model criar_relatorio_clientes_usecase();

struct Login_usuario_model login_usuario_usecase(char[22], char[22]);

// repository //
struct Buscar_cargos_model buscar_cargos_repository();
struct Buscar_clientes_model buscar_clientes_repository();
struct Buscar_usuarios_model buscar_usuarios_repository();
struct Buscar_funcionarios_model buscar_funcionarios_repository();

struct Criar_cliente_model criar_cliente_repository(struct Cliente cliente);
struct Criar_usuario_model criar_usuario_repository(char[22], char[22], int);
struct Criar_funcionario_model criar_funcionario_repository(struct Funcionario);
struct Criar_relatorio_model criar_relatorio_funcionarios_repository(struct Buscar_funcionarios_model buscar_funcionarios_model, struct Buscar_cargos_model buscar_cargos_model);
struct Criar_relatorio_model criar_relatorio_clientes_repository(struct Buscar_clientes_model model);
//   service    //
struct Buscar_clientes_model buscar_clientes_service();
struct Buscar_usuarios_model buscar_usuarios_service();
struct Buscar_funcionarios_model buscar_funcionarios_service();

struct Criar_usuario_model criar_usuario_service(char[22], char[22]);
struct Criar_cliente_model criar_cliente_service(struct Cliente cliente);
struct Criar_relatorio_model criar_relatorio_funcionarios_service();
struct Criar_relatorio_model criar_relatorio_clientes_service();
struct Criar_funcionario_model criar_funcionario_service(struct Funcionario funcionario);

struct Login_usuario_model login_usuario_service(char[22], char[22]);

void router(char buffer[1024]);

// page //
void login_page();
void perfil_page();
void menu_page(int erro);
void home_page(int erro);
void consultas_page(int erro);
void relatorios_page(int erro);
void cadastro_page();
void cadastro_cliente_page();
void cadastro_funcionario_page();
void buscar_usuarios_page();
void buscar_clientes_page();
void buscar_funcionarios_page();
void cadastros_page(int erro);

char usuario_logado[22];
char senha_usuario_logado[22];

//utils
void montar_caminho_arquivo(char caminho_arquivo[150], char sufixo[75]);

void delay(int segundos);

char *encrypt(char string[]);
char *decrypt(char string[]);

void voltar_home_page();
void voltar_consultas_page();
void formatar_cpf(char cpf[11], char cpf_formatado[16]);
void formatar_cnpj(char cnpj[14], char cnpj_formatado[19]);
void formatar_cpf_cnj(char cpf_cnpj[19], char cpf_cnpj_formatado[19]);
const double calcular_soma_valor_produtos(struct Buscar_clientes_model model);
#endif /* HEADERS_DOT_H */