#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int  counter = 1;
    char string[sizeof(char) * 200];
    char * arg_vals [sizeof(string)];
    char *command;
    int status_code;

    
    printf("($): ");
    fgets(string,  3000, stdin);

    command  = strtok(string, " ");
    arg_vals[0] = command;
    
    while(command != NULL)
    {
        command = strtok(NULL, " ");
        arg_vals[counter] = command;
        counter++;
    }
    
   
    status_code = execvp(arg_vals[0], arg_vals);

   if(status_code == -1)
   {
    printf("Invalid Command!");
    exit(1);
   }
    
    return (0);
}