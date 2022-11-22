#include "../headers.h"
#include "../constantes.h"

void voltar_home_page() {
    char voltar;
    puts(TEXTO_VOLTAR);
    while ((voltar = getc(stdin)) == '\n')
        ;
    home_page(false);
}

void voltar_consultas_page() {
    char voltar;
    puts(TEXTO_VOLTAR);
    while ((voltar = getc(stdin)) == '\n')
        ;
    consultas_page(false);
}