#include "../headers.h"
#include "../constantes.h"

void home_page() {
    int acao;
    system("clear");
    printf(TEXTO_TITULO_HOME);
    puts(TEXTO_OPCOES_HOME);
    scanf("%i", &acao);

    switch (acao)
    {
    case 1:
        perfil_page();
        break;

    case 2:
        buscar_usuarios_page();
        break;

    case 3:
        buscar_funcionarios_page();
        break;

    case 4:
        menu_page();
        break;

    default:
        puts(TEXTO_OPCAO_INVALIDA);
        menu_page();
        break;
    }
}