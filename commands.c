#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "smash.h"
#include "history.h"

void init_shell(Shell *sh_ptr) {
    sh_ptr->arr[0] = NULL;
    sh_ptr->stack[0] = NULL;
    Exit = 0;
}

void chg_dir(char *p);

void exit_shell(void) {
    Exit = 1;
}

void executeCommand(Shell *sh_ptr) {
    
   
    if (!strcmp(sh_ptr->arr[0], "cd")) {
        
       
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
