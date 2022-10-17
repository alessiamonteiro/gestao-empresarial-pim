#include "../headers.h"

struct Buscar_funcionarios_model mapear_buscar_funcionarios_service(char response[1024]);

struct Buscar_funcionarios_model buscar_funcionarios_service()
{
    char response[1024] = {};
    socket_client("GET/funcionarios", response);
    puts(response);
    return mapear_buscar_funcionarios_service(response);
}

struct Buscar_funcionarios_model mapear_buscar_funcionarios_service(char response[1024])
{
    const int COLUNA_ERRO = 1;
    const int COLUNA_MENSAGEM = 2;
    const int COLUNA_QUANTIDADE_FUNCIONARIOS = 3;
    const int COLUNA_FUNCIONARIO = 4;

    const int COLUNA_ID = 1;
    const int COLUNA_NOME = 2;
    const int COLUNA_CPF = 3;
    const int COLUNA_RG = 4;
    const int COLUNA_CARGO = 5;
    const int COLUNA_SALARIO = 6;
    const int COLUNA_POSSUI_FERIAS = 7;
    const int COLUNA_ESTA_DE_FERIAS = 8;
    const int COLUNA_DATA_INICIO = 9;
    const int COLUNA_DATA_INICIO_CONTAGEM_FERIAS = 10;
    const int COLUNA_VALIDADE_FERIAS = 11;

    struct Funcionario funcionarios[500] = {};
    struct Buscar_funcionarios_model model = {};

    int coluna = 1;
    int coluna_funcionario = 1;
    int contador_registros = 0;

    char mensagem[200] = "";

    char id[10] = "";
    char nome[150] = "";
    char cpf[15] = "";
    char rg[15] = "";
    char cargo[15] = "";
    char salario[15] = "";
    char data_inicio[64] = "";
    char data_inicio_contagem_ferias[64] = "";
    char validade_ferias[64] = "";
    char quantidade_funcionarios_char[10] = "";

    model.mensagem = "";
    model.erro = atoi(&response[0]);

    for (int i = 0; i < strlen(response); i++)
    {

        if (response[i] == '\n')
            continue;

        if (response[i] == ';' && coluna == COLUNA_ERRO)
        {
            coluna += 1;
            continue;
        }

        if (response[i] == ';' && coluna == COLUNA_QUANTIDADE_FUNCIONARIOS)
        {
            coluna += 1;
            model.quantidade_funcionarios = atoi(quantidade_funcionarios_char);
            continue;
        }

        if (response[i] == ';' && coluna == COLUNA_MENSAGEM)
        {
            coluna += 1;
            model.mensagem = mensagem;
            continue;
        }

        if (coluna == COLUNA_MENSAGEM)
        {
            strncat(mensagem, &response[i], 1);
        }

        if (coluna == COLUNA_QUANTIDADE_FUNCIONARIOS)
        {
            strncat(quantidade_funcionarios_char, &response[i], 1);
        }

        if (coluna == COLUNA_FUNCIONARIO)
        {
            if (response[i] == ',' && coluna_funcionario == COLUNA_ID)
            {
                coluna_funcionario += 1;
                funcionarios[contador_registros].id = atoi(id);
                continue;
            }

            if (response[i] == ',' && coluna_funcionario == COLUNA_NOME)
            {
                coluna_funcionario += 1;
                strcpy(funcionarios[contador_registros].nome, nome);
                continue;
            }

            if (response[i] == ',' && coluna_funcionario == COLUNA_CPF)
            {
                coluna_funcionario += 1;
                strcpy(funcionarios[contador_registros].cpf, cpf);
                continue;
            }

            if (response[i] == ',' && coluna_funcionario == COLUNA_RG)
            {
                coluna_funcionario += 1;
                strcpy(funcionarios[contador_registros].rg, rg);
                continue;
            }

            if (response[i] == ',' && coluna_funcionario == COLUNA_CARGO)
            {
                coluna_funcionario += 1;
                funcionarios[contador_registros].cargo = atoi(cargo);
                continue;
            }

            if (response[i] == ',' && coluna_funcionario == COLUNA_SALARIO)
            {
                coluna_funcionario += 1;
                funcionarios[contador_registros].salario = atoi(salario);
                continue;
            }

            if (response[i] == ',' && coluna_funcionario == COLUNA_DATA_INICIO)
            {
                coluna_funcionario += 1;
                funcionarios[contador_registros].data_inicio = atol(data_inicio);
                continue;
            }

            if (response[i] == ',' && coluna_funcionario == COLUNA_DATA_INICIO_CONTAGEM_FERIAS)
            {
                coluna_funcionario += 1;
                funcionarios[contador_registros].data_inicio_contagem_ferias = atol(data_inicio_contagem_ferias);
                continue;
            }

            if (response[i] == ';' && coluna_funcionario == COLUNA_VALIDADE_FERIAS)
            {
                funcionarios[contador_registros].validade_ferias = atol(validade_ferias);
                coluna_funcionario = COLUNA_ID;
                contador_registros += 1;
                strcpy(id, "");
                strcpy(nome, "");
                strcpy(cpf, "");
                strcpy(rg, "");
                strcpy(cargo, "");
                strcpy(salario, "");
                strcpy(data_inicio, "");
                strcpy(data_inicio_contagem_ferias, "");
                strcpy(validade_ferias, "");
                continue;
            }

            if (coluna_funcionario == COLUNA_ID)
            {
                strncat(id, &response[i], 1);
            }

            if (coluna_funcionario == COLUNA_NOME)
            {
                strncat(nome, &response[i], 1);
            }

            if (coluna_funcionario == COLUNA_CPF)
            {
                strncat(cpf, &response[i], 1);
            }

            if (coluna_funcionario == COLUNA_RG)
            {
                strncat(rg, &response[i], 1);
            }

            if (coluna_funcionario == COLUNA_CARGO)
            {
                strncat(cargo, &response[i], 1);
            }

            if (coluna_funcionario == COLUNA_SALARIO)
            {
                strncat(salario, &response[i], 1);
            }

            if (coluna_funcionario == COLUNA_POSSUI_FERIAS)
            {
                coluna_funcionario += 1;
                funcionarios[contador_registros].possui_ferias = atoi(&response[i]);
                continue;
            }

            if (coluna_funcionario == COLUNA_ESTA_DE_FERIAS)
            {
                coluna_funcionario += 1;
                funcionarios[contador_registros].esta_de_ferias = atoi(&response[i]);
                continue;
            }

            if (coluna_funcionario == COLUNA_DATA_INICIO)
            {
                strncat(data_inicio, &response[i], 1);
            }

            if (coluna_funcionario == COLUNA_DATA_INICIO_CONTAGEM_FERIAS)
            {
                strncat(data_inicio_contagem_ferias, &response[i], 1);
            }

            if (coluna_funcionario == COLUNA_VALIDADE_FERIAS)
            {
                strncat(validade_ferias, &response[i], 1);
            }
        }
    }
    model.funcionarios = funcionarios;
    return model;
}