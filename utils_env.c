#include "shell.h"

/**
 * _getenv_idx - Retrieves an environmental variable index in environ
 * @name: Name/key of the env variable to get
 *
 * Return: The environmental variable index in environ array
 */
int _getenv_idx(const char *name)
{
	char *key;
	int i = 0;

	while (environ[i] != NULL)
	{
		key = _strtok(environ[i], "=");
		if (strcmp(name, key) == 0)
		{
			free(key);
			return (i);
		}
		free(key);
		i++;
	}

	return (-1);
}

/**
 * getenv_size - Get size of environ array
 * Return: Size oof environ array
 */
size_t getenv_size(void)
{
	size_t size = 0;

	while (environ[size] != NULL)
		size++;

	return (size);
}

/**
 * _getenv - A function that returns the value
 * of the environment variable
 * @envname: pointer to a character constant
 *
 * Return: Pointer to the corresponding value
 * of the env variable, or NULL if not found
 */

char *_getenv(char *envname)
{
	char **env;
	int len;

	if (envname == NULL || environ == NULL || envname[0] == '\0')
		return (NULL);

	len = _strlen(envname);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, envname, len) == 0 && (*env)[len] == '=')
			return (*env + len + 1); /* Return the value part */
	}
	return (NULL);
}

/**
 * _setenv - changes or adds an environment variable
 * @name: name of variable
 * @value: Value of variable
 * @overwrite: Overwrite the environmental variable
 *
 * Return: zero on success, or -1 on error,
 * with errno set to indicate the cause of the error.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	/* +2 for chars '=' and '\0' */
	int length = strlen(name) + strlen(value) + 2;
	char *new = malloc(length * sizeof(char));
	size_t environ_size;
	int idx;
	(void)overwrite;

	_memset(new, '\0', length);
	_strcat(new, (char *)name);
	_strcat(new, "=");
	_strcat(new, (char *)value);

	idx = _getenv_idx(name);
	if (idx >= 0)
	{
		if (overwrite > 0)
			environ[idx] = _strdup(new);
	}
	else
	{
		environ_size = getenv_size();
		environ[environ_size] = _strdup(new);
		environ[environ_size + 1] = NULL;
	}

	free(new);
	return (0);
}

/**
 * _unsetenv - deletes the variable name from the environment
 * @name: Name of the env variable
 *
 * Return: zero on success, or -1 on error,
 * with errno set to indicate the cause of the error.
 */
int _unsetenv(const char *name)
{
	int idx = _getenv_idx(name);

	if (idx >= 0)
	{
		while (environ[idx] != NULL)
		{
			environ[idx] = environ[idx + 1];
			idx++;
		}
	}

	return (0);
}
