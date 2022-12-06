#include "../headers.h"

const char *encontrar_cargo(int id, struct Buscar_cargos_model model)
{
    for (int i = 0; i < model.quantidade_cargos; i++)
    {
        if (model.cargos[i].id == id)
        {
            char *cargo = model.cargos[i].cargo;
            return cargo;
        }
    }

    return "Cargo não encontrado";
}