#include "../headers.h"
#include "../constantes.h"

void home_page(bool erro)
{
    char acao;
    system("clear");

    puts(TEXTO_TITULO_HOME);
    puts(TEXTO_OPCOES_HOME);

    if (erro == true) {
        putchar(acao);
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
        criar_relatorio_funcionarios_service();
        system("./abrir-relatorios.sh");
        scanf("%c", &acao);
        home_page(false);
        break;

    case '6':
        menu_page(false);
        break;

    default:
        home_page(true);
        break;
    }
}