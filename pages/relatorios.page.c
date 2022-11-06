#include "../headers.h"
#include "../constantes.h"

void x()
{
    struct Cliente cliente = {0, "Empresa x", "00.000.000/0001-00", 10000, "10/05/2023"};
    // struct Criar_cliente_model model = criar_cliente_repository(cliente);
    struct Criar_cliente_model model = criar_cliente_service(cliente);
    puts(model.mensagem);
}

void relatorios_page(bool erro)
{
    void criar_relatorio_funcionarios();
    char acao;
    system("clear");
    puts(TEXTO_TITULO_RELATORIOS);
    puts(TEXTO_OPCOES_RELATORIOS);

    if (erro == true)
    {
        puts(TEXTO_OPCAO_INVALIDA);
    }

    scanf("\n%c", &acao);

    switch (acao)
    {
    case '1':
        criar_relatorio_funcionarios();
        break;

    default:
        x();
        // relatorios_page(true);
        break;
    }
}

void criar_relatorio_funcionarios()
{
    char voltar;
    struct Criar_relatorio_model model = criar_relatorio_funcionarios_service();
    puts(model.mensagem);

    if (model.erro == false)
    {
        system("./abrir-relatorios.sh");
    }

    puts(TEXTO_VOLTAR);
    while ((voltar = getc(stdin)) == '\n')
        ;
    home_page(false);
}