#include "shell.h"

/**
 * print_env - A function that prints environment variables
 * @envname: pointer to the address of the path name
 *
 * Return: void functions have no return value
 */

void print_env(char *envname)
{
	char *envvalue = _getenv(envname);

	if (envvalue != NULL)
		printf("%s:%s\n", envname, envvalue);
	else
		printf("%s:(null)\n", envname);
}
