#include "../headers.h"

void criar_cliente_controller(char buffer[1024])
{
    void mapear_criar_cliente_response(char buffer[1024], struct Criar_cliente_model model);

    int coluna = 1;
    bool deve_adicionar = false;

    char nome[150] = "";
    char cpf_cnpj[19] = "";
    char valor_produto[10] = "";
    char data_entrega[11] = "";

    struct Cliente cliente = {};

    // entrypoint log
    puts("ENTRYPOINT criar_cliente_controller");
    puts(buffer);

    // obter parametros passados na mensagem
    for (int i = 0; i < strlen(buffer); i++)
    {
        if (buffer[i] == '&')
        {
            deve_adicionar = false;
            coluna += 1;
        }

        if (buffer[i] == '=')
        {
            deve_adicionar = true;
            continue;
        }

        if (deve_adicionar == true)
        {
            switch (coluna)
            {
            case 1:
                strncat(nome, &buffer[i], 1);
                break;

            case 2:
                strncat(cpf_cnpj, &buffer[i], 1);
                break;

            case 3:
                strncat(valor_produto, &buffer[i], 1);
                break;

            case 4:
                strncat(data_entrega, &buffer[i], 1);
                break;

            default:
                break;
            }
        }
    }

    // montar struct cliente
    strcpy(cliente.nome, nome);
    strcpy(cliente.cpf_cnpj, cpf_cnpj);
    cliente.valor_produto = atof(valor_produto);
    strcpy(cliente.data_entrega, data_entrega);
    // montar struct cliente

    bzero(buffer, 1024);

    struct Criar_cliente_model model = criar_cliente_usecase(cliente);
    mapear_criar_cliente_response(buffer, model);
}

void mapear_criar_cliente_response(char buffer[1024], struct Criar_cliente_model model)
{
    char erro[2];

    sprintf(erro, "%d", model.erro);
    strcat(buffer, erro);
    strcat(buffer, ";");

    strcat(buffer, model.mensagem);
    strcat(buffer, ";");

    strcat(buffer, model.nome_cliente);
    strcat(buffer, ";");
}