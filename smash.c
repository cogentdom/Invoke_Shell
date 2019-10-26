#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "smash.h"
#include "commands.h"

read(void){

}

void loop(void) {
    char * line;
    char ** args;
    int status;

    do {
        printf("Hello\n");
        line = read();

        args = parse(line);
        status = execute(args);

        free(line);
        free(args);
    } while (status);
    
}

int main(void) {

    loop();
    return 0;
}