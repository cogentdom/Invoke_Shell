#ifndef __DH_HISTORY_H__
#define __DH_HISTORY_H__
#define COMMAND_RECALL 10
#include "smash.h"

typedef struct {
    char *cmd;
    int *exit_status;
    int *index;
}Cmd;

Cmd init_hist();
char* add_history(Cmd *cmd);
// void history_add( *ptr, char *cp);
void history(Cmd *ptr);

#endif