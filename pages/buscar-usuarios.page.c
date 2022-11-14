#include "../headers.h"
#include "../constantes.h"

void buscar_usuarios_page()
{
    system("clear");

    struct Buscar_usuarios_model model = buscar_usuarios_service();

    puts("\n\nlista de usuarios: \n");
    for (int i = 0; i < model.quantidade_usuarios; i++)
    {
        printf("user: %s\n", model.usuarios[i].usuario);
    }

    puts("\n");
    voltar();
}