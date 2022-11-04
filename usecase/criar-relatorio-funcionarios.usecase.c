#include "../headers.h"

struct Criar_relatorio_model criar_relatorio_funcionarios_usecase() {
    struct Buscar_cargos_model buscar_cargos_model = buscar_cargos_repository();
    
    struct Buscar_funcionarios_model buscar_funcionarios_model = buscar_funcionarios_repository();

    return criar_relatorio_funcionarios_repository(buscar_funcionarios_model, buscar_cargos_model);
}