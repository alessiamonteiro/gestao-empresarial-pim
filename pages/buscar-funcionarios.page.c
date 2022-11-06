#include "../headers.h"
#include "../constantes.h"

void buscar_funcionarios_page() {
    system("clear");

    char voltar;

    struct Buscar_funcionarios_model model = buscar_funcionarios_service();

    puts("\n\nlista de funcionarios: \n");

    // formatar cpf
    for (int i = 0; i < model.quantidade_funcionarios; i++)
    {
        printf(" id: %i\n nome: %s\n cpf: %s\n cargo: %i\n salario: R$ %.2f\n possuiFerias: %i\n estaDeFerias: %i\n\n\n",
               model.funcionarios[i].id,
               model.funcionarios[i].nome,
               model.funcionarios[i].cpf,
               model.funcionarios[i].cargo,
               model.funcionarios[i].salario,
               model.funcionarios[i].possui_ferias,
               model.funcionarios[i].esta_de_ferias       
        );
    }

    puts(TEXTO_VOLTAR);
    while ((voltar = getc(stdin)) == '\n')
        ;
    home_page(false);
}