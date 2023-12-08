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

/* UTILS - SHELL */
char **build_cmd_array(char *line, int *token_count);
int handle_cmd(char *program_name, char **cmd, int *token_count);

/* UTILS - DEV */
void print_string_array(char **arr, size_t len);
void _printenv(void);

/* UTILS - ENVIRONMENT */
int _getenv_idx(const char *name);
size_t getenv_size(void);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

/* UTILS - STRING */
int _strlen(char *str);
char *_strtok(char *str, const char *delim);
char *_strcat(char *dest, char *src);

/* UTILS - MEMORY MANAGEMENT */
void free_string_array(char **array, size_t len);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memset(char *s, char b, unsigned int n);

/* UTILS - PATH */
char *get_cmd_path(char *name);

#endif /* SHELL_H */
