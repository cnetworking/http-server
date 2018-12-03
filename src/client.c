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
    int port;
    char *ip;
    if (argc < 3 || argc > 3 || to_int(argv[2]) <= 0) {
        printf("syntax: ./client.out <ip> <port>\n");
        exit(-1);
    } else {
        port = to_int(argv[2]);
        ip = argv[1];
    }

    clientbox(ip, port);
}