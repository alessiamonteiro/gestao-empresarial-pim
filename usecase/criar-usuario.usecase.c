#include "../headers.h"
#include "../constantes.h"

int calcular_proximo_id(struct Buscar_usuarios_model input)
{
    return input.quantidade_usuarios == 0
               ? 1
               : atoi(input.usuarios[input.quantidade_usuarios - 1].id) + 1;
}

struct Criar_usuario_model criar_usuario_usecase(char usuario[22], char senha[22])
{
    struct Criar_usuario_model output = {};

    if (usuario_senha_invalido(usuario) || usuario_senha_invalido(senha))
    {
        strcpy(output.usuario, "");
        strcpy(output.mensagem, "usuario ou senha incorretos\n");
        output.erro = 1;
        return output;
    }

    struct Buscar_usuarios_model buscar_usuarios_model = buscar_usuarios_repository();

    if (buscar_usuarios_model.erro == true)
    {
        output.erro = true;
        output.mensagem = buscar_usuarios_model.mensagem;
        output.usuario = "";
        return output;
    }

    for (int i = 0; i < buscar_usuarios_model.quantidade_usuarios; i++)
    {
        int valida_usuario_existente = strcmp(buscar_usuarios_model.usuarios[i].usuario, usuario);

        if (valida_usuario_existente == 0)
        {
            output.erro = true;
            output.usuario = "";
            output.mensagem = TEXTO_ERRO_CADASTRO_USUARIO_EXISTENTE;
            return output;
        }
    }

    int id = calcular_proximo_id(buscar_usuarios_model);

    return criar_usuario_repository(encrypt(usuario), encrypt(senha), id);
}