#ifndef __DH_HISTORY_H__
#define __DH_HISTORY_H__
#include "smash.h"

typedef struct {
    char *cmd;
    int exit_status;
}Cmd;

void init_history(Shell *sh_ptr);

void add_history(Shell *sh_ptr, char *command, int index);

void clear_history(Shell *sh_ptr);

void print_history(Shell *sh_ptr);

#endif