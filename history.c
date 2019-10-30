#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"
#include "smash.h"

void add_history(Shell *sh_ptr, char *command, int index) {
    if (sh_ptr->stack_ptr == HISTORY_SIZE - 1) {
        sh_ptr->stack_ptr = 0;
        sh_ptr->stack[sh_ptr->stack_ptr] = command;
        sh_ptr->arr[index] = '\0';
    } else if (sh_ptr->stack[sh_ptr->stack_ptr] == NULL) {
        sh_ptr->stack[sh_ptr->stack_ptr] = command;
        sh_ptr->count = 1;
        sh_ptr->arr[index] = '\0';
        sh_ptr->stack_ptr = 0;    
    }else {
        sh_ptr->stack_ptr++;
        sh_ptr->stack[sh_ptr->stack_ptr] = command;
        sh_ptr->arr[index] = '\0';
        if (sh_ptr->count < HISTORY_SIZE) {
            sh_ptr->count++;
        }
    }

}


void print_history (Shell *sh_ptr) {
    int tmp_ptr = sh_ptr->stack_ptr;
    // printf("*************Temp pointer val = %d\n", tmp_ptr);
    // for (int i=0; i<(sh_ptr->count); i++) {
    //     printf("%s\n", sh_ptr->stack[i]);
    // }

    // printf("*************Temp pointer val = %d\n", tmp_ptr);

    if (tmp_ptr == sh_ptr->count -1 || sh_ptr->count < HISTORY_SIZE) {
        for (int i=0; i <(sh_ptr->count -1); i++) {
            printf("%d [%d] %s\n", i+1, 0, sh_ptr->stack[i]);
            // printf("%s\n", sh_ptr->stack[i]);
        }
    } else {
        tmp_ptr++;
        for (int i=0; i <(sh_ptr->count -1); i++) {
            printf("%d [%d] %s\n", i+1, 0, sh_ptr->stack[tmp_ptr]);
            // printf("%s\n", sh_ptr->stack[tmp_ptr]);
            if (tmp_ptr == sh_ptr->count -1) {
                tmp_ptr = 0;
            } else {
                tmp_ptr++;
            }
        }
    }

        
}
