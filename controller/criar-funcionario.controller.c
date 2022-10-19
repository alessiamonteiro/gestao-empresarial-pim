#include "../headers.h"

void criar_funcionario_controller(char buffer[1024])
{
    void mapear_criar_funcionario_response(char buffer[1024], struct Criar_funcionario_model model);

    const int COLUNA_NOME = 1;
    const int COLUNA_CPF = 2;
    const int COLUNA_RG = 3;
    const int COLUNA_CARGO = 4;
    const int COLUNA_SALARIO = 5;

    int coluna = COLUNA_NOME;
    bool deve_adicionar = false;

    char nome[150] = "";
    char cpf[15] = "";
    char rg[15] = "";
    char cargo[5] = "";
    char salario[15] = "";

    struct Funcionario funcionario = {};

    // entrypoint log
    puts("ENTRYPOINT criar_funcionario_controller");
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

        if (deve_adicionar == true && coluna == COLUNA_NOME)
        {
            strncat(nome, &buffer[i], 1);
        }

        if (deve_adicionar == true && coluna == COLUNA_CPF)
        {
            strncat(cpf, &buffer[i], 1);
        }

        if (deve_adicionar == true && coluna == COLUNA_RG)
        {
            strncat(rg, &buffer[i], 1);
        }

        if (deve_adicionar == true && coluna == COLUNA_CARGO)
        {
            strncat(cargo, &buffer[i], 1);
        }

        if (deve_adicionar == true && coluna == COLUNA_SALARIO)
        {
            strncat(salario, &buffer[i], 1);
        }
    }

    //montar struct funcionario
    strcpy(funcionario.nome, nome);
    strcpy(funcionario.cpf, cpf);
    strcpy(funcionario.rg, rg);
    funcionario.cargo = atoi(cargo);
    funcionario.salario = atoi(salario);
    //montar struct funcionario

    bzero(buffer, 1024);

    struct Criar_funcionario_model model = criar_funcionario_usecase(funcionario);
    mapear_criar_funcionario_response(buffer, model);
}

void mapear_criar_funcionario_response(char buffer[1024], struct Criar_funcionario_model model) {
    char erro[2];

    sprintf(erro, "%d", model.erro);
    strcat(buffer, erro);
    strcat(buffer, ";");

    strcat(buffer, model.mensagem);
    strcat(buffer, ";");

    strcat(buffer, model.nome_funcionario);
    strcat(buffer, ";");
}