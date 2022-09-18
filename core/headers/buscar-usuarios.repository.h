#ifndef BUSCAR_USUARIOS_REPOSITORY_DOT_H /* This is an "include guard" */
#define BUSCAR_USUARIOS_REPOSITORY_DOT_H /* prevents the file from being included twice. */
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

struct Buscar_usuarios_repository buscar_usuarios_repository();

struct Buscar_usuarios_repository
{
    int quantidade_usuarios;
    struct Usuario *usuarios;
};

#endif /* BUSCAR_USUARIOS_REPOSITORY_DOT_H */