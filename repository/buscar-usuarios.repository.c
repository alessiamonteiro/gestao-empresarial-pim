#include "../headers.h"
#include "../constantes.h"

const int COLUNA_ID = 1;
const int COLUNA_USUARIO = 2;
const int COLUNA_SENHA = 3;

struct Usuario usuarios[] = {};

struct Buscar_usuarios_model repository_retorno = {
    0,
    "",
    0,
};

struct Buscar_usuarios_model buscar_usuarios_repository()
{
    char ch;
    char usuario[22] = "";
    char senha[22] = "";
    char id[5] = "";

    int coluna = 1;
    int contador_registros = 0;

    char caminho_arquivo[150] = "";
    montar_caminho_arquivo(caminho_arquivo, "/database/usuarios.txt");

    FILE *txt_usuarios;
    txt_usuarios = fopen(caminho_arquivo, "r");

    if (txt_usuarios == NULL)
    {
        repository_retorno.erro = true;
        repository_retorno.mensagem = "[ERRO] buscar_usuarios_repository";
        repository_retorno.quantidade_usuarios = 0;
        repository_retorno.usuarios = usuarios;
        return repository_retorno;
    }

    while ((ch = fgetc(txt_usuarios)) != EOF)
    {
        if (ch == '\n')
        {
            if (coluna == COLUNA_SENHA)
            {
                strcpy(usuarios[contador_registros].senha, decrypt(senha));
            }

            contador_registros += 1;
            coluna = COLUNA_ID;
            strcpy(id, "");
            strcpy(usuario, "");
            strcpy(senha, "");
            continue;
        }

        if (ch == ',' && coluna == COLUNA_ID)
        {
            coluna += 1;
            strcpy(usuarios[contador_registros].id, id);
            continue;
        }

        if (ch == ',' && coluna == COLUNA_USUARIO)
        {
            coluna += 1;
            strcpy(usuarios[contador_registros].usuario, decrypt(usuario));
            continue;
        }

        if (coluna == COLUNA_ID)
        {
            strncat(id, &ch, 1);
        }

        if (coluna == COLUNA_USUARIO)
        {
            strncat(usuario, &ch, 1);
        }

        if (coluna == COLUNA_SENHA)
        {
            strncat(senha, &ch, 1);
        }
    }

    repository_retorno.erro = 0;
    repository_retorno.mensagem = "[OK] buscar_usuarios_repository";
    repository_retorno.quantidade_usuarios = contador_registros;
    repository_retorno.usuarios = usuarios;

    return repository_retorno;
}