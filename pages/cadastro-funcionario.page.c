#include "../headers.h"
#include "../constantes.h"

void cadastro_funcionario_page()
{
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

    struct Criar_funcionario_model criar_funcionario_model = criar_funcionario_service(funcionario);
    puts(criar_funcionario_model.mensagem);
}