#include "file.h"

#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>

_Bool file_exists(const char *name) {
    // Create storage buffer
    struct stat buffer;

    // Check if stat call is successful on given file name and return
    return stat(name, &buffer) == 0;
}