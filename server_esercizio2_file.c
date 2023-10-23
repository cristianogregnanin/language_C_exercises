#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define dim 1024
#define port 40000
void Inverti(char buffer[])
{
    int len = strlen(buffer);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = buffer[i];
        buffer[i] = buffer[len - 1 - i];
        buffer[len - 1 - i] = temp;
    }
}
int main()
{
    int client_socket, server_socket;
    struct sockaddr_in client_addr, server_addr;
    char buffer[dim];
    socklen_t addr_size;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0)
    {
        printf("errore\n");
        exit(1);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("errore di binding\n");
        exit(1);
    }
    for (;;)
    {
        if (listen(server_socket, 10) == 0)
        {
            printf("In attesa di connessioni...\n");
        }
        else
        {
            printf("Errore durante l'ascolto delle connessioni.\n");
        }
        addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);
        recv(client_socket, buffer, 1024, 0);
        printf("stringa ricevuta\n");
        Inverti(buffer);
        send(client_socket, buffer, strlen(buffer), 0);
        close(client_socket);
    }
    close(server_socket);
    return 0; 
}