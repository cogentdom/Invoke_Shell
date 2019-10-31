#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <dirent.h>
#include "smash.h"
#include "history.h"
#define EXIT_F 127


void init_shell(Shell *sh_ptr) {
    init_history(sh_ptr);
    sh_ptr->env = getenv(ENVIORMENT);
    if (sh_ptr->env != NULL) {
        printf("path: %s\n", sh_ptr->env);
        // putenv(sh_ptr->env);
    }
}


void exit_shell(void) {
    Exit = 1;
}

void executeCommand(Shell *sh_ptr) {
    
    if (!strcmp(sh_ptr->arr[0], "cd")) {
        if (sh_ptr->arr_size == 2) {
            int complete = chdir(sh_ptr->arr[1]);
            if (complete == 0) {
                char* cur_dir = getcwd(NULL, MAXLINE);
                sh_ptr->exit_stack[sh_ptr->stack_ptr] = EXIT_SUCCESS;
                printf("%s\n", cur_dir);
            } else {
                fprintf(stderr, "no such directory\n");
                sh_ptr->exit_stack[sh_ptr->stack_ptr] = EXIT_FAILURE;
            }
        } else if(sh_ptr->arr_size > 2) {
            fprintf(stderr, "no such command\n");
            sh_ptr->exit_stack[sh_ptr->stack_ptr] = EXIT_F;
        }
    } else if (!strcmp(sh_ptr->arr[0], "ls")) {
        if (sh_ptr->arr_size == 1) {
            DIR *mydir;
            struct dirent *dp;
            char cwd[MAXLINE];
            getcwd(cwd, sizeof(cwd));
            if((mydir  = opendir(cwd)) != NULL) {
                while ((dp=readdir(mydir)) != NULL) {
                    printf("%s\t", dp->d_name);
                }
                sh_ptr->exit_stack[sh_ptr->stack_ptr] = EXIT_SUCCESS;
                printf("\n");
            } else {
                sh_ptr->exit_stack[sh_ptr->stack_ptr] = EXIT_FAILURE;
                fprintf(stderr, "no such directory\n");
            }
            closedir(mydir);
            free(dp);

        } else {
            fprintf(stderr, "no such command\n");
            sh_ptr->exit_stack[sh_ptr->stack_ptr] = EXIT_F;
        }
    } else if(!strcmp(sh_ptr->arr[0], "history")) {
        if (sh_ptr->arr_size == 1) {
            print_history(sh_ptr);
        } else {
            fprintf(stderr, "no such command\n");
            sh_ptr->exit_stack[sh_ptr->stack_ptr] = EXIT_F;
        }
    } else if(!strcmp(sh_ptr->arr[0], "exit")) {
        if (sh_ptr->arr_size == 1) {
            exit_shell();
        } else {
            fprintf(stderr, "no such command\n");
            sh_ptr->exit_stack[sh_ptr->stack_ptr] = EXIT_F;
        }
    // }
    // sh_ptr->exit_stack[sh_ptr->stack_ptr] = &sh_ptr->exit_status;
    }
}

