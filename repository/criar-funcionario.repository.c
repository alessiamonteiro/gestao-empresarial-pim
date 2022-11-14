#include "../headers.h"
#include "../constantes.h"

struct Criar_funcionario_model criar_funcionario_repository(struct Funcionario funcionario)
{
    struct Criar_funcionario_model model = {};

    char caminho_arquivo[150] = "";
    montar_caminho_arquivo(caminho_arquivo, "/database/funcionarios.txt");

    FILE *txt_funcionarios;
    txt_funcionarios = fopen(caminho_arquivo, "a");

    if (txt_funcionarios == NULL)
    {
        model.erro = true;
        model.nome_funcionario = "";
        model.mensagem = "[ERRO] criar_funcionario_repository";
        return model;
    }

    fprintf(txt_funcionarios, "%i,%s,%s,%s,%i,%.2f,%i,%i\n",
            funcionario.id,
            encrypt(funcionario.nome),
            encrypt(funcionario.cpf),
            encrypt(funcionario.rg),
            funcionario.cargo,
            funcionario.salario,
            funcionario.possui_ferias,
            funcionario.esta_de_ferias);

    fclose(txt_funcionarios);

    model.erro = false;
    model.nome_funcionario = funcionario.nome;
    model.mensagem = "Cadastro realizado com sucesso!\n";
    return model;
}