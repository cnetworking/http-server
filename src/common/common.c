#include <stdio.h>
#include "common.h"

int file_count(char filename[MAX_FILE_NAME]) {
    FILE *fp;
    int count = 0;
    char c;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("could not open file %s", filename);
        return -1;
    }
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n')
            count = count + 1;

    fclose(fp);
    return count;
}