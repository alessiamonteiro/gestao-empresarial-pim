#include "../headers.h"
#include "../constantes.h"

void cadastros_page(int erro)
{
    char acao;
    system("clear");
    puts(TEXTO_TITULO_CADASTROS);
    puts(TEXTO_OPCOES_CADASTROS);

    if (erro == true)
        puts(TEXTO_OPCAO_INVALIDA);

    scanf("\n%c", &acao);

    switch (acao)
    {
    case '1':
        return cadastro_funcionario_page(0, "");

    case '2':
        return cadastro_cliente_page();

    case '3':
        return home_page(false);
        
    default:
        cadastros_page(true);
    }
}
