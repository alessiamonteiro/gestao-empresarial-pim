#include "../headers.h"

void router(char buffer[1024])
{
  char *rota_login = strstr(buffer, "GET/login");
  char *rota_criar_usuario = strstr(buffer, "POST/usuarios");
  char *rota_criar_cliente = strstr(buffer, "POST/clientes");
  char *rota_criar_funcionario = strstr(buffer, "POST/funcionarios");
  char *rota_criar_relatorio_funcionarios = strstr(buffer, "POST/relatorios/funcionarios");
  bool rota_buscar_usuarios = strcmp(buffer, "GET/usuarios") == 0;
  bool rota_buscar_funcionarios = strcmp(buffer, "GET/funcionarios") == 0;

  if (rota_buscar_usuarios)
  {
    buscar_usuarios_controller(buffer);
  }

  if (rota_login)
  {
    login_usuario_controller(buffer);
  }

  if (rota_criar_usuario)
  {
    criar_usuario_controller(buffer);
  }

  if (rota_buscar_funcionarios)
  {
    buscar_funcionarios_controller(buffer);
  }

  if (rota_criar_funcionario)
  {
    criar_funcionario_controller(buffer);
  }

  if (rota_criar_relatorio_funcionarios)
  {
    criar_relatorio_funcionarios_controller(buffer);
  }

  if (rota_criar_cliente)
  {
    criar_cliente_controller(buffer);
  }
}