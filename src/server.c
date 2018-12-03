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
    char response_data[1024];
    fgets(response_data, sizeof(response_data), html_data);

    // Initialize the http header
    char http_header[2048] = "HTTP/1.0 200 OK\r\n\n";
    strcat(http_header, response_data);

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
    printf("awaiting connections\n");
    listen(server_socket, MAX_CLIENTS);

    return 0;
}