#include "../headers.h"

struct Buscar_funcionarios_model mapear_buscar_funcionarios_service(char response[1024]);

struct Buscar_funcionarios_model buscar_funcionarios_service()
{
    char response[1024] = {};
    socket_client("GET/funcionarios", response);
    return mapear_buscar_funcionarios_service(response);
}

struct Buscar_funcionarios_model mapear_buscar_funcionarios_service(char response[1024])
{
    const int COLUNA_ID = 1;
    const int COLUNA_ERRO = 1;
    const int COLUNA_MENSAGEM = 2;
    const int COLUNA_QUANTIDADE_REGISTROS = 3;
    const int COLUNA_FUNCIONARIO = 4;

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
            case 2:
                model.mensagem = mensagem;
                break;

            case 3:
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
                case 1:
                    funcionarios[contador_registros].id = atoi(id);
                    break;

                case 2:
                    strcpy(funcionarios[contador_registros].nome, nome);
                    break;

                case 3:
                    strcpy(funcionarios[contador_registros].cpf, cpf);
                    break;

                case 4:
                    strcpy(funcionarios[contador_registros].rg, rg);
                    break;

                case 5:
                    funcionarios[contador_registros].cargo = atoi(cargo);
                    break;

                case 6:
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
            case 1:
                strncat(id, &response[i], 1);
                break;

            case 2:
                strncat(nome, &response[i], 1);
                break;

            case 3:
                strncat(cpf, &response[i], 1);
                break;

            case 4:
                strncat(rg, &response[i], 1);
                break;

            case 5:
                strncat(cargo, &response[i], 1);
                break;

            case 6:
                strncat(salario, &response[i], 1);
                break;

            case 7:
                funcionarios[contador_registros].possui_ferias = atoi(&response[i]);
                continue;

            case 8:
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