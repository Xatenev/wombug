#include "file.h"

#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>

_Bool check_file_exists(const char *name) {
    struct stat buffer;

    return stat(name, &buffer) == 0;
}