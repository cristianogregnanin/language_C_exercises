#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define dim 1024
#define port 40000
int Conta_carattere(char buffer[],char carattere)
{
    int len=strlen(buffer);
    int cont=0;
    for (int i = 0; i < len; i++)
		{
			if (buffer[i] == carattere)
				cont++;
		}
        return cont; 
}
int main()
{
    int client_socket, server_socket;
    struct sockaddr_in server_addr,client_addr;
    char buffer[dim];
    int nread;
    char carattere;
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

        nread=read(client_socket,"%s",sizeof(buffer));
        printf("stringa ricevuta\n");
        nread=read(client_socket,"%s",sizeof(carattere));
        printf("carattere ricevuto\n");
        int risultato=Conta_carattere(buffer,carattere);
        snprintf(buffer, dim, "%d", risultato);
        send(client_socket,buffer,strlen(buffer),0);
        close(client_socket);

    }
    close(server_socket);
    return 0; 

}