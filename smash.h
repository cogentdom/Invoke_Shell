#ifndef __DH_SMASH_H__
#define __DH_SMASH_H__
#define NUMBER_OF_ARGUMENTS 10

typedef struct{
    char *arr[NUMBER_OF_ARGUMENTS];
    char *comnd;
    FILE *fp;
}Cmd;
void loop();
void executeCommand(Cmd *ptr);
// extern char *arr[NUMBER_OF_ARGUMENTS];

#endif