#include "../headers.h"

struct Buscar_funcionarios_model buscar_funcionarios_repository()
{
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

    char ch;
    char id[10] = "";
    char nome[150] = "";
    char cpf[15] = "";
    char rg[15] = "";
    char cargo[5] = "";
    char salario[15] = "";
    char data_inicio[64] = "";
    char data_inicio_contagem_ferias[64] = "";
    char validade_ferias[64] = "";

    int coluna = 1;
    int contador_registros = 0;

    struct Buscar_funcionarios_model model = {};
    struct Funcionario funcionarios[500] = {};

    FILE *txt_funcionarios;
    txt_funcionarios = fopen("funcionarios.txt", "r");

    if (txt_funcionarios == NULL)
    {
        model.erro = true;
        model.mensagem = "[ERRO] buscar_funcionarios_repository";
        model.quantidade_funcionarios = 0;
        model.funcionarios = NULL;
        return model;
    }
    
    while ((ch = fgetc(txt_funcionarios)) != EOF)
    {
        if (ch == '\n')
        {
            if (coluna == COLUNA_VALIDADE_FERIAS)
            {
                funcionarios[contador_registros].validade_ferias = atol(validade_ferias);
            }

            contador_registros += 1;
            coluna = COLUNA_ID;
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

        if (ch == ',' && coluna == COLUNA_ID)
        {
            coluna += 1;
            funcionarios[contador_registros].id = atoi(id);
            continue;
        }

        if (ch == ',' && coluna == COLUNA_NOME)
        {
            coluna += 1;
            strcpy(funcionarios[contador_registros].nome, nome);
            continue;
        }

        if (ch == ',' && coluna == COLUNA_CPF)
        {
            coluna += 1;
            strcpy(funcionarios[contador_registros].cpf, cpf);
            continue;
        }

        if (ch == ',' && coluna == COLUNA_RG)
        {
            coluna += 1;
            strcpy(funcionarios[contador_registros].rg, rg);
            continue;
        }

        if (ch == ',' && coluna == COLUNA_CARGO)
        {
            coluna += 1;
            funcionarios[contador_registros].cargo = atoi(cargo);
            continue;
        }

        if (ch == ',' && coluna == COLUNA_SALARIO)
        {
            coluna += 1;
            funcionarios[contador_registros].salario = atoi(salario);
            continue;
        }

        if (ch == ',' && (coluna == COLUNA_POSSUI_FERIAS || coluna == COLUNA_ESTA_DE_FERIAS))
        {
            coluna += 1;
            continue;
        }

        if (ch == ',' && coluna == COLUNA_DATA_INICIO)
        {
            coluna += 1;
            funcionarios[contador_registros].data_inicio = atol(data_inicio);
            continue;
        }

        if (ch == ',' && coluna == COLUNA_DATA_INICIO_CONTAGEM_FERIAS)
        {
            coluna += 1;
            funcionarios[contador_registros].data_inicio_contagem_ferias = atol(data_inicio_contagem_ferias);
            continue;
        }

        if (coluna == COLUNA_ID)
        {
            strncat(id, &ch, 1);
        }

        if (coluna == COLUNA_NOME)
        {
            strncat(nome, &ch, 1);
        }

        if (coluna == COLUNA_CPF)
        {
            strncat(cpf, &ch, 1);
        }

        if (coluna == COLUNA_RG)
        {
            strncat(rg, &ch, 1);
        }

        if (coluna == COLUNA_CARGO)
        {
            strncat(cargo, &ch, 1);
        }

        if (coluna == COLUNA_SALARIO)
        {
            strncat(salario, &ch, 1);
        }

        if (coluna == COLUNA_POSSUI_FERIAS)
        {
            funcionarios[contador_registros].possui_ferias = atoi(&ch);
        }

        if (coluna == COLUNA_ESTA_DE_FERIAS)
        {
            funcionarios[contador_registros].esta_de_ferias = atoi(&ch);
        }

        if (coluna == COLUNA_DATA_INICIO)
        {
            strncat(data_inicio, &ch, 1);
        }

        if (coluna == COLUNA_DATA_INICIO_CONTAGEM_FERIAS)
        {
            strncat(data_inicio_contagem_ferias, &ch, 1);
        }

        if (coluna == COLUNA_VALIDADE_FERIAS)
        {
            strncat(validade_ferias, &ch, 1);
        }
    }

    model.erro = 0;
    model.mensagem = "[OK] buscar_funcionarios_repository";
    model.quantidade_funcionarios = contador_registros;
    model.funcionarios = funcionarios;

    return model;
}