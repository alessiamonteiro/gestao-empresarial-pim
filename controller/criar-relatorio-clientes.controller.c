#include "../headers.h"

void criar_relatorio_clientes_controller(char buffer[1024])
{
    void mapear_criar_relatorio_clientes_response(char buffer[1024], struct Criar_relatorio_model model);

    // entrypoint log
    puts("ENTRYPOINT criar_relatorio_clientes_controller");
    puts(buffer);

    bzero(buffer, 1024);

    struct Criar_relatorio_model usecase_response = criar_relatorio_clientes_usecase();
    mapear_criar_relatorio_clientes_response(buffer, usecase_response);
}

void mapear_criar_relatorio_clientes_response(char buffer[1024], struct Criar_relatorio_model model)
{
    char erro[2];

    sprintf(erro, "%d", model.erro);
    strcat(buffer, erro);
    strcat(buffer, ";");

    strcat(buffer, model.mensagem);
    strcat(buffer, ";");
}

