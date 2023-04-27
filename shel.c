#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void execmd(char **av);
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

	if (!isatty(STDIN_FILENO)) {
		/* Input is coming from a pipe */
		if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
			perror("error reading input");
			exit(1);
		}
	} else {
		/* Input is coming from a terminal */
		while (1)
		{
			printf("%s ", prompt);
			totalread = getline(&buffer, &n, stdin);
			if (totalread == -1)
			{
				perror("exiting\n");
				return (-1);
			}
			if (strcmp(buffer, "exit\n") == 0)
			{
				exit(0);
			}
			buffer2 = malloc(sizeof(char) * strlen(buffer) + 1);
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
				av[i] = malloc(sizeof(char) * strlen(split) + 1);
				strcpy(av[i], split);
				split = strtok(NULL, del);
			}
			av[i] = NULL;
			execmd(av);
			free(av);
			free(buffer2);
		}
	}
	free(buffer);

	return (0);
}
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
