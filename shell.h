#ifndef SHELL_H
#define SHELL_H
#define MAX_BUF_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
char *_getenv(char *envname);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, size_t n);
void print_env(char *envname);

#endif /* SHELL_H */
