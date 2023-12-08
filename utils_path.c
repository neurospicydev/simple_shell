#include "shell.h"
#include <sys/stat.h>

/**
 * get_cmd_path - Determines the path of command
 * @name: Name/path of command
 *
 * Return: Path
 */
char *get_cmd_path(char *name)
{
	int len = _strlen(name), i = 0;
	char *bin_path = "/bin/", *path;
	int path_len;
	struct stat st;

	if (name == NULL)
		return (NULL);
	if (stat(name, &st) == 0)
		return (name);

	/* Checks if path (contains char /)*/
	for (i = 0; i < len; i++)
	{
		if (name[i] == '/')
			return (name);
	}

	path_len = _strlen(bin_path) + _strlen(name) + 1;
	path = malloc((path_len) * sizeof(char));
	if (path == NULL)
	{
		/* TODO: Log malloc error */
		free(name);
		return (NULL);
	}
	_memset(path, '\0', path_len);
	/* is not path, then concat bin_path */
	path = _strcat(path, bin_path);
	path = _strcat(path, name);

	/* Free the name here */
	free(name);
	/* cmd path not found */
	if (stat(path, &st) != 0)
	{
		free(path);
		return (NULL);
	}
	return (path);
}
