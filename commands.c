#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "smash.h"

void executeCommand(char *cmd[]) {
    if (!strcmp(cmd[1], "cd")) {
        // chg_dir();
    } else if(!strcmp(cmd[1], "history")) {
        // history();
    } else if(!strcmp(cmd[1], "exit")) {
        // exit();
    }
    
}
