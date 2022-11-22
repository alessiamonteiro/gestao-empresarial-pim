#include "../headers.h"
#include "../constantes.h"

void consultas_page(int erro)
{
    char acao;
    system("clear");
    puts(TEXTO_TITULO_CONSULTAS);
    puts(TEXTO_OPCOES_CONSULTAS);

    if (erro == true)
        puts(TEXTO_OPCAO_INVALIDA);

    scanf("\n%c", &acao);

    switch (acao)
    {
    case '1':
        return buscar_usuarios_page();

    case '2':
        return buscar_funcionarios_page();

    case '3':
        return buscar_clientes_page();

    case '4':
        return home_page(false);
        
    default:
        consultas_page(true);
    }
}
