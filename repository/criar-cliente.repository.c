#include "../headers.h"
#include "../constantes.h"

struct Criar_cliente_model criar_cliente_repository(struct Cliente cliente)
{
    struct Criar_cliente_model model = {};

    char caminho_arquivo[150] = "";
    montar_caminho_arquivo(caminho_arquivo, "/database/clientes.txt");

    FILE *txt_clientes;
    txt_clientes = fopen(caminho_arquivo, "a");

    if (txt_clientes == NULL)
    {
        model.erro = true;
        model.nome_cliente = "";
        model.mensagem = "[ERRO] criar_cliente_repository";
        return model;
    }

    fprintf(txt_clientes, "%i,%s,%s,%.2f,%s\n",
            cliente.id,
            encrypt(cliente.nome),
            encrypt(cliente.cpf_cnpj),
            cliente.valor_produto,
            cliente.data_entrega);
    
    fclose(txt_clientes);

    model.erro = false;
    model.nome_cliente = cliente.nome;
    model.mensagem = "Cadastro realizado com sucesso!\n";
    return model;
}