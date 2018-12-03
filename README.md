# HTTP Server
A simple HTTP server in C.

## Building
 * To build everything: `make`
 * To build just the binaries: `make sockets`<hr>
 * To build just the client binary: `make client`
 * To build just the server binary: `make server`<hr>
 * To build the client: `make -f build.mk EXEC=client`
 * To build the server: `make -f build.mk EXEC=server`

## Syntax
 * To run the server: `./server.out <port>`
 * To run the client: `./client.out <ip> <port>`