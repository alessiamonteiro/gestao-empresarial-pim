#include "../headers.h"

struct Buscar_clientes_model buscar_clientes_service()
{
    struct Buscar_clientes_model mapear_buscar_clientes_service(char response[1024]);
    char response[1024] = {};
    socket_client("GET/clientes", response);
    return mapear_buscar_clientes_service(response);
}

struct Buscar_clientes_model mapear_buscar_clientes_service(char response[1024])
{
    const int COLUNA_ID = 1;
    const int COLUNA_ERRO = 1;
    const int COLUNA_MENSAGEM = 2;
    const int COLUNA_QUANTIDADE_REGISTROS = 3;
    const int COLUNA_CLIENTE = 4;

    struct Cliente clientes[500] = {};
    struct Buscar_clientes_model model = {};

    int coluna = COLUNA_ERRO;
    int coluna_cliente = COLUNA_ID;
    int contador_registros = 0;

    char mensagem[200] = "";

    char id[10] = "";
    char nome[150] = "";
    char cpf_cnpj[15] = "";
    char valor_produto[15] = "";
    char data_entrega[11] = "";
    char quantidade_clientes_char[10] = "";

    model.mensagem = "";
    model.erro = atoi(&response[0]);

    for (int i = 0; i < strlen(response); i++)
    {
        if (response[i] == '\n')
            continue;

        if (response[i] == ';' && coluna < COLUNA_CLIENTE)
        {
            switch (coluna)
            {
            case 2:
                model.mensagem = mensagem;
                break;

            case 3:
                model.quantidade_clientes = atoi(quantidade_clientes_char);
                break;

            default:
                break;
            }

            coluna += 1;
            continue;
        }

        if (response[i] == ';' && coluna_cliente == 5)
        {
            strcpy(clientes[contador_registros].data_entrega, data_entrega);
            coluna_cliente = COLUNA_ID;
            continue;
        }

        if (coluna == COLUNA_MENSAGEM)
        {
            strncat(mensagem, &response[i], 1);
        }

        if (coluna == COLUNA_QUANTIDADE_REGISTROS)
        {
            strncat(quantidade_clientes_char, &response[i], 1);
        }

        if (coluna == COLUNA_CLIENTE)
        {
            if (response[i] == ';')
            {
                contador_registros += 1;
                strcpy(id, "");
                strcpy(nome, "");
                strcpy(cpf_cnpj, "");
                strcpy(valor_produto, "");
                strcpy(data_entrega, "");
                continue;
            }

            if (response[i] == ',')
            {
                switch (coluna_cliente)
                {
                case 1:
                    clientes[contador_registros].id = atoi(id);
                    break;

                case 2:
                    strcpy(clientes[contador_registros].nome, nome);
                    break;

                case 3:
                    strcpy(clientes[contador_registros].cpf_cnpj, cpf_cnpj);
                    break;

                case 4:
                    clientes[contador_registros].valor_produto = atof(valor_produto);
                    coluna_cliente= COLUNA_ID;
                    break;

                default:
                    break;
                }

                coluna_cliente += 1;
                continue;
            }

            switch (coluna_cliente)
            {
            case 1:
                strncat(id, &response[i], 1);
                break;

            case 2:
                strncat(nome, &response[i], 1);
                break;

            case 3:
                strncat(cpf_cnpj, &response[i], 1);
                break;

            case 4:
                strncat(valor_produto, &response[i], 1);
                break;

            case 5:
                strncat(data_entrega, &response[i], 1);
                break;

            default:
                break;
            }
        }
    }

    model.clientes = clientes;
    return model;
}