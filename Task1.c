#include "main.h"
void execmd(char **av);
/**
 * main - Creates a simple shell
 * @ac: number of arguments
 *@av: The arguments
 * Return: value of the last executed command
 */
int main(int ac, char **av)
{
	char *prompt = "(simpleshell)$";
	ssize_t totalread;
	char *buffer = NULL, *buffer2 = NULL;
	size_t n = 0;
	char *split;
	char *del = " \n";
	int splitcount = 0;
	int i;
	(void)ac;

	while (1)
	{
		printf("%s ", prompt);
		totalread = getline(&buffer, &n, stdin);
		if (totalread == -1)
		{
			perror("exiting\n");
			exit (-1);
		}
		if (strcmp(buffer, "exit\n") == 0)
		{
			exit(0);
		}
		buffer2 = malloc(sizeof(char) * totalread);
		if (buffer2 == NULL)
		{
			perror("no memory");
			exit (1);
		}
		strcpy(buffer2, buffer);
		split = strtok(buffer, del);

		while (split != NULL)
		{
			splitcount++;
			split = strtok(NULL, del);
		}
		splitcount++;
		av = malloc(sizeof(char *) * splitcount);

		split = strtok(buffer2, del);
		for (i = 0; split != NULL; i++)
		{
			av[i] = malloc(sizeof(char) * strlen(split));
			strcpy(av[i], split);
			split = strtok(NULL, del);
		}
		av[i] = NULL;
		execmd(av);
		free(av);
	}
	free(buffer2);
	free(buffer);

	return (0);
}
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
			exit(1);
		}
	}
}

