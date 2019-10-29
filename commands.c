#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "smash.h"
#include "history.h"

#define STACK_INDEX_POS 0

void init_shell(Shell *sh_ptr) {
    sh_ptr->arr[0] = NULL;
    sh_ptr->stack[0] = NULL;
}

void chg_dir(char *p);

void exit_shell(void);

void executeCommand(Shell *sh_ptr) {
    Cmd *cmd_ptr = malloc(sizeof(Cmd));
    if (sh_ptr->stack_ptr == 9) {
        sh_ptr->stack_ptr = 0;
    } else {
        // sh_ptr->stack_ptr++;
    }
    
    int val = sh_ptr->stack_ptr;
    printf("Val = %d\n", val);
    printf("Added command:  $ %s\n", sh_ptr->stack[sh_ptr->stack_ptr]);
    // cmd_ptr->cmd = command;
    
    cmd_ptr->exit_status = 0;
    
    
   
    if (!strcmp(sh_ptr->arr[0], "cd")) {
        if (sh_ptr->count > 2) {
            // sh_ptr->arr[1] = add_history(cmd_ptr);
            fprintf(stderr, "Invalid syntax for cd\n");
        } else {
            // chg_dir(sh_ptr->arr[1]);
        }
       
    } else if(!strcmp(sh_ptr->arr[0], "history")) {
        
        print_history(sh_ptr);
    } else if(!strcmp(sh_ptr->arr[0], "exit")) {
        exit_shell();
    }
    
}

void chg_dir(char *p) {
    FILE *file = fopen(p, "a+");
    if (file == NULL) {
        fprintf(stderr, "%s: No such file or directory", p);
        // return 1;
    } else {
        printf("%s\n", p);
    }
}

void exit_shell(void) {

}