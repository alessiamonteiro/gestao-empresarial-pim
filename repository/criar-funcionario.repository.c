#include "../headers.h"

struct Criar_funcionario_model criar_funcionario_repository(struct Funcionario funcionario)
{
    struct Criar_funcionario_model model = {0, "", ""};

    FILE *txt_funcionarios;
    txt_funcionarios = fopen("funcionarios.txt", "a");

    if (txt_funcionarios == NULL)
    {
        model.erro = 1;
        model.nome_funcionario = "";
        model.mensagem = "[ERRO] criar_funcionario_repository";
        return model;
    }

    fprintf(txt_funcionarios, "%i,%s,%s,%s,%i,%i,%i,%i\n",
            funcionario.id,
            funcionario.nome,
            funcionario.cpf,
            funcionario.rg,
            funcionario.cargo,
            funcionario.salario,
            funcionario.possui_ferias,
            funcionario.esta_de_ferias);

    fclose(txt_funcionarios);

    model.erro = false;
    model.nome_funcionario = funcionario.nome;
    model.mensagem = "Cadastro realizado com sucesso!\n";
    return model;
}