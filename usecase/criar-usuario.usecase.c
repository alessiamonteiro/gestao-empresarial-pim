#include "../headers.h"
#include "../constantes.h"

struct Criar_usuario_model criar_usuario_usecase(char user[22], char senha[22])
{
    struct Criar_usuario_model criar_usuario_model = {0, "", ""};
    struct Buscar_usuarios_model buscar_usuarios_model = buscar_usuarios_repository();
    int id;

    if (buscar_usuarios_model.erro == true)
    {
        criar_usuario_model.erro = true;
        criar_usuario_model.mensagem = buscar_usuarios_model.mensagem;
        criar_usuario_model.usuario = "";
        return criar_usuario_model;
    }

    if (buscar_usuarios_model.quantidade_usuarios == 0)
    {
        id = 1;
    }
    else
    {
        id = atoi(buscar_usuarios_model.usuarios[buscar_usuarios_model.quantidade_usuarios - 1].id) + 1;
    }

    for (int i = 0; i < buscar_usuarios_model.quantidade_usuarios; i++)
    {
        int valida_usuario_existente = strcmp(buscar_usuarios_model.usuarios[i].usuario, user);

        if (valida_usuario_existente == 0)
        {
            criar_usuario_model.erro = true;
            criar_usuario_model.usuario = "";
            criar_usuario_model.mensagem = TEXTO_ERRO_CADASTRO_USUARIO_EXISTENTE;
            return criar_usuario_model;
        }
    }

    return criar_usuario_repository(encrypt(user), encrypt(senha), id);
}