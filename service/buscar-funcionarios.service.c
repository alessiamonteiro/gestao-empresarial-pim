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
    struct Funcionario funcionarios[500] = {};
    struct Buscar_funcionarios_model model = {};

    int coluna = COLUNA_ERRO;
    int coluna_funcionario = COLUNA_ID;
    int contador_registros = 0;

    char mensagem[200] = "";

    char id[10] = "";
    char nome[150] = "";
    char cpf[15] = "";
    char rg[15] = "";
    char cargo[15] = "";
    char salario[15] = "";
    char quantidade_funcionarios_char[10] = "";

    model.mensagem = "";
    model.erro = atoi(&response[0]);

    for (int i = 0; i < strlen(response); i++)
    {

        if (response[i] == '\n')
            continue;

        if (response[i] == ';' && coluna < COLUNA_FUNCIONARIO)
        {
            switch (coluna)
            {
            case COLUNA_MENSAGEM:
                model.mensagem = mensagem;
                break;

            case COLUNA_QUANTIDADE_REGISTROS:
                model.quantidade_funcionarios = atoi(quantidade_funcionarios_char);
                break;

            default:
                break;
            }

            coluna += 1;
            continue;
        }

        if (coluna == COLUNA_MENSAGEM)
        {
            strncat(mensagem, &response[i], 1);
        }

        if (coluna == COLUNA_QUANTIDADE_REGISTROS)
        {
            strncat(quantidade_funcionarios_char, &response[i], 1);
        }

        if (coluna == COLUNA_FUNCIONARIO)
        {
            if (response[i] == ';')
            {
                contador_registros += 1;
                strcpy(id, "");
                strcpy(nome, "");
                strcpy(cpf, "");
                strcpy(rg, "");
                strcpy(cargo, "");
                strcpy(salario, "");
                continue;
            }

            if (response[i] == ',')
            {
                switch (coluna_funcionario)
                {
                case COLUNA_ID:
                    funcionarios[contador_registros].id = atoi(id);
                    break;

                case COLUNA_NOME:
                    strcpy(funcionarios[contador_registros].nome, nome);
                    break;

                case COLUNA_CPF:
                    strcpy(funcionarios[contador_registros].cpf, cpf);
                    break;

                case COLUNA_RG:
                    strcpy(funcionarios[contador_registros].rg, rg);
                    break;

                case COLUNA_CARGO:
                    funcionarios[contador_registros].cargo = atoi(cargo);
                    break;

                case COLUNA_SALARIO:
                    funcionarios[contador_registros].salario = atoi(salario);
                    break;

                default:
                    break;
                }

                coluna_funcionario += 1;
                continue;
            }

            switch (coluna_funcionario)
            {
            case COLUNA_ID:
                strncat(id, &response[i], 1);
                break;

            case COLUNA_NOME:
                strncat(nome, &response[i], 1);
                break;

            case COLUNA_CPF:
                strncat(cpf, &response[i], 1);
                break;

            case COLUNA_RG:
                strncat(rg, &response[i], 1);
                break;

            case COLUNA_CARGO:
                strncat(cargo, &response[i], 1);
                break;

            case COLUNA_SALARIO:
                strncat(salario, &response[i], 1);
                break;

            case COLUNA_POSSUI_FERIAS:
                funcionarios[contador_registros].possui_ferias = atoi(&response[i]);
                continue;

            case COLUNA_ESTA_DE_FERIAS:
                coluna_funcionario = COLUNA_ID;
                funcionarios[contador_registros].esta_de_ferias = atoi(&response[i]);
                continue;

            default:
                break;
            }
        }
    }
    model.funcionarios = funcionarios;
    return model;
}