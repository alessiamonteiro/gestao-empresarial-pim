#ifndef LOGIN_USUARIO_USECASE_DOT_H /* This is an "include guard" */
#define LOGIN_USUARIO_USECASE_DOT_H /* prevents the file from being included twice. */
                                    /* Including a header file twice causes all kinds */
                                    /* of interesting problems.*/

/**
 * This is a function declaration.
 * It tells the compiler that the function exists somewhere.
 */

struct Login_usuario
{
    char usuario[21];
    char senha[21];
};

struct Login_usuario_usecase login_usuario_usecase(char[21], char[21]);

struct Login_usuario_usecase
{
    int erro;
    char mensagem[151];
    struct Login_usuario login_usuario;
};

#endif /* LOGIN_USUARIO_USECASE_DOT_H */