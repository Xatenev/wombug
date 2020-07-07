#include <stdio.h>

#include "help.h"

void help_start() {
    puts("Usage: wombug [options...] [filename]\n"
         "-h Show this help text\n"
         "-i Show information about a binary\n"
         "-d Start debugging a binary");
}