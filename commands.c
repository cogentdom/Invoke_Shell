#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "smash.h"

int execute_command(char * cmd) {
    if (cmd == "cd") {
        chg_dir();
    } else if(cmd == "history") {
        history();
    } else if(cmd == "exit") {
        exit();
    }
    return 0;
}

void exit() {
    
}