#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

Cmd init_hist() {
    Cmd *hist_ptr = malloc(sizeof(Cmd));
    // hist_ptr->stack[0] = NULL;
    // hist_ptr->count = 0;
    return *hist_ptr;
}

char* add_history(Cmd *cmd_ptr) {
    // ptr->stack[ptr->count] = cp;
    // ptr->count++;
    // int i = &cmd_ptr->index;
    // sh_ptr->arr[cmd_ptr->index];
    // int *out = &cmd_ptr->exit_status;
    char *command = cmd_ptr->cmd;
    // int *out = i;
     printf ("%s \n", command);
     char *formatted = "TEXT";
    return formatted;
}
void history(Cmd *ptr) {
    
}
