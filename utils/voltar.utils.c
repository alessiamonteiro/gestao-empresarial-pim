#include "../headers.h"
#include "../constantes.h"

void voltar() {
    char voltar;
    puts(TEXTO_VOLTAR);
    while ((voltar = getc(stdin)) == '\n')
        ;
    home_page(false);
}