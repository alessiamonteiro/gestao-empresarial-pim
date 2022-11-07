#include "../headers.h"
#include "../constantes.h"

void perfil_page()
{
    char voltar;
    system("clear");
    printf("usuario: %s\n", usuario_logado);

    puts(TEXTO_VOLTAR);
    while ((voltar = getc(stdin)) == '\n')
        ;
    home_page(false);
}