#include "../headers.h"
#include "../constantes.h"

struct Criar_usuario_model criar_usuario_repository(char nome[22], char senha[22], int id)
{
    // montar caminho do arquivo
    char caminho_arquivo[150] = "";
    montar_caminho_arquivo(caminho_arquivo, "/database/usuarios.txt");

    struct Criar_usuario_model model = {0, "", ""};

    FILE *txt_usuarios;
    txt_usuarios = fopen(caminho_arquivo, "a");

    if (txt_usuarios == NULL)
    {
        model.erro = 1;
        model.usuario = "";
        model.mensagem = "[ERRO] criar_usuario_repository";
        return model;
    }

    fprintf(txt_usuarios, "%i,%s,%s\n", id, nome, senha);

    fclose(txt_usuarios);

    model.erro = 0;
    model.usuario = nome;
    model.mensagem = "Cadastro realizado com sucesso!\n";
    return model;
}
