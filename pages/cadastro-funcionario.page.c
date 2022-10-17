#include "../headers.h"
#include "../constantes.h"

void cadastro_funcionario_page()
{
    // inicializar default com o dia atual
    int dia_data_inicio = 0;
    int mes_data_inicio = 0;
    int ano_data_inicio = 0;

    time_t data_inicio_time;

    struct Funcionario funcionario = {};
    funcionario.id = 0;

    printf(TEXTO_TITULO_CADASTRO_FUNCIONARIO);

    // adicionar validacoes necessarias aos campos
    puts("\n\n Nome completo:");
    scanf("%[^\n]", funcionario.nome);

    puts("\n\n CPF:");
    scanf("%s", funcionario.cpf);

    puts("\n\n RG:");
    scanf("%s", funcionario.rg);

    puts("\n\n Cargo:");
    scanf("%d", &funcionario.cargo);

    puts("\n\n Salario:");
    scanf("%d", &funcionario.salario);

    puts("\n\nData de inicio do funcionario na empresa");
    puts("\n\nDigite o dia: ");
    scanf("%d", &dia_data_inicio);

    puts("\n\nDigite o mes: ");
    scanf("%d", &mes_data_inicio);

    puts("\n\nDigite o ano: ");
    scanf("%d", &ano_data_inicio);

    data_inicio_time = create_time(dia_data_inicio, mes_data_inicio, ano_data_inicio);
    funcionario.data_inicio = data_inicio_time;
    funcionario.data_inicio_contagem_ferias = data_inicio_time;
    funcionario.validade_ferias = data_inicio_time;

    struct Criar_funcionario_model criar_funcionario_model = criar_funcionario_service(funcionario);
    puts(criar_funcionario_model.mensagem);
}