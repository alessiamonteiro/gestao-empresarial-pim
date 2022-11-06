#include "../headers.h"

struct Criar_cliente_model criar_cliente_service(struct Cliente cliente)
{
    struct Criar_cliente_model mapear_criar_cliente_model(char buffer[1024]);

    char response[1024] = {};
    char url[500] = "POST/clientes";

    char valor_produto[10];
    sprintf(valor_produto, "%.2f", cliente.valor_produto);

    strcat(url, "?nome=");
    strcat(url, cliente.nome);

    strcat(url, "&cpf_cnpj=");
    strcat(url, cliente.cpf_cnpj);

    strcat(url, "&valor_produto=");
    strcat(url, valor_produto);

    strcat(url, "&data_entrega=");
    strcat(url, cliente.data_entrega);

    socket_client(url, response);
    puts(response);
    return mapear_criar_cliente_model(response);
}

struct Criar_cliente_model mapear_criar_cliente_model(char buffer[1024])
{   
    const int COLUNA_ERRO = 1;
    const int COLUNA_MENSAGEM = 2;
    const int COLUNA_NOME = 3;
    char erro[2] = "";
    char mensagem[150];
    char nome[150];

    int coluna = COLUNA_ERRO;

    struct Criar_cliente_model model = {};

    for (int i = 0; i < strlen(buffer); i++)
    {
        if (buffer[i] == ';')
        {
            coluna += 1;
            continue;
        }

        if (coluna == COLUNA_ERRO)
        {
            strncat(erro, &buffer[i], 1);
        }

        if (coluna == COLUNA_MENSAGEM)
        {
            strncat(mensagem, &buffer[i], 1);
        }

        if (coluna == COLUNA_NOME)
        {
            strncat(nome, &buffer[i], 1);
        }
    }

    model.erro = atoi(erro);
    model.mensagem = mensagem;
    model.nome_cliente = nome;
    return model;
}