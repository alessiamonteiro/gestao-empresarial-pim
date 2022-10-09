#include "../headers.h"
#include "../constantes.h"

void perfil_page() {
    int acao;
    system("clear");
    printf("usuario: %s\n", usuario_logado);
    printf("senha: %s\n", senha_usuario_logado);

    puts("Digite 1 para voltar para a home");
    scanf("%i", &acao);

    switch (acao)
    {
    case 1:
        home_page();
        break;

    default:
        puts(TEXTO_OPCAO_INVALIDA);
        menu_page();
        break;
    }
}