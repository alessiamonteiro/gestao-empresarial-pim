#include <stdio.h>
#include <string.h>

#include "../headers/buscar-usuarios.repository.h"
#include "../headers/login-usuario.usecase.h"

struct Login_usuario_usecase login_usuario_usecase(char user[21], char senha_usuario[21])
{
    struct Login_usuario login_usuario;
    struct Login_usuario_usecase usecase_retorno;
    struct Buscar_usuarios_repository repository_retorno = buscar_usuarios_repository();

    for (int i = 0; i <= repository_retorno.quantidade_usuarios - 1; i++)
    {
        int compara_nome = strcmp(repository_retorno.usuarios[i].usuario, user);
        int compara_senha = strcmp(repository_retorno.usuarios[i].senha, senha_usuario);

        if (compara_nome == 0 && compara_senha == 0)
        {
            strcpy(login_usuario.usuario, user);
            strcpy(login_usuario.senha, senha_usuario);
            strcpy(usecase_retorno.mensagem, "login realizado com sucesso\n");
            usecase_retorno.erro = 0;
            usecase_retorno.login_usuario = login_usuario;
            return usecase_retorno;
        }
    }

    strcpy(login_usuario.usuario, "");
    strcpy(login_usuario.senha, "");
    strcpy(usecase_retorno.mensagem, "usuario ou senha incorretos\n");
    usecase_retorno.erro = 1;
    usecase_retorno.login_usuario = login_usuario;
    return usecase_retorno;
}
