#include "../headers.h"

struct Criar_funcionario_model criar_funcionario_usecase(struct Funcionario funcionario)
{
    struct Criar_funcionario_model criar_funcionario_model = {};
    struct Buscar_funcionarios_model buscar_funcionarios_model = buscar_funcionarios_usecase();
    int id;

    if (buscar_funcionarios_model.erro == true)
    {
        criar_funcionario_model.erro = true;
        criar_funcionario_model.mensagem = buscar_funcionarios_model.mensagem;
        criar_funcionario_model.nome_funcionario = "";
        return criar_funcionario_model;
    }

    if (buscar_funcionarios_model.quantidade_funcionarios == 0)
    {
        id = 1;
    }
    else
    {
        id = buscar_funcionarios_model.funcionarios[buscar_funcionarios_model.quantidade_funcionarios - 1].id + 1;
    }

    for (int i = 0; i < buscar_funcionarios_model.quantidade_funcionarios; i++)
    {
        int valida_nome_existente = strcmp(buscar_funcionarios_model.funcionarios[i].nome, funcionario.nome);
        int valida_cpf_existente = strcmp(buscar_funcionarios_model.funcionarios[i].cpf, funcionario.cpf);
        int valida_rg_existente = strcmp(buscar_funcionarios_model.funcionarios[i].nome, funcionario.rg);

        if (
            valida_nome_existente == 0 ||
            valida_cpf_existente == 0 ||
            valida_rg_existente == 0)
        {
            criar_funcionario_model.erro = true;
            criar_funcionario_model.nome_funcionario = "";
            criar_funcionario_model.mensagem = "Nome, CPF, ou RG já foram cadastrados anteriormente";
            return criar_funcionario_model;
        }
    }

    funcionario.id = id;
    return criar_funcionario_repository(funcionario);
}