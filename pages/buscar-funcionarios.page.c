#include "../headers.h"
#include "../constantes.h"

void buscar_funcionarios_page() {
    system("clear");

    struct Buscar_cargos_model cargos = buscar_cargos_repository();
    struct Buscar_funcionarios_model model = buscar_funcionarios_service();

    puts("\n\nlista de funcionarios: \n");

    // formatar cpf
    for (int i = 0; i < model.quantidade_funcionarios; i++)
    {
        char cpf_formatado[16] = "";
        formatar_cpf(model.funcionarios[i].cpf, cpf_formatado);

        printf(" id: %i\n nome: %s\n cpf: %s\n cargo: %s\n salario: R$ %.2f\n possuiFerias: %i\n estaDeFerias: %i\n\n",
               model.funcionarios[i].id,
               model.funcionarios[i].nome,
               cpf_formatado,
               encontrar_cargo(model.funcionarios[i].cargo, cargos),
               model.funcionarios[i].salario,
               model.funcionarios[i].possui_ferias,
               model.funcionarios[i].esta_de_ferias       
        );
    }

    voltar_consultas_page();
}