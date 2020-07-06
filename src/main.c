#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <windows.h>

#include "file.h"

_Bool usage(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    if (!usage(argc, argv)) {
        fprintf(stdout, "Please provide exactly one executable to start debugging.\nUsage: wombug executable.exe");
        return -1;
    }

    if (!check_file_exists(argv[1])) {
        fprintf(stdout, "File `%s` does not exist.\nUsage: wombug executable.exe", argv[1]);
        return -1;
    }

    if(!check_file_pe_elf(argv[1])) {
        fprintf(stdout, "File `%s` is not a valid executable.\nUsage: wombug executable.exe", argv[1]);
        return -1;
    }
    return 0;
}

_Bool usage(int argc, char *argv[]) {
    return argc == 2;
}
