#include "../headers.h"

void mapear_response(char buffer[1024], struct Login_usuario_model model);

void login_usuario_controller(char buffer[1024])
{
  int coluna = 1;
  int deve_adicionar = 0;
  char usuario[22] = "";
  char senha[22] = "";

  // entrypoint log
  puts("RECEBI O LOGINS");
  puts(buffer);

  // obter parametros passados na mensagem
  for (int i = 0; i < strlen(buffer); i++)
  {
    if (buffer[i] == '&')
    {
      deve_adicionar = 0;
      coluna += 1;
    }

    if (buffer[i] == '=')
    {
      deve_adicionar = 1;
      continue;
    }

    if (deve_adicionar == 1 && coluna == 1)
    {
      strncat(usuario, &buffer[i], 1);
    }

    if (deve_adicionar == 1 && coluna == 2)
    {
      strncat(senha, &buffer[i], 1);
    }
  }

  // debug
  // puts(usuario);
  // puts(senha);

  bzero(buffer, 1024);

  struct Login_usuario_model model = login_usuario_usecase(usuario, senha);
  mapear_response(buffer, model);
}

void mapear_response(char buffer[1024], struct Login_usuario_model model)
{
  char erro[2];

  sprintf(erro, "%d", model.erro);
  strcat(buffer, erro);
  strcat(buffer, ";");

  strcat(buffer, model.mensagem);
  strcat(buffer, ";");

  strcat(buffer, model.login_usuario.usuario);
  strcat(buffer, ";");

  strcat(buffer, model.login_usuario.senha);
  strcat(buffer, ";");
}