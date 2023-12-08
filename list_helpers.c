#include "shell.h"

/**
 * addNode - A function that adds a new node to the end of a linked list
 * @head: Pointer to the head of the linked list.
 * @dir:  pointer to the address of the string containing
 * the directory to be added to the new node.
 *
 * Return: void functions have no return value
 */

void addNode(struct Node **head, const char *dir)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	struct Node *currentNode;
	char err[] = "ERROR: Failed to allocate memory.\n";

	if (newNode == NULL)
	{
		write(2, err, _strlen(err));
		exit(EXIT_FAILURE);
	}

	/* Allocate memory to each directory and copy value*/
	newNode->dir = strdup(dir);

	if (newNode->dir == NULL)
	{
		write(2, err, _strlen(err));
		free(newNode);
		exit(EXIT_FAILURE);
	}

	/* set next pointer (Node) to NULL */
	newNode->next = NULL;

	/* handle the list if it is empty*/
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		currentNode = *head;
		while (currentNode->next != NULL)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}

}

/**
 * print_list - A function that prints the contents
 * of a linked list
 * @head: Pointer to the head of the linked list
 *
 * Return: void functions have no return value
 */

void print_list(struct Node *head)
{
	struct Node *curr = head;

	while (curr != NULL)
	{
		printf("%s\n", curr->dir);
		curr = curr->next;
	}
}

/**
 * free_list - A function that frees the memory allocated
 * to each node in a linked list, including
 * the directory strings stored in each node.
 * @head: Pointer to the address of the head
 * of the linked list
 *
 * Return: void functions have no return value
 */

void free_list(struct Node *head)
{
	struct Node *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->dir);
		free(tmp);
	}
}
