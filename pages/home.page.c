#include "../headers.h"
#include "../constantes.h"

void home_page(int erro)
{
    char acao;

    system("clear");
    puts(TEXTO_TITULO_HOME);
    puts(TEXTO_OPCOES_HOME);

    if (erro == true)
        puts(TEXTO_OPCAO_INVALIDA);

    scanf("\n%c", &acao);

    switch (acao)
    {
    case '1':
        return perfil_page();

    case '2':
        return consultas_page(false);

    case '3':
        return cadastros_page(false);

    case '4':
        return relatorios_page(false);

    case '5':
        return menu_page(false);

    default:
        return home_page(true);
    }
}