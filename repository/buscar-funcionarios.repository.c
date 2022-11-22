#include "../headers.h"
#include "../constantes.h"

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

    char ch;
    char id[10] = "";
    char nome[150] = "";
    char cpf[15] = "";
    char rg[15] = "";
    char cargo[5] = "";
    char salario[15] = "";

    int coluna = 1;
    int contador_registros = 0;

    struct Buscar_funcionarios_model model = {};
    struct Funcionario funcionarios[500] = {};

    char caminho_arquivo[150] = "";
    montar_caminho_arquivo(caminho_arquivo, "/database/funcionarios.txt");

    FILE *txt_funcionarios;
    txt_funcionarios = fopen(caminho_arquivo, "r");

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
        putchar(ch);
        if (ch == '\n')
        {
            contador_registros += 1;
            coluna = COLUNA_ID;
            strcpy(id, "");
            strcpy(nome, "");
            strcpy(cpf, "");
            strcpy(rg, "");
            strcpy(cargo, "");
            strcpy(salario, "");
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
            strcpy(funcionarios[contador_registros].nome, decrypt(nome));
            continue;
        }

        if (ch == ',' && coluna == COLUNA_CPF)
        {
            coluna += 1;
            strcpy(funcionarios[contador_registros].cpf, decrypt(cpf));
            continue;
        }

        if (ch == ',' && coluna == COLUNA_RG)
        {
            coluna += 1;
            strcpy(funcionarios[contador_registros].rg, decrypt(rg));
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
            funcionarios[contador_registros].salario = atof(salario);
            continue;
        }

        if (ch == ',' && coluna == COLUNA_POSSUI_FERIAS)
        {
            coluna += 1;
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
    }

    fclose(txt_funcionarios);

    model.erro = 0;
    model.mensagem = "[OK] buscar_funcionarios_repository";
    model.quantidade_funcionarios = contador_registros;
    model.funcionarios = funcionarios;

    return model;
}