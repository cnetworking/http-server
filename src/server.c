#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>

#include "http_server.h"

int main(int argc, char *argv[]) {
	printf("server here\n");

    FILE *html_data;
    html_data = fopen("./static/index.html", "r");
    printf("len: %d\n", file_count("./static/index.html"));
    printf("len: %d\n", file_count("client.c"));

}