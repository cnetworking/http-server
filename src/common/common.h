#ifndef COMMON_H
#define COMMON_H

#define MAX_FILE_NAME 16
#define BODY_SIZE 2048
#define HEADER_SIZE 2176 

// Count the amount of lines in a file
int file_count(char filename[MAX_FILE_NAME]);

// Get a local ip address
char *get_ip(char *type);

#endif