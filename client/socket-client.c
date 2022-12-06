#include <unistd.h>
#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <strings.h> // bzero()
#include <sys/socket.h>

#include "../headers.h"

#define MAX 1024
#define PORT 8080
#define SA struct sockaddr

void socket_client(char requisicao[], char resposta[])
{
  int sock;
  struct sockaddr_in server_addr;
  char buffer[1024];

  sock = socket(AF_INET, SOCK_STREAM, 0);

  if (sock == -1)
  {
    printf("socket creation failed...\n");
    exit(0);
  }
  else
    bzero(&server_addr, sizeof(server_addr));

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  if (connect(sock, (SA *)&server_addr, sizeof(server_addr)) != 0)
  {
    printf("connection with the server failed...\n");
    exit(0);
  }

  bzero(buffer, MAX);
  strcpy(buffer, requisicao);

  send(sock, buffer, strlen(buffer), 0);

  bzero(buffer, MAX);
  recv(sock, buffer, sizeof(buffer), 0);

  close(sock);

  strcpy(resposta, buffer);
}