#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "./headers.h"

int main()
{
  char *ip = "127.0.0.1";
  int port = 5566;

  int server_sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_size;
  char buffer[1024];
  int n;
  char status_resposta[10];

  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0)
  {
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP server socket created.\n");

  memset(&server_addr, '\0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip);

  n = bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (n < 0)
  {
    perror("[-]Bind error");
    exit(1);
  }
  printf("[+]Bind to the port number: %d\n", port);

  listen(server_sock, 5);
  printf("Listening...\n");

  while (1)
  {
    addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_size);
    printf("[+]Client connected.\n");

    bzero(buffer, 1024);
    recv(client_sock, buffer, sizeof(buffer), 0);
    printf("Client: %s\n", buffer);

    if (strcmp(buffer, "GET/usuarios") == 0)
    {
      bzero(buffer, 1024);
       buscar_usuarios_controller(buffer);
    }

    char * rota_login = strstr(buffer, "GET/login");

    if (rota_login) {
      int coluna = 1;
      int deve_adicionar = 0;
      char usuario[21] = "";
      char senha[21] = "";
      puts("RECEBI O LOGINS");
      puts(buffer);

      for (int i = 0; i < strlen(buffer); i++)
      {
        if (buffer[i] == '&') {
          deve_adicionar = 0;
          coluna +=1;
        }

        if (buffer[i] == '=') {
          deve_adicionar = 1;
          continue;
        }

        if (deve_adicionar == 1 && coluna == 1) {
          strncat(usuario, &buffer[i], 1);
        }

        if (deve_adicionar == 1 && coluna == 2) {
          strncat(senha, &buffer[i], 1);
        }
      }
      puts(usuario);
      puts(senha);
      bzero(buffer, 1024);
      
      login_usuario_controller(usuario, senha, buffer);
    }

    printf("Server: %s\n", buffer);
    send(client_sock, buffer, strlen(buffer), 0);

    close(client_sock);
    printf("[+]Client disconnected.\n\n");
  }

  return 0;
}