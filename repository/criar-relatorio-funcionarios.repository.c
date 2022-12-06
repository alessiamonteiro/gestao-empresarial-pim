#include "../headers.h"
#include "../constantes.h"

const double calcular_soma_salarios(struct Buscar_funcionarios_model buscar_funcionarios_model);

struct Criar_relatorio_model criar_relatorio_funcionarios_repository(struct Buscar_funcionarios_model buscar_funcionarios_model, struct Buscar_cargos_model buscar_cargos_model)
{
    struct Criar_relatorio_model model = {};
    // pega a data hora atual time_t
    char string_data_hora_atual[20];
    time_t segundos;
    time(&segundos);

    struct tm *data_hora_atual;
    data_hora_atual = localtime(&segundos);

    // transforma time_t (long int) pra string
    sprintf(string_data_hora_atual, "%ld", segundos);

    // monta nome do arquivo
    char sufixo[75] = "/relatorios/funcionarios/rel_funcionarios_";
    strcat(sufixo, string_data_hora_atual);
    strcat(sufixo, ".txt");

    char caminho_arquivo[150] = "";
    montar_caminho_arquivo(caminho_arquivo, sufixo);

    FILE *txt_relatorio = fopen(caminho_arquivo, "w");

    if (txt_relatorio == NULL)
    {
        model.erro = true;
        model.mensagem = "[ERRO] ocorreu um erro ao abrir o arquivo!";
        return model;
    }

    fprintf(txt_relatorio, "%s\n", TEXTO_TITULO_RELATORIO_FUNCIONARIOS);

    fprintf(txt_relatorio, "Data: %d/%d/%d \n\n",
            data_hora_atual->tm_mday,
            data_hora_atual->tm_mon + 1,
            data_hora_atual->tm_year + 1900);

    fprintf(txt_relatorio, "%s", "Total de funcionários: ");
    fprintf(txt_relatorio, "%i\n\n", buscar_funcionarios_model.quantidade_funcionarios);

    fprintf(txt_relatorio, "%s", "Despesa total com funcionarios: ");
    fprintf(txt_relatorio, "R$ %.2f\n\n", calcular_soma_salarios(buscar_funcionarios_model));

    fprintf(txt_relatorio, "%s", "Todos os funcionários: \n\n");

    for (int i = 0; i < buscar_funcionarios_model.quantidade_funcionarios; i++)
    {
        fprintf(txt_relatorio, "\tNome: ");
        fprintf(txt_relatorio, " %s\n", buscar_funcionarios_model.funcionarios[i].nome);

        fprintf(txt_relatorio, "\tCargo: ");
        fprintf(txt_relatorio, "%s\n", encontrar_cargo(buscar_funcionarios_model.funcionarios[i].id, buscar_cargos_model));

        // formatar salario
        char salario[50];
        strfmon(salario, 35, "%n", buscar_funcionarios_model.funcionarios[i].salario);
        fprintf(txt_relatorio, "\tSalario: ");
        fprintf(txt_relatorio, "R$ %s\n", salario);

        // formatar cpf -> presume que cpf tem 11 caracteres ja preenchidos (validar isso)
        char cpf_formatado[16];
        formatar_cpf(buscar_funcionarios_model.funcionarios[i].cpf, cpf_formatado);

        fprintf(txt_relatorio, "\tCPF:");
        fprintf(txt_relatorio, " %s\n\n", cpf_formatado);
    }

    fclose(txt_relatorio);
    model.erro = false;
    model.mensagem = "[OK] relatório criado com sucesso!";
    return model;
}

const double calcular_soma_salarios(struct Buscar_funcionarios_model buscar_funcionarios_model)
{
    double soma_todos_salarios = 0;
    for (int i = 0; i < buscar_funcionarios_model.quantidade_funcionarios; i++)    
        soma_todos_salarios += buscar_funcionarios_model.funcionarios[i].salario;

    return soma_todos_salarios;
}