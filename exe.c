#include "main.h"

/**
 * execmd - A function which gets the env
 * @av: The argument
 */
void execmd(char **av)
{
	char *md = NULL;

	if (av)
	{
		md = av[0];
		if (execve(md, av, NULL) == -1)
		{
			perror("invalid");
		}
	}
}
