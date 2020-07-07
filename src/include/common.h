#ifndef WOMBUG_COMMON_H
#define WOMBUG_COMMON_H

enum {
    PROGRAM_STATE_HELP,
    PROGRAM_STATE_DEBUG,
    PROGRAM_STATE_INFO
};

/**
 * Parse given arguments
 * @param argc argument count
 * @param argv arguments
 * @return program state
 */
int common_parse_args(int argc, char *argv[]);

#endif //WOMBUG_COMMON_H
