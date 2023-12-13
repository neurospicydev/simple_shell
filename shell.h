#ifndef SHELL_H
#define SHELL_H
#define MAX_BUF_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdbool.h>
#define PATH_MAX 4096 /* # chars in a path name including nul */

extern char **environ;

#define NOT_FOUND "Not found\n"

/**
 * struct Node - A structure representing a node
 * in a linked list
 * @dir: Pointer to the address of the string
 * containing the directory associated with the node
 * @next: Pointer to the address of the next node
 * in the linked list
 */

struct Node
{
	char *dir;
	struct Node *next;
};


char *_getenv(char *envname);
int _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
void print_env(char *envname);
char *_strtok(char *str, const char *delim);
void print_env(char *envname);
char *_strtok(char *str, const char *delim);
void addNode(struct Node **head, const char *dir);
struct Node *build_linked_list(void);
void print_list(struct Node *head);
void free_list(struct Node *head);
int _setenv(const char *name, const char *value, int overwrite);

/* UTILS - SHELL */
char **build_cmd_array(char *line, int *token_count);
int preprocess_cmd(char *program_name, char **cmd, int *token_count);
int handle_cmd(char *program_name, char **cmd, int *token_count);
void handle_exit(char *line, char **cmd, int *token_count);
int handle_env_builtins_cmd(char **cmd, int *token_count);
int handle_cd_builtins_cmd(char **cmd, int *token_count);

/* UTILS - PATH */
bool is_path(char *str);
bool is_existing_path(char *str);
char *get_cmd_path(char *name);

/* UTILS - DEV */
void print_string_array(char **arr, size_t len);
void _printenv(void);

/* UTILS - ENVIRONMENT */
int _getenv_idx(const char *name);
size_t getenv_size(void);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
char *_getenv(char *envname);

/* UTILS - STRING */
int _strlen(char *str);
char *_strtok(char *str, const char *delim);
char *_strcat(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strncat(char *dest, char *src, int n);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(const char *s1, const char *s2);

/* UTILS - MEMORY MANAGEMENT */
void free_string_array(char **array, size_t len);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memset(char *s, char b, unsigned int n);

/* UTILS - PATH */
char *get_cmd_path(char *name);

/* UTILS - ERRORS */
void err_invalid_argc(char *process_name, int *status);

ssize_t _getline(char **lineptr, size_t *n);

#endif /* SHELL_H */
