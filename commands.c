#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "smash.h"
#include "history.h"


void init_shell(Shell *sh_ptr) {
    init_history(sh_ptr);
    sh_ptr->env = getenv(ENVIORMENT);
    if (sh_ptr->env != NULL) {
        printf("path: %s\n", sh_ptr->env);
        // putenv(sh_ptr->env);
    }
}



void chg_dir(char *p);

void exit_shell(void) {
    Exit = 1;
}

void executeCommand(Shell *sh_ptr) {
    
   
    if (!strcmp(sh_ptr->arr[0], "cd")) {

        if (sh_ptr->arr_size == 2) {
            int complete = chdir(sh_ptr->arr[1]);
            if (complete == 0) {
                char* cur_dir = getcwd(NULL, MAXLINE);
                printf("%s\n", cur_dir);
            } else {
                fprintf(stderr, "no such directory\n");
            }
        }
        
       
    } else if(!strcmp(sh_ptr->arr[0], "history")) {
        
        print_history(sh_ptr);
    } else if(!strcmp(sh_ptr->arr[0], "exit")) {
        exit_shell();
    }
    sh_ptr->exit_stack[sh_ptr->stack_ptr] = &sh_ptr->exit_status;
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
