#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

#include "common.h"

int file_count(char filename[MAX_FILE_NAME]) {
    FILE *fp;
    int count = 0;
    char c;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("could not open file %s\n", filename);
        return -1;
    }
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n')
            count = count + 1;

    fclose(fp);
    return count;
}

char *get_ip(char *type) {
    int fd;
    struct ifreq ifr;
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    ifr.ifr_addr.sa_family = AF_INET;
    strncpy(ifr.ifr_name, type, IFNAMSIZ-1);
    ioctl(fd, SIOCGIFADDR, &ifr);
    close(fd);
    char *ipv4 = inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr);
    return ipv4;
}