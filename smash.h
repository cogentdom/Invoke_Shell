#ifndef __DH_SMASH_H__
#define __DH_SMASH_H__
#define NUMBER_OF_ARGUMENTS 10
#define COMMAND_RECALL 10
#define MAXLINE 4096

typedef struct{
    char *arr[NUMBER_OF_ARGUMENTS];
    char *stack[COMMAND_RECALL];
    int *exit_stack[COMMAND_RECALL];
    int stack_ptr;
    int exit_status;
    int count;
}Shell;


void loop();
void init_shell();
void executeCommand(Shell *ptr);


#endif