#include "../headers.h"
#include "../constantes.h"

void cadastro_funcionario_page()
{
    struct Funcionario funcionario = {};
    funcionario.id = 0;

    puts(TEXTO_TITULO_CADASTRO_FUNCIONARIO);

    // adicionar validacoes necessarias aos campos
   
    puts("\nNome completo:\n");
    scanf(" %[^\n]s", funcionario.nome);
    
    puts("\n\n CPF:");
    scanf("%s", funcionario.cpf);

    puts("\n\n RG:");
    scanf("%s", funcionario.rg);

    puts("\n\n Cargo:");
    scanf("%d", &funcionario.cargo);

    puts("\n\n Salario:");
    scanf("%le", &funcionario.salario);

    struct Criar_funcionario_model criar_funcionario_model = criar_funcionario_service(funcionario);
    puts(criar_funcionario_model.mensagem);
    system("sleep 03");
    system("clear");

    if (criar_funcionario_model.erro == true) {
        cadastro_funcionario_page();
        return;
    }

    home_page();
}