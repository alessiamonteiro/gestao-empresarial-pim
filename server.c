// NOTE aqui deve ter algum include desnecessario
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
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

  server_sock = socket(AF_INET, SOCK_STREAM, 0);

  if (server_sock == -1)
  {
    printf("[ERRO] criar socket\n");
    exit(0);
  }

  printf("[OK] criar socket\n");

  bzero(&server_addr, sizeof(server_addr));

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  // Binding newly created socket to given IP and verification
  if ((bind(server_sock, (SA *)&server_addr, sizeof(server_addr))) != 0)
  {
    printf("[ERRO] bind servidor\n");
    exit(0);
  }
  
  printf("[OK] bind servidor\n");

  // Now server is ready to listen and verification
  if ((listen(server_sock, 5)) != 0)
  {
    printf("[ERRO] servidor ouvir\n");
    exit(0);
  }
  
  printf("[OK] servidor ouvir\n");

  while (1)
  {
    addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (SA *)&client_addr, &addr_size);

    if (client_sock < 0)
    {
      printf("[ERRO] servidor aceitar cliente\n");
      exit(0);
    }

    printf("[OK] servidor aceitar cliente\n");

    bzero(buffer, MAX);
    recv(client_sock, buffer, sizeof(buffer), 0);
    printf("Cliente: %s\n", buffer);

    router(buffer);

    printf("Servidor: %s\n", buffer);
    send(client_sock, buffer, strlen(buffer), 0);

    close(client_sock);
    printf("[+]Cliente desconectado.\n\n");
  }

  return 0;
}