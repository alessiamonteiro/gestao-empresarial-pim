#include "../headers.h"

bool usuario_senha_invalido(char *usuario_senha)
{
    return possui_caracteres_invalidos(usuario_senha) || strlen(usuario_senha) > 20 || strlen(usuario_senha) < 3;
}