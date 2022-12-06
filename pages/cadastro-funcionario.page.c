#include "../headers.h"
#include "../constantes.h"

void cadastro_funcionario_page(int erro, char mensagem[200])
{
    system("clear");
    struct Funcionario funcionario = {};
    funcionario.id = 0;

    struct Buscar_cargos_model buscar_cargos = buscar_cargos_repository();

    puts(TEXTO_TITULO_CADASTRO_FUNCIONARIO);

    if (erro == 1)
    {
        puts("\n-------------- ATENÇÃO --------------- \n");
        puts(mensagem);
        puts("\n");
    }

    // adicionar validacoes necessarias aos campos
   
    puts("\nNome completo:\n");
    scanf(" %[^\n]s", funcionario.nome);
    
    puts("\n\n CPF (Apenas números):");
    scanf("%s", funcionario.cpf);

    puts("\n\n RG (Apenas números):");
    scanf("%s", funcionario.rg);

    puts("\n\n Cargo (número correspondente):");

    for (int i = 0; i < buscar_cargos.quantidade_cargos; i++)
    {   
        printf("\n   %i - %s", buscar_cargos.cargos[i].id, buscar_cargos.cargos[i].cargo);
    }

    puts("\n");
    
    scanf("%d", &funcionario.cargo);

    puts("\n\n Salario (Apenas números):");
    scanf("%f", &funcionario.salario);

    struct Criar_funcionario_model criar_funcionario_model = criar_funcionario_service(funcionario);

    if (criar_funcionario_model.erro == true)
        return cadastro_funcionario_page(1, criar_funcionario_model.mensagem);
        
    puts(criar_funcionario_model.mensagem);
    system("sleep 03");
    system("clear");

    home_page(false);
}