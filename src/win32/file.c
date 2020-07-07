#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "file.h"

_Bool file_is_executable(const char *name) {
    // Open file
    FILE *fp = fopen(name, "r");

    if (fp == NULL) {
        fprintf(stderr, "Error opening file while trying to validate it as PE file.");
        return false;
    }

    // Validate file as PE file, check first two bytes for "MZ"
    int maxBytes = 2;
    char buffer[maxBytes];
    char c;
    int count = 0;
    while( (c = fgetc(fp)) != EOF && count < maxBytes) {
        buffer[count] = c;

        count++;
    }

    // Close file
    fclose(fp);

    return !strcmp(buffer, "MZ");
}