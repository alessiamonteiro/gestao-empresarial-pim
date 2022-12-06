#include "../headers.h"

struct Criar_relatorio_model criar_relatorio_funcionarios_service()
{
    struct Criar_relatorio_model mapear_criar_relatorio_funcionarios_service(char buffer[1024]);
    
    char response[1024] = {};
    char url[500] = "POST/relatorios/funcionarios";

    socket_client(url, response);
    return mapear_criar_relatorio_funcionarios_service(response);
}

struct Criar_relatorio_model mapear_criar_relatorio_funcionarios_service(char buffer[1024])
{
    const int COLUNA_ERRO = 1;
    const int COLUNA_MENSAGEM = 2;

    char erro[2] = "";
    char mensagem[200];

    int coluna = COLUNA_ERRO;

    struct Criar_relatorio_model model = {};

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

    }

    model.erro = atoi(erro);
    model.mensagem = mensagem;
    return model;
}
