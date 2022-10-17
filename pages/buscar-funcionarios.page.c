#include "../headers.h"
#include "../constantes.h"

void buscar_funcionarios_page() {
    system("clear");

    int acao;

    struct Buscar_funcionarios_model model = buscar_funcionarios_service();

    puts("\n\nlista de funcionarios: \n");

    for (int i = 0; i < model.quantidade_funcionarios; i++)
    {
        printf(" id: %i\n nome: %s\n cpf: %s\n cargo: %i\n salario: %i\n possuiFerias: %i\n estaDeFerias: %i\n dataInicio: %s\n dataInicioContagemFerias: %s\n validadeFerias: %s\n\n\n",
               model.funcionarios[i].id,
               model.funcionarios[i].nome,
               model.funcionarios[i].cpf,
               model.funcionarios[i].cargo,
               model.funcionarios[i].salario,
               model.funcionarios[i].possui_ferias,
               model.funcionarios[i].esta_de_ferias,
               time_to_string(model.funcionarios[i].data_inicio),
               time_to_string(model.funcionarios[i].data_inicio_contagem_ferias),
               time_to_string(model.funcionarios[i].validade_ferias)       
        );
    }

    puts("\n\nDigite 1 para voltar para a home");
    scanf("%i", &acao);

    switch (acao)
    {
    case 1:
        home_page();
        break;

    default:
        home_page();
        // puts(TEXTO_OPCAO_INVALIDA);
        // menu();
        break;
    }
}