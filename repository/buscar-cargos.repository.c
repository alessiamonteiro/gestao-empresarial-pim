#include "../headers.h"

struct Buscar_cargos_model buscar_cargos_repository()
{
    const int COLUNA_ID = 1;
    const int COLUNA_CARGO = 2;

    int coluna = 1;
    int contador_registros = 0;

    char id[10] = "";
    char cargo[50] = "";
    char ch;

    struct Buscar_cargos_model cargos_model = {};

    char caminho_arquivo[150] = "";
    montar_caminho_arquivo(caminho_arquivo, "/database/cargos.txt");

    FILE *txt_cargos = fopen(caminho_arquivo, "r");

    if (txt_cargos == NULL)
    {
        cargos_model.erro = true;
        cargos_model.mensagem = "[ERRO] buscar_cargos_repository";
        cargos_model.quantidade_cargos = 0;
        return cargos_model;
    }

    while ((ch = fgetc(txt_cargos)) != EOF)
    {

        if (ch == '\n')
        {
            if (coluna == COLUNA_CARGO)
            {
                strcpy(cargos_model.cargos[contador_registros].cargo, cargo);
            }

            contador_registros += 1;
            coluna = COLUNA_ID;
            strcpy(id, "");
            strcpy(cargo, "");
        }

        if (ch == ',' && coluna == COLUNA_ID)
        {
            coluna += 1;
            cargos_model.cargos[contador_registros].id = atoi(id);
            continue;
        }

        if (coluna == COLUNA_ID)
        {
            strncat(id, &ch, 1);
        }

        if (coluna == COLUNA_CARGO)
        {
            strncat(cargo, &ch, 1);
        }
    }

    cargos_model.erro = 0;
    cargos_model.mensagem = "[OK] buscar_cargos_repository";
    cargos_model.quantidade_cargos = contador_registros;
    return cargos_model;
}