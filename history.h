#ifndef __DH_HISTORY_H__
#define __DH_HISTORY_H__
#include "smash.h"

typedef struct {
    char *cmd;
    int exit_status;
}Cmd;

void init_history(void);

void add_history(char *cmd, int exitStatus);

void clear_history(void);

void print_history(Shell *sh_ptr);

#endif