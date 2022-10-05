#ifndef HEADERS_DOT_H /* This is an "include guard" */
#define HEADERS_DOT_H /* prevents the file from being included twice. */
                                         /* Including a header file twice causes all kinds */
                                         /* of interesting problems.*/

/**
 * This is a function declaration.
 * It tells the compiler that the function exists somewhere.
 */

struct Usuario
{
    char id[5];
    char usuario[21];
    char senha[21];
};

struct Buscar_usuarios_model
{   
    int erro;
    char * mensagem;
    int quantidade_usuarios;
    struct Usuario * usuarios;
};

struct Criar_usuario_model 
{
    int erro;
    char * mensagem;
    char * usuario;
};

struct Buscar_usuarios_model buscar_usuarios_repository();

struct Criar_usuario_model criar_usuario_repository(char[21], char[21], int);

struct Criar_usuario_model criar_usuario_usecase(char[21], char[21]);

void criar_usuario_controller(char buffer[1024]);

struct Criar_usuario_model criar_usuario_service(char[21], char[21]);

struct Login_usuario
{
    char usuario[21];
    char senha[21];
};

struct Login_usuario_model login_usuario_usecase(char[21], char[21]);

struct Login_usuario_model
{
    int erro;
    char mensagem[151];
    struct Login_usuario login_usuario;
};

void socket_client(char requisicao[], char responsta[]);

void buscar_usuarios_controller(char[1024]);

void login_usuario_controller(char[1024]);

struct Buscar_usuarios_model buscar_usuarios_service();

struct Buscar_usuarios_model buscar_usuarios_usecase();

struct Login_usuario_model login_usuario_service(char[21], char[21]);

#endif /* HEADERS_DOT_H */