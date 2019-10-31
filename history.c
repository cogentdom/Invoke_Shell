#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"
#include "smash.h"

void add_history(Shell *sh_ptr, char *command, int index) {
    if (sh_ptr->stack_ptr == HISTORY_SIZE - 1) {
        sh_ptr->stack_ptr = 0;
        sh_ptr->stack[sh_ptr->stack_ptr] = command;
        sh_ptr->arr[index] = NULL;
        // memset(sh_ptr->arr, 0, sizeof(sh_ptr->arr));
    } else if (sh_ptr->stack[sh_ptr->stack_ptr] == NULL) {
        sh_ptr->stack[sh_ptr->stack_ptr] = command;
        sh_ptr->count = 1;
        sh_ptr->arr[index] = NULL;
        // memset(sh_ptr->arr, 0, sizeof(sh_ptr->arr));
        sh_ptr->stack_ptr = 0;    
    }else {
        sh_ptr->stack_ptr++;
        sh_ptr->stack[sh_ptr->stack_ptr] = command;
        sh_ptr->arr[index] = NULL;
        // memset(sh_ptr->arr, 0, sizeof(sh_ptr->arr));
        if (sh_ptr->count < HISTORY_SIZE) {
            sh_ptr->count++;
        }
    }

}

void init_history(Shell *sh_ptr) {
    sh_ptr->arr[0] = NULL;
    sh_ptr->stack[0] = NULL;
    sh_ptr->exit_stack[0] = -1;
    Exit = 0;
    sh_ptr->stack_ptr = 0;
}

void clear_history(Shell *sh_ptr) {
    memset(sh_ptr->arr, 0, sizeof(sh_ptr->arr));
    init_history(sh_ptr);
    sh_ptr->stack_ptr = 0;
    sh_ptr->count = 0;
    sh_ptr->exit_stack[sh_ptr->stack_ptr] = EXIT_SUCCESS; 
}

void print_history (Shell *sh_ptr) {
    int tmp_ptr = sh_ptr->stack_ptr;
    printf("\n");
    if (tmp_ptr == sh_ptr->count -1 || sh_ptr->count < HISTORY_SIZE) {
        for (int i=0; i <(sh_ptr->count -1); i++) {
            printf("%d [%d] %s\n", i+1, sh_ptr->exit_stack[i], sh_ptr->stack[i]);
        }
    } else {
        tmp_ptr++;
        for (int i=0; i <(sh_ptr->count -1); i++) {
            printf("%d [%d] %s\n", i+1, sh_ptr->exit_stack[tmp_ptr], sh_ptr->stack[tmp_ptr]);
            printf("%s\n", sh_ptr->stack[tmp_ptr]);
            if (tmp_ptr == sh_ptr->count -1) {
                tmp_ptr = 0;
            } else {
                tmp_ptr++;
            }
        }
    }
    printf("\n");
}
