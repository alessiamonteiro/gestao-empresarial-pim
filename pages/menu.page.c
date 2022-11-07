#include "../headers.h"
#include "../constantes.h"

void menu_page(int erro)
{
    char acao;
    system("clear");
    puts(TEXTO_TITULO_MENU);
    puts(TEXTO_OPCOES_MENU);

    if (erro == true) {
        puts(TEXTO_OPCAO_INVALIDA);
    }

    scanf("\n%c", &acao);

    switch (acao)
    {
    case '1':
        login_page();
        break;

    case '2':
        cadastro_page(0);
        break;

    default:
        menu_page(true);
        break;
    }
}