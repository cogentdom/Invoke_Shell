#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "commands.h"

void execute_command(char * cmd) {
    if (cmd == "cd") {
        chg_dir();
    } else if(cmd == "history") {
        history();
    } else if(cmd == "exit") {
        exit();
    } 
}

void exit() {
    
}