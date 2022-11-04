#include "../headers.h"

struct Criar_funcionario_model mapear_criar_funcionario_model(char buffer[1024]);

struct Criar_funcionario_model criar_funcionario_service(struct Funcionario funcionario)
{
    char response[1024] = {};
    char url[500] = "POST/funcionarios";

    char cargo[10];
    char salario[20];
    char possui_ferias[5];
    char esta_de_ferias[2] = "";

    sprintf(cargo, "%d", funcionario.cargo);
    sprintf(salario, "%.2f", funcionario.salario);
    sprintf(possui_ferias, "%d", funcionario.possui_ferias);
    sprintf(esta_de_ferias, "%d", funcionario.esta_de_ferias);

    strcat(url, "?nome=");
    strcat(url, funcionario.nome);

    strcat(url, "&cpf=");
    strcat(url, funcionario.cpf);

    strcat(url, "&rg=");
    strcat(url, funcionario.rg);

    strcat(url, "&cargo=");
    strcat(url, cargo);

    strcat(url, "&salario=");
    strcat(url, salario);

    socket_client(url, response);
    puts(response);
    return mapear_criar_funcionario_model(response);
}

struct Criar_funcionario_model mapear_criar_funcionario_model(char buffer[1024])
{
    const int COLUNA_ERRO = 1;
    const int COLUNA_MENSAGEM = 2;
    const int COLUNA_NOME = 3;
    char erro[2] = "";
    char mensagem[200];
    char nome[200];

    int coluna = COLUNA_ERRO;

    struct Criar_funcionario_model model = {};

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
    model.nome_funcionario = nome;
    return model;
}
