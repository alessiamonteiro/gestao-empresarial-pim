#include "../headers.h"
#include "../constantes.h"

void buscar_clientes_page()
{
    system("clear");

    struct Buscar_clientes_model model = buscar_clientes_service();

    puts("\n\nlista de clientes: \n");

    for (int i = 0; i < model.quantidade_clientes; i++)
    {
        printf(" id: %i\n nome: %s\n cpf_cnpj: %s\n valor_produto: R$ %.2f\n data_entrega: %s\n\n\n",
               model.clientes[i].id,
               model.clientes[i].nome,
               model.clientes[i].cpf_cnpj,
               model.clientes[i].valor_produto,
               model.clientes[i].data_entrega
        );
    }

    voltar_consultas_page();
}