#include "main.h"

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
	char *buffer = NULL;
	size_t n = 0;
	char *split;
	char *del = " \n";
	int splitcount = 0;
	int i;
	pid_t child;
	int status;
	(void)ac;

	while (1)
	{
		printf("%s ", prompt);
		totalread = getline(&buffer, &n, stdin);
		if (totalread == -1)
		{
			perror("exiting\n");
			return (-1);
		}
		buffer[strcspn(buffer, "\n")]= 0;
		split = strtok(buffer, del);

		while (!split)
		{
			continue;
		}
		splitcount = 1;
		while (strtok(NULL, del))
		{
			splitcount++;
		}
		av = malloc((splitcount + 1) * sizeof(char *));

		while (!av)
		{
			perror("memoery not alloacated");
			exit(EXIT_FAILURE);
		}

		i = 0;
		av[i++] = split;

		while ((split = strtok(NULL, del)))
		{
			av[i++] = split;
		}
		av[i] = NULL;

		child = fork();
		if (child == -1)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		if (child == 0)
		{
			execvp(av[0], av);
			perror("command does not exist");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(child, &status, 0);
		}
		free(av);
	}

	free(buffer);
	return (0);
}

