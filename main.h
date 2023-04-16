#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t getline(char **restrict lineptr, size_t *restrict n,FILE *restrict stream);
int main(int ac, char **av);
char *strtok(char *restrict str, const char *restrict delim);
void execmd(char **av);
#endif
