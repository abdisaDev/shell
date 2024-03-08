#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int counter, i = 0;
    char *command = argv[1];
    char * arg_vals[argc];
    int status_code;

    for (counter = 1; counter < argc; counter++, i++)
    {
        arg_vals[i] = argv[counter];
    }

    status_code = execvp(command, arg_vals);

    if (status_code == -1)
    {
        printf("Invalid Parameter");
        exit (1);
    }
    
    return (0);
}