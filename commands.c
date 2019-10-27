#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "smash.h"
#include "history.h"

void init_commands(Shell *sh_ptr) {
    // Cmd history_log = init_hist();
    sh_ptr->arr[0] = NULL;
    sh_ptr->command = NULL;
    sh_ptr->stack[0] = NULL;
    // int exit_status;
    // int count = 0;
    // sh_ptr->Log = malloc(sizeof(Hist));
    // history_log;
}

int chg_dir(char *p) {
    FILE *file = fopen(p, "a+");
    if (file == NULL) {
        fprintf(stderr, "%s: No such file or directory", p);
        return 1;
    } else {
        printf("%s\n", p);
    }
}

void exit_shell(void) {

}

void executeCommand(Shell *sh_ptr) {
    Cmd *cmd_ptr = malloc(sizeof(Cmd));
    cmd_ptr->index = &Index;
    // Index++;
    cmd_ptr->cmd = strcat(sh_ptr->arr[0], sh_ptr->arr[1]);
    int ext=0;
    cmd_ptr->exit_status = &ext;
    
    // extern char **arr;
    // char *arr[NUMBER_OF_ARGUMENTS];
    // arr[0] = p[0];
    
   
    if (!strcmp(sh_ptr->arr[0], "cd")) {
        if ((int)sizeof(sh_ptr->arr) > 2) {
            sh_ptr->arr[1] = add_history(cmd_ptr);
            fprintf(stderr, "Invalid syntax for cd");
        } else {
            chg_dir(sh_ptr->arr[1]);
        }
       
    } else if(!strcmp(sh_ptr->arr[0], "history")) {
        
        // history();
    } else if(!strcmp(sh_ptr->arr[0], "exit")) {
        exit_shell();
    }
    
}

