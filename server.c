// NOTE aqui deve ter algum include desnecessario
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdbool.h>
// NOTE aqui deve ter algum include desnecessario
#include "./headers.h"

#define MAX 1024
#define PORT 8080
#define SA struct sockaddr

int main()
{
  int server_sock, client_sock, addr_size;
  struct sockaddr_in server_addr, client_addr;
  char buffer[1024];

  // socket create and verification
  server_sock = socket(AF_INET, SOCK_STREAM, 0);

  if (server_sock == -1)
  {
    printf("[ERROR] socket create\n");
    exit(0);
  }

  printf("[OK] socket create\n");

  bzero(&server_addr, sizeof(server_addr));
  // memset(&server_addr, '\0', sizeof(server_addr));

  // assign IP, PORT
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  // Binding newly created socket to given IP and verification
  if ((bind(server_sock, (SA *)&server_addr, sizeof(server_addr))) != 0)
  {
    printf("[ERROR] server bind\n");
    exit(0);
  }
  
  printf("[OK] server bind\n");

  // Now server is ready to listen and verification
  if ((listen(server_sock, 5)) != 0)
  {
    printf("[ERROR] server listen\n");
    exit(0);
  }
  
  printf("[OK] server listen\n");

  while (1)
  {
    addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (SA *)&client_addr, &addr_size);

    if (client_sock < 0)
    {
      printf("[ERROR] server accept client\n");
      exit(0);
    }

    printf("[OK] server accept client\n");

    bzero(buffer, MAX);
    recv(client_sock, buffer, sizeof(buffer), 0);
    printf("Client: %s\n", buffer);

    // sistema de roteamento
    char *rota_login = strstr(buffer, "GET/login");
    char *rota_cadastro = strstr(buffer, "POST/usuarios");
    bool rota_buscar_usuarios = strcmp(buffer, "GET/usuarios") == 0;

    if (rota_buscar_usuarios)
    {
      buscar_usuarios_controller(buffer);
    }

    if (rota_login)
    {
      login_usuario_controller(buffer);
    }

    if (rota_cadastro)
    {
      criar_usuario_controller(buffer);
    }
    // fim do sistema de roteamento

    printf("Server: %s\n", buffer);
    send(client_sock, buffer, strlen(buffer), 0);

    close(client_sock);
    printf("[+]Client disconnected.\n\n");
  }

  return 0;
}