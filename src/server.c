#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include "http_server.h"

int main(int argc, char *argv[]) {
    // Open the index.html file
    FILE *html_data;
    html_data = fopen("./src/static/index.html", "r");
    
    // Read from the file
    char response_body[BODY_SIZE];
    fgets(response_body, sizeof(response_body), html_data);

    // Initialize the http header
    char http_header[HEADER_SIZE] = "HTTP/1.0 200 OK\r\n\n";
    strcat(http_header, response_body);

    // Create the server socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    // Define the socket address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(3000);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the network
    bind(
      server_socket,
      (struct sockaddr *) &server_address,
      sizeof(server_address)
    );
    // Start listening to connections
    int client_count = 0;
    printf("awaiting connections\n");
    listen(server_socket, MAX_CLIENTS);

    // Accept connections from client sockets
    while (client_count < 5) {
        // Accept the connection
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            printf("unable to accept client\n");
        } else {
            send(client_socket, http_header, sizeof(http_header), 0);
            // Close the connection with the client
            close(client_socket);
            // memset(client_socket, 0, sizeof(client_socket));
        }
    }

    return 0;
}