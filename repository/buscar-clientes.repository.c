#include "../headers.h"
#include "../constantes.h"

struct Buscar_clientes_model buscar_clientes_repository()
{
    char ch;
    char id[5] = "";
    char nome[150] = "";
    char cpf_cnpj[19] = "";
    char valor_produto[10] = "";
    char data_entrega[15] = "";

    int coluna = 1;
    int contador_registros = 0;

    struct Buscar_clientes_model model = {};
    struct Cliente clientes[500] = {};

    char caminho_arquivo[150] = "";
    montar_caminho_arquivo(caminho_arquivo, "/database/clientes.txt");

    FILE *txt_clientes = fopen(caminho_arquivo, "r");

    if (txt_clientes == NULL)
    {
        model.erro = true;
        model.mensagem = "[ERRO] buscar_clientes_repository";
        model.quantidade_clientes = 0;
        model.clientes = NULL;
        return model;
    }

    while ((ch = fgetc(txt_clientes)) != EOF)
    {
        if (ch == '\n')
        {
            if (coluna == 5)
            {
                strcpy(clientes[contador_registros].data_entrega, data_entrega);
            }

            contador_registros += 1;
            coluna = 1;
            strcpy(id, "");
            strcpy(nome, "");
            strcpy(cpf_cnpj, "");
            strcpy(valor_produto, "");
            strcpy(data_entrega, "");
            continue;
        }

        if (ch == ',')
        {
            switch (coluna)
            {
            case 1:
                clientes[contador_registros].id = atoi(id);
                break;

            case 2:
                strcpy(clientes[contador_registros].nome, decrypt(nome));
                break;

            case 3:
                strcpy(clientes[contador_registros].cpf_cnpj, decrypt(cpf_cnpj));
                break;

            case 4:
                clientes[contador_registros].valor_produto = atof(valor_produto);
                break;
            }

            coluna += 1;
            continue;
        }

        switch (coluna)
        {
        case 1:
            strncat(id, &ch, 1);
            break;

        case 2:
            strncat(nome, &ch, 1);
            break;

        case 3:
            strncat(cpf_cnpj, &ch, 1);
            break;

        case 4:
            strncat(valor_produto, &ch, 1);
            break;

        case 5:
            strncat(data_entrega, &ch, 1);
            break;
        }
    }

    fclose(txt_clientes);

    model.erro = 0;
    model.mensagem = "[OK] buscar_clientes_repository";
    model.quantidade_clientes = contador_registros;
    model.clientes = clientes;

    return model;
}