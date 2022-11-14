#include "../headers.h"
#include "../constantes.h"

void relatorios_page(int erro)
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
        relatorios_page(true);
        break;
    }
}

void criar_relatorio_funcionarios()
{
    struct Criar_relatorio_model model = criar_relatorio_funcionarios_service();
    puts(model.mensagem);

    if (model.erro == false)
    {
        system("./abrir-relatorios.sh");
    }

    voltar();
}