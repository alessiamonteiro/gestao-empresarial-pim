#include "../headers.h"
#include "../constantes.h"

struct Criar_relatorio_model criar_relatorio_clientes_repository(struct Buscar_clientes_model model)
{
    struct Criar_relatorio_model output = {};
    // pega a data hora atual time_t
    char string_data_hora_atual[20];
    time_t segundos;
    time(&segundos);

    struct tm *data_hora_atual;
    data_hora_atual = localtime(&segundos);

    // transforma time_t (long int) pra string
    sprintf(string_data_hora_atual, "%ld", segundos);

    // monta nome do arquivo
    char sufixo[75] = "/relatorios/clientes/rel_funcionarios_";
    strcat(sufixo, string_data_hora_atual);
    strcat(sufixo, ".txt");

    char caminho_arquivo[150] = "";
    montar_caminho_arquivo(caminho_arquivo, sufixo);

    FILE *txt_relatorio = fopen(caminho_arquivo, "w");

    if (txt_relatorio == NULL)
    {
        output.erro = true;
        output.mensagem = "[ERRO] ocorreu um erro ao abrir o arquivo!";
        return output;
    }

    fprintf(txt_relatorio, "%s\n", TEXTO_TITULO_RELATORIO_CLIENTES);

    fprintf(txt_relatorio, "Data: %d/%d/%d \n\n",
            data_hora_atual->tm_mday,
            data_hora_atual->tm_mon + 1,
            data_hora_atual->tm_year + 1900);

    fprintf(txt_relatorio, "%s", "Total de clientes: ");
    fprintf(txt_relatorio, "%i\n\n", model.quantidade_clientes);

    fprintf(txt_relatorio, "%s", "Receita total dos produtos: ");
    fprintf(txt_relatorio, "R$ %.2f\n\n", calcular_soma_valor_produtos(model));

    fprintf(txt_relatorio, "%s", "Todos os clientes: \n\n");

    for (int i = 0; i < model.quantidade_clientes; i++)
    {
        fprintf(txt_relatorio, "\tNome: ");
        fprintf(txt_relatorio, " %s\n", model.clientes[i].nome);

        fprintf(txt_relatorio, "\tCPF/CNPJ:");
        fprintf(txt_relatorio, " %s\n", model.clientes[i].cpf_cnpj);

        // formatar valor produto
        char valor_produto[50];
        strfmon(valor_produto, 35, "%n", model.clientes[i].valor_produto);
        fprintf(txt_relatorio, "\tValor do produto encomendado: ");
        fprintf(txt_relatorio, "R$ %s\n", valor_produto);

        fprintf(txt_relatorio, "\tData de entrega: ");
        fprintf(txt_relatorio, " %s\n\n", model.clientes[i].data_entrega);
    }

    fclose(txt_relatorio);
    output.erro = false;
    output.mensagem = "[OK] relatório criado com sucesso!";
    return output;
}

const double calcular_soma_valor_produtos(struct Buscar_clientes_model model)
{
    double total = 0;
    for (int i = 0; i < model.quantidade_clientes; i++)
        total += model.clientes[i].valor_produto;

    return total;
}