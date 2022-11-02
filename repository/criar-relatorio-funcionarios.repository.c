#include "../headers.h"
#include "../constantes.h"

const char *encontrar_cargo(int id, struct Buscar_cargos_model buscar_cargos_model);

void criar_relatorio_funcionarios_repository(struct Buscar_funcionarios_model buscar_funcionarios_model, struct Buscar_cargos_model buscar_cargos_model)
{
    char string_data_hora_atual[20];
    time_t segundos;

    time(&segundos);
    sprintf(string_data_hora_atual, "%ld", segundos);

    char caminho_pasta_relatorios[150] = "/home/jmanara/c/gestao-empresarial-pim/relatorios/";
    strcat(caminho_pasta_relatorios, "rel_funcionarios_");
    strcat(caminho_pasta_relatorios, string_data_hora_atual);
    strcat(caminho_pasta_relatorios, ".txt");

    FILE *txt_relatorio;
    txt_relatorio = fopen(caminho_pasta_relatorios, "w");

    fprintf(txt_relatorio, "%s\n", TEXTO_TITULO_RELATORIO_FUNCIONARIOS);

    for (int i = 0; i < buscar_funcionarios_model.quantidade_funcionarios; i++)
    {
        fprintf(txt_relatorio, "\tNome:");
        fprintf(txt_relatorio, " %s\n", buscar_funcionarios_model.funcionarios[i].nome);

        fprintf(txt_relatorio, "\tCargo:");
        fprintf(txt_relatorio, " %s\n", encontrar_cargo(
                             buscar_funcionarios_model.funcionarios[i].id,
                             buscar_cargos_model));
        
        char salario[50];
        strfmon(salario, 35, "%n", buscar_funcionarios_model.funcionarios[i].salario);

        fprintf(txt_relatorio, "\tSalario:");
        fprintf(txt_relatorio, " %s\n", salario);

        fprintf(txt_relatorio, "\tCPF:");
        fprintf(txt_relatorio, " %s\n\n", buscar_funcionarios_model.funcionarios[i].cpf);
    }
}

const char *encontrar_cargo(int id, struct Buscar_cargos_model model)
{
    for (int i = 0; i < model.quantidade_cargos; i++)
    {
        if (model.cargos[i].id == id)
        {
            char * cargo = model.cargos[i].cargo;
            return cargo;
        }
    }

    return "Cargo não encontrado";
}