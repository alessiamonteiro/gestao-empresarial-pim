#include "../headers.h"
#include "../constantes.h"

void cadastro_cliente_page()
{
    system("clear");
    struct Cliente cliente = {};
    cliente.id = 0;

    puts(TEXTO_TITULO_CADASTRO_CLIENTE);

    // adicionar validacoes necessarias aos campos
   
    puts("\nNome:\n");
    scanf(" %[^\n]s", cliente.nome);
    
    puts("\n\n CPF ou CNPJ:");
    scanf("%s", cliente.cpf_cnpj);

    puts("\n\n Valor do produto encomendado:");
    scanf("%e", &cliente.valor_produto);

    puts("\n\n Data de entrega:");
    scanf("%s", cliente.data_entrega);

    struct Criar_cliente_model model = criar_cliente_service(cliente);
    puts(model.mensagem);
    system("sleep 03");
    system("clear");

    if (model.erro == true) {
        cadastro_cliente_page();
        return;
    }

    home_page(false);
}