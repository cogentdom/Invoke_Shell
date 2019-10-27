#ifndef __DH_SMASH_H__
#define __DH_SMASH_H__
#define NUMBER_OF_ARGUMENTS 10
#define COMMAND_RECALL 10

typedef struct{
    char *arr[NUMBER_OF_ARGUMENTS];
    char *command;
    char *stack[COMMAND_RECALL];
    int exit_status;
    int count;
}Shell;

int Index = 1;
void loop();
void init_commands();
void executeCommand(Shell *ptr);
// extern char *arr[NUMBER_OF_ARGUMENTS];

#endif