#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "debug.h"

void debug_start(char file_name[]) {
    if (!file_exists(file_name)) {
        fprintf(stderr, "wombug: file `%s` does not exist.\n", file_name);
        exit(-1);
    }

    if (!file_is_executable(file_name)) {
        fprintf(stderr, "wombug: file `%s` is not a valid executable.", file_name);
        exit(-1);
    }
}