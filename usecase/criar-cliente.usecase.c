#include "../headers.h"

struct Criar_cliente_model criar_cliente_usecase(struct Cliente cliente)
{
    struct Criar_cliente_model criar_cliente_model = {};
    struct Buscar_clientes_model buscar_clientes_model = buscar_clientes_repository();
    int id;

    if (buscar_clientes_model.erro == true)
    {
        criar_cliente_model.erro = true;
        criar_cliente_model.mensagem = buscar_clientes_model.mensagem;
        criar_cliente_model.nome_cliente = "";
        return criar_cliente_model;
    }

    if (buscar_clientes_model.quantidade_clientes == 0)
    {
        id = 1;
    }
    else
    {
        id = buscar_clientes_model.clientes[buscar_clientes_model.quantidade_clientes - 1].id + 1;
    }

    for (int i = 0; i < buscar_clientes_model.quantidade_clientes; i++)
    {
        int valida_nome_existente = strcmp(buscar_clientes_model.clientes[i].nome, cliente.nome);
        int valida_cpf_cnpj_existente = strcmp(buscar_clientes_model.clientes[i].cpf_cnpj, cliente.cpf_cnpj);

        if (
            valida_nome_existente == 0 ||
            valida_cpf_cnpj_existente == 0)
        {
            criar_cliente_model.erro = true;
            criar_cliente_model.nome_cliente = "";
            criar_cliente_model.mensagem = "Nome, CPF ou CNPJ já foram cadastrados anteriormente";
            return criar_cliente_model;
        }
    }

    cliente.id = id;
    return criar_cliente_repository(cliente);
}