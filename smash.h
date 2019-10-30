#ifndef __DH_SMASH_H__
#define __DH_SMASH_H__
#define NUMBER_OF_ARGUMENTS 10
#define HISTORY_SIZE 10
#define MAXLINE 4096

typedef struct{
    char *arr[NUMBER_OF_ARGUMENTS];
    char *stack[HISTORY_SIZE];
    int *exit_stack[HISTORY_SIZE];
    int stack_ptr;
    int exit_status;
    int count;
}Shell;

int Exit;
int loop();
void init_shell();
void executeCommand(Shell *ptr);


#endif