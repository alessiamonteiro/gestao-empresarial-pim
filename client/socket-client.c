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

  // socket create and verification
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1)
  {
    printf("socket creation failed...\n");
    exit(0);
  }
  else
    // printf("Socket successfully created..\n");

    // memset(&addr, '\0', sizeof(addr));
    bzero(&server_addr, sizeof(server_addr));

  // assign IP, PORT
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // connect the client socket to server socket
  if (connect(sock, (SA *)&server_addr, sizeof(server_addr)) != 0)
  {
    printf("connection with the server failed...\n");
    exit(0);
  }
  else
  {
    // printf("connected to the server..\n");
  }

  // printf("Connected to the server.\n");

  bzero(buffer, MAX);
  strcpy(buffer, requisicao);
  // printf("Client: %s\n", buffer);
  send(sock, buffer, strlen(buffer), 0);

  bzero(buffer, MAX);
  recv(sock, buffer, sizeof(buffer), 0);
  // printf("Server: %s\n", buffer);

  close(sock);
  // printf("Disconnected from the server.\n");

  strcpy(resposta, buffer);
}