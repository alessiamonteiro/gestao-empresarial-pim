#include "../headers.h"
#include "../constantes.h"

void menu_page(bool erro)
{
    char acao;
    system("clear");
    puts(TEXTO_BEM_VINDO);
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
        cadastro_page();
        break;

    default:
        menu_page(true);
        break;
    }
}