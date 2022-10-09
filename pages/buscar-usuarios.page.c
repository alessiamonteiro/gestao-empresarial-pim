#include "../headers.h"
#include "../constantes.h"

void buscar_usuarios_page() {
    system("clear");

    struct Buscar_usuarios_model model = buscar_usuarios_service();

    puts("\n\nlista de usuarios: \n");
    for (int i = 0; i < model.quantidade_usuarios; i++)
    {
        printf("id: %s, usuario: %s, senha: %s \n",
               model.usuarios[i].id,
               model.usuarios[i].usuario,
               model.usuarios[i].senha);
    }

    int acao;
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