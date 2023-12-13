#include "shell.h"

/**
 * build_linked_list - A function that prints each directory
 * within the path variable
 *
 * Return: void functions have no return value
 */

struct Node *build_linked_list(void)
{
	struct Node *head = NULL;
	char *path = _getenv("PATH");
	char *tok;

	if (path == NULL)
	{
		printf("PATH variable not set.\n");
	}
	/* Tokenise using strtok */
	tok = _strtok(path, ":");

	while (tok != NULL)
	{
		addNode(&head, tok);
		tok = _strtok(NULL, ":");
	}
	return (head);
}
