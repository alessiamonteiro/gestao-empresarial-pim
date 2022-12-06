#include "../headers.h"

struct Login_usuario_model login_usuario_usecase(char usuario[22], char senha[22])
{
    struct Login_usuario login_usuario;
    struct Login_usuario_model output;
    struct Buscar_usuarios_model buscar_usuarios = buscar_usuarios_repository();

    for (int i = 0; i < buscar_usuarios.quantidade_usuarios; i++)
    {
        int compara_nome = strcmp(buscar_usuarios.usuarios[i].usuario, usuario);
        int compara_senha = strcmp(buscar_usuarios.usuarios[i].senha, senha);

        if (compara_nome == 0 && compara_senha == 0)
        {
            strcpy(login_usuario.usuario, usuario);
            strcpy(login_usuario.senha, senha);
            strcpy(output.mensagem, "login realizado com sucesso\n");
            output.erro = 0;
            output.login_usuario = login_usuario;
            return output;
        }
    }

    strcpy(login_usuario.usuario, "");
    strcpy(login_usuario.senha, "");
    strcpy(output.mensagem, "usuario ou senha incorretos\n");
    output.erro = 1;
    output.login_usuario = login_usuario;
    return output;
}
