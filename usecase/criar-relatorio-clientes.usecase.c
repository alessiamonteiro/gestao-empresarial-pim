#include "../headers.h"

struct Criar_relatorio_model criar_relatorio_clientes_usecase() {   
    struct Buscar_clientes_model model = buscar_clientes_repository();
    return criar_relatorio_clientes_repository(model);
}