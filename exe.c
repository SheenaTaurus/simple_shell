#include "main.h"

/**
 * execmd - A function which gets the env
 * @av: The argument
 */
void execmd(char **av)
{
	char *md = NULL, *actual_command = NULL;

	if (av)
	{
		md = av[0];
		actual_command = get_path(md);
		if (execve(actual_command, av, NULL) == -1)
		{
			perror("invalid");
		}
	}
}
