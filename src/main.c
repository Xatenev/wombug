#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <windows.h>

#include "common.h"
#include "file.h"

#include "help.h"
#include "debug.h"
#include "info.h"

int main(int argc, char *argv[]) {
    switch(common_parse_args(argc, argv)) {
        case PROGRAM_STATE_HELP:
            help_start();
            break;
        case PROGRAM_STATE_DEBUG:
            debug_start(argv[2]);
            break;
        case PROGRAM_STATE_INFO:
            info_start(argv[2]);
            break;
        case -1:
            fprintf(stderr, "wombug: invalid arguments. See wombug -h for available commands.");
            return -1;
    }


    return 0;
}