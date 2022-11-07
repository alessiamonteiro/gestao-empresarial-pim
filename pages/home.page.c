#include "../headers.h"
#include "../constantes.h"

void home_page(int erro)
{
    system("clear");
    char acao;

    puts(TEXTO_TITULO_HOME);
    puts(TEXTO_OPCOES_HOME);

    if (erro == true)
    {
        puts(TEXTO_OPCAO_INVALIDA);
    }

    scanf("\n%c", &acao);

    switch (acao)
    {
    case '1':
        perfil_page();
        break;

    case '2':
        buscar_usuarios_page();
        break;

    case '3':
        buscar_funcionarios_page();
        break;

    case '4':
        cadastro_funcionario_page();
        break;
    
    case '5':
        cadastro_cliente_page();
        break;

    case '6':
        relatorios_page(false);
        break;

    case '7':
        menu_page(false);
        break;

    default:
        home_page(true);
        break;
    }
}