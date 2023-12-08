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
void addNode(struct Node **head, const char *dir);
struct Node *build_linked_list(void);
void print_list(struct Node *head);
void free_list(struct Node *head);
int _setenv(const char *name, const char *value, int overwrite);

#endif /* SHELL_H */
