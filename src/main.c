#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <sys/stat.h>


typedef void (*CommandFunctionPointer)();

typedef struct {
    char *keys[2];
    CommandFunctionPointer call;
} Command;

void quit() {
    exit(EXIT_SUCCESS);
}

void usage() {
    puts("usage");
    exit(EXIT_SUCCESS);
}

void version() {
    puts("version");
    exit(EXIT_SUCCESS);
}

void file_does_not_exist() {
    puts("file doesnt exist");
    exit(EXIT_FAILURE);
}


bool file_exists(char *filename) {
    struct stat buffer;

    int exists = stat(filename, &buffer) == 0;
    return exists && S_ISREG(buffer.st_mode);
}

int main(int argc, char *argv[]) {

    if(argc != 2) { usage(argv[0]); }
    if(!strcmp(argv[1], "--version")) { version(argv[0]); }
    if(!file_exists(argv[1])) { file_does_not_exist(argv[0]); }

    char command[60];

    Command commands[] = {
        {{"quit", "q"}, quit}, 
    };

    while(true) {
        fgets(command, sizeof command, stdin);

        command[strlen(command) - 1] = '\0';


        for (size_t i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
            Command c = commands[i];
            if (!strcmp(c.keys[0], command) || !strcmp(c.keys[1], command)) {
                c.call();
            }
        }
    }
}
