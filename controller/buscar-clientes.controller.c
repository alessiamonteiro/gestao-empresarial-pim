#include "../headers.h"

void buscar_clientes_controller(char buffer[1024])
{
    void mapear_buscar_clientes_response(char buffer[1024], struct Buscar_clientes_model model);
    struct Buscar_clientes_model model = buscar_clientes_usecase();
    mapear_buscar_clientes_response(buffer, model);
}

void mapear_buscar_clientes_response(char buffer[1024], struct Buscar_clientes_model model) {
    char erro_repository[2];
    char quantidade_clientes[10];

    sprintf(erro_repository, "%d", model.erro);
    sprintf(quantidade_clientes, "%d", model.quantidade_clientes);

    strcat(buffer, erro_repository);
    strcat(buffer, ";");

    strcat(buffer, model.mensagem);
    strcat(buffer, ";");

    if (model.erro == true && model.quantidade_clientes == 0)
    {
        strcat(buffer, "\n");
        return;
    }

    strcat(buffer, quantidade_clientes);
    strcat(buffer, ";");

    for (int i = 0; i < model.quantidade_clientes; i++)
    {
        char id[10] = "";
        char nome[150] = "";
        char cpf_cnpj[19] = "";
        char valor_produto[15] = "";
        char data_entrega[11] = "";

        sprintf(id, "%d", model.clientes[i].id);
        strcat(buffer, id);
        strcat(buffer, ",");

        strcat(buffer, model.clientes[i].nome);
        strcat(buffer, ",");

        strcat(buffer, model.clientes[i].cpf_cnpj);
        strcat(buffer, ",");

        sprintf(valor_produto, "%.2f", model.clientes[i].valor_produto);
        strcat(buffer, valor_produto);
        strcat(buffer, ",");

        strcat(buffer,  model.clientes[i].data_entrega);
        strcat(buffer, ";");
    }

    strcat(buffer, "\n");
}