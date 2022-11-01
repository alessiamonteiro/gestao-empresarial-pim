#include "../headers.h"
#include "../constantes.h"

void menu_page()
{
    int acao;
    system("clear");
    puts(TEXTO_BEM_VINDO);
    puts(TEXTO_OPCOES_MENU);
    scanf("%i", &acao);

    switch (acao)
    {
    case 1:
        login_page();
        break;

    case 2:
        cadastro_page();
        break;

    default:
        puts(TEXTO_OPCAO_INVALIDA);
        menu_page();
        break;
    }
}