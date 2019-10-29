#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"
#include "smash.h"

void add_history(char *cmd, int exitStatus) {
   

}


void print_history (Shell *sh_ptr) {
    int tmp_ptr = sh_ptr->stack_ptr;
    printf("*************Temp pointer val = %d\n", tmp_ptr);
    if (sh_ptr->count == COMMAND_RECALL) {  // Condition for a full history stack
        if (tmp_ptr == sh_ptr->count -1) {
            tmp_ptr = 0;
        } else {
            tmp_ptr++;
        }
    } else {
        tmp_ptr = 0;
    }
    for (int i=0; i <(sh_ptr->count); i++) {
        if (tmp_ptr == sh_ptr->count -1) {
            printf("%s\n", sh_ptr->stack[tmp_ptr]);
            tmp_ptr = 0;
        } else {
            printf("%s\n", sh_ptr->stack[tmp_ptr]);
            tmp_ptr++;
        }
        
    }
}
