#include "shell.h"

/**
 * is_path - Check if string is formatted as path
 * @test_path: Path to be tested
 *
 * Return: true if is path, false otherwise
 */
bool is_path(char *test_path)
{
	int len = _strlen(test_path), i = 0;

	/* Checks if path (contains char /)*/
	for (i = 0; i < len; i++)
	{
		if (test_path[i] == '/')
			return (true);
	}

	return (false);
}

/**
 * is_existing_path - Check if path exist
 * @test_path: Path to be tested
 *
 * Return: true if is path, false otherwise
 */
bool is_existing_path(char *test_path)
{
	struct stat st;

	if (test_path == NULL)
		return (false);

	/* cmd path found */
	if (stat(test_path, &st) == 0)
		return (true);

	return (false);
}

/**
 * get_cmd_path - Determines the path of command
 * @name: Name/path of command
 *
 * Return: Path
 */
char *get_cmd_path(char *name)
{
	char *bin_path = "/bin/", *path;
	int path_len;

	if (name == NULL)
		return (NULL);

	if (is_existing_path(name) || is_path(name))
		return (strdup(name));

	path_len = _strlen(bin_path) + _strlen(name) + 1;
	path = malloc((path_len) * sizeof(char));
	if (path == NULL)
	{
		/* TODO: Log malloc error */
		return (NULL);
	}

	_memset(path, '\0', path_len);
	/* is not path, then concat bin_path */
	path = _strcat(path, bin_path);
	path = _strcat(path, name);

	/**
	 * This is the ILLEGAL free causing all issues
	 free(name);
	 */

	return (path);
}
