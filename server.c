#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
// aqui deve ter algum include desnecessario
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
    printf("socket creation failed...\n");
    exit(0);
  }
  else
    printf("Socket successfully created..\n");

  bzero(&server_addr, sizeof(server_addr));
  // memset(&server_addr, '\0', sizeof(server_addr));

  // assign IP, PORT
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  // Binding newly created socket to given IP and verification
  if ((bind(server_sock, (SA *)&server_addr, sizeof(server_addr))) != 0)
  {
    printf("socket bind failed...\n");
    exit(0);
  }
  else
    printf("Socket successfully binded..\n");

  // Now server is ready to listen and verification
  if ((listen(server_sock, 5)) != 0)
  {
    printf("Listen failed...\n");
    exit(0);
  }
  else
    printf("Server listening..\n");

  while (1)
  {
    addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (SA *)&client_addr, &addr_size);

    if (client_sock < 0)
    {
      printf("server accept failed...\n");
      exit(0);
    }
    else
      printf("server accept the client...\n");

    bzero(buffer, MAX);
    recv(client_sock, buffer, sizeof(buffer), 0);
    printf("Client: %s\n", buffer);

    if (strcmp(buffer, "GET/usuarios") == 0)
    {
      bzero(buffer, MAX);
      buscar_usuarios_controller(buffer);
    }

    char *rota_login = strstr(buffer, "GET/login");

    if (rota_login)
    {
      int coluna = 1;
      int deve_adicionar = 0;
      char usuario[21] = "";
      char senha[21] = "";
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
      
      puts(usuario);
      puts(senha);
      bzero(buffer, 1024);

      login_usuario_controller(usuario, senha, buffer);
    }

    char *rota_cadastro = strstr(buffer, "POST/usuario");

    if (rota_cadastro)
    {
      int coluna = 1;
      int deve_adicionar = 0;
      char usuario[21] = "";
      char senha[21] = "";
      puts("RECEBI O CADASTRO");
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
      
      puts(usuario);
      puts(senha);
      bzero(buffer, 1024);

      criar_usuario_controller(usuario, senha, buffer);
    }


    printf("Server: %s\n", buffer);
    send(client_sock, buffer, strlen(buffer), 0);

    close(client_sock);
    printf("[+]Client disconnected.\n\n");
  }

  return 0;
}