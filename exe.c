#include "main.h"

/**
 * execmd - A function which gets the env
 * @av: The argument
 */

void execmd(char **av)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0)
    {
        perror("fork error");
        exit(1);
    }
    if (pid == 0)
    {
        if (execve(av[0], av, NULL) == -1)
        {
            perror("execve error");
            exit(1);
        }
    }
    else
    {
        wait(&status);
    }
}
