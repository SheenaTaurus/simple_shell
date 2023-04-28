#include "main.h"

/**
 * execmd - A function which gets the env
 * @av: The argument
 */
void execmd(char **av)
{
	pid_t pid;
	char *actual_command = get_path(av[0]);

	if (actual_command == NULL)
	{
		printf("%s : not found\n", av[0]);
		return;
	}
	
	pid = fork();
	if (pid == -1)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(actual_command, av, NULL);
		perror("error executing");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
	free(actual_command);

}

