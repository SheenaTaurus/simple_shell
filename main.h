#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int main(int ac, char **av);
char *strtok(char *str, const char *delim);
extern char **en;
char *get_path(char *command);
void execmd(char **av);
#endif
