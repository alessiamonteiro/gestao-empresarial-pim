#include "../headers.h"

void mapear_buscar_funcionarios_controller(char buffer[1024], struct Buscar_funcionarios_model model);

void buscar_funcionarios_controller(char buffer[1024])
{
    struct Buscar_funcionarios_model model = buscar_funcionarios_usecase();
    mapear_buscar_funcionarios_controller(buffer, model);
}

void mapear_buscar_funcionarios_controller(char buffer[1024], struct Buscar_funcionarios_model model)
{
    char erro_repository[2];
    char quantidade_funcionarios[20];

    sprintf(erro_repository, "%d", model.erro);
    sprintf(quantidade_funcionarios, "%d", model.quantidade_funcionarios);

    strcat(buffer, erro_repository);
    strcat(buffer, ";");

    strcat(buffer, model.mensagem);
    strcat(buffer, ";");

    if (model.erro == true && model.quantidade_funcionarios == 0)
    {
        strcat(buffer, "\n");
        return;
    }

    strcat(buffer, quantidade_funcionarios);
    strcat(buffer, ";");

    for (int i = 0; i < model.quantidade_funcionarios; i++)
    {
        char id[10] = "";
        char possui_ferias[2] = "";
        char esta_de_ferias[2] = "";
        char salario[15] = "";
        char cargo[10] = "";

        sprintf(id, "%d", model.funcionarios[i].id);
        strcat(buffer, id);
        strcat(buffer, ",");

        strcat(buffer, model.funcionarios[i].nome);
        strcat(buffer, ",");

        strcat(buffer, model.funcionarios[i].cpf);
        strcat(buffer, ",");

        strcat(buffer, model.funcionarios[i].rg);
        strcat(buffer, ",");

        sprintf(cargo, "%d", model.funcionarios[i].cargo);
        strcat(buffer, cargo);
        strcat(buffer, ",");

        sprintf(salario, "%d", model.funcionarios[i].salario);
        strcat(buffer, salario);
        strcat(buffer, ",");

        sprintf(possui_ferias, "%d", model.funcionarios[i].possui_ferias);
        strcat(buffer, possui_ferias);
        strcat(buffer, ",");

        sprintf(esta_de_ferias, "%d", model.funcionarios[i].esta_de_ferias);
        strcat(buffer, esta_de_ferias);
        strcat(buffer, ";");
    }

    strcat(buffer, "\n");
}
