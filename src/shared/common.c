#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include "common.h"

int common_parse_args(int argc, char *argv[]) {
    // set error state
    int state = -1;

    // check max arguments
    if(argc != 3) {
        return state;
    }

    // check for available options
    // h = help
    // i = info
    // d = debug
    if (!strcmp(argv[1], "-h")) {
        state = PROGRAM_STATE_HELP;
    } else if(!strcmp(argv[1], "-i")) {
        state = PROGRAM_STATE_INFO;
    } else if(!strcmp(argv[1], "-d")) {
        state = PROGRAM_STATE_DEBUG;
    }

    return state;
}