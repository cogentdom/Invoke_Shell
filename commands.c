#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <dirent.h>
#include "smash.h"
#include "history.h"
#define EXIT_F 127

void changeDir(Shell *sh_ptr);

void listDir(Shell *sh_ptr);

void history(Shell *sh_ptr);

void init_shell(Shell *sh_ptr) {
    init_history(sh_ptr);
    sh_ptr->env = getenv(ENVIORMENT);
}

void exit_shell(void) {
    Exit = 1;
}

void executeCommand(Shell *sh_ptr) {
    if (!strcmp(sh_ptr->arr[0], "cd")) {
        changeDir(sh_ptr);
    } else if (!strcmp(sh_ptr->arr[0], "ls")) {
        listDir(sh_ptr);
    } else if(!strcmp(sh_ptr->arr[0], "history")) {
        history(sh_ptr);
    } else if(!strcmp(sh_ptr->arr[0], "exit")) {
        if (sh_ptr->arr_size == 1) {
            exit_shell();
        } else {
            fprintf(stderr, "Error: no such command\n");
            sh_ptr->exit_stack[sh_ptr->stack_ptr] = EXIT_F;
        }
    }
}

void changeDir(Shell *sh_ptr) {
    if (sh_ptr->arr_size == 2) {
        int complete = chdir(sh_ptr->arr[1]);
        if (complete == 0) {
            char* cur_dir = getcwd(NULL, MAXLINE);
            sh_ptr->exit_stack[sh_ptr->stack_ptr] = EXIT_SUCCESS;
            printf("%s\n", cur_dir);
        } else {
            perror(sh_ptr->arr[1]);
            sh_ptr->exit_stack[sh_ptr->stack_ptr] = EXIT_FAILURE;
        }
    } else if(sh_ptr->arr_size > 2) {
        fprintf(stderr, "Error: no such command\n");
        sh_ptr->exit_stack[sh_ptr->stack_ptr] = EXIT_F;
    }
}

void listDir(Shell *sh_ptr) {
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
            fprintf(stderr, "Error: no such directory\n");
        }
        closedir(mydir);
        free(dp);
    } else {
        fprintf(stderr, "Error: no such command\n");
        sh_ptr->exit_stack[sh_ptr->stack_ptr] = EXIT_F;
    }
}

void history(Shell *sh_ptr) {
    if (sh_ptr->arr_size == 1) {
            print_history(sh_ptr);
    } else {
            fprintf(stderr, "Error: no such command\n");
            sh_ptr->exit_stack[sh_ptr->stack_ptr] = EXIT_F;
    }
}

