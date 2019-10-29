#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "smash.h"
#include "history.h"


void to_stack (Shell *sh_ptr, char *command, int index);


void loop(Shell *sh_ptr) {

    char bfr[MAXLINE];
    char *toke;
    fputs("$ ", stderr);    //Output the first prompt
    

    /////////////////////////////////////////////
    //
    // Loops while shell is open
    //
    /////////////////////////////////////////////
    while (fgets(bfr, MAXLINE, stdin) != '\0') {
        // Marks the end of input stream with null character
        if (bfr[strlen(bfr) - 1] == '\n') { //Replace newline character with null character
            bfr[strlen(bfr) - 1] = '\0';
        } else if (bfr[strlen(bfr) - 1] != '\0') {  //Append null character to input
            bfr[strlen(bfr)] = '\0';
        }   
        

        /////////////////////////////////////////////
        //
        // Loops through individual commands
        //
        /////////////////////////////////////////////
        char *command = malloc(MAXLINE);
        int index = 0;
        toke = strtok(bfr, " ");    //Takes command and uses a speace as delimeter
        while((toke != NULL) && (*toke != '\n')) {
            if (*toke == ' ') {  //Prevents an input with consecutive spaces
                fprintf(stderr, "Error: invalid input");
                break;
            } else if (index == 0) {
                strcpy(command, toke);
                sh_ptr->arr[index] = toke;
                toke = strtok(NULL, " ");
                index++;
            } else {
                sh_ptr->arr[index] = toke;
                strcat(command, " ");
                strcat(command, toke);
                toke = strtok(NULL, " ");
                index++;
            }
        }

        if (index != 0) {   // Resets 'loop()' when user inputs '\n'
            to_stack(sh_ptr, command, index);
            executeCommand(sh_ptr);
            
        }
        sh_ptr->arr[0] = NULL;
        fputs("$ ", stderr);
    }
    
}

int main(void) {

    Shell *sh_ptr = malloc(sizeof(Shell));
    init_shell(sh_ptr);
    
    loop(sh_ptr);
    // free(sh_ptr);
    
    return 0;
}

void to_stack (Shell *sh_ptr, char *command, int index) {
    if (sh_ptr->stack_ptr == COMMAND_RECALL - 1) {
        sh_ptr->stack_ptr = 0;
        sh_ptr->stack[sh_ptr->stack_ptr] = command;
        sh_ptr->arr[index] = '\0';
    } else if (sh_ptr->stack[sh_ptr->stack_ptr] == NULL) {
        sh_ptr->stack[sh_ptr->stack_ptr] = command;
        sh_ptr->count = 0;
        sh_ptr->arr[index] = '\0';
        sh_ptr->stack_ptr = 0;    
    }else {
        sh_ptr->stack_ptr++;
        sh_ptr->stack[sh_ptr->stack_ptr] = command;
        sh_ptr->arr[index] = '\0';
        if (sh_ptr->count < 10) {
            sh_ptr->count++;
        }
    }
}