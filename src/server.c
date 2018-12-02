#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
	printf("server here\n");

    FILE *html_data;
    html_data = fopen("./templates/index.html", "r");
    
}