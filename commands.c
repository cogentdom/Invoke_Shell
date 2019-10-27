#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "smash.h"




void executeCommand(Cmd *ptr) {
    
    // extern char **arr;
    // char *arr[NUMBER_OF_ARGUMENTS];
    // arr[0] = p[0];
    printf("Enter Succesfully: %s\n", ptr->arr[0]);
   
    if (!strcmp(ptr->arr[0], "cd")) {
        
        
        // chg_dir();
    } else if(!strcmp(ptr->arr[0], "history")) {
        // history();
    } else if(!strcmp(ptr->arr[0], "exit")) {
        // exit();
    }
    
}
