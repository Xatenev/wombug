#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <windows.h>

#include "file.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
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