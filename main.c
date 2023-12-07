#include "shell.h"

/**
 * main - Entry point of shell
 * @ac: argument count
 * @argv: Argument vector
 * @env: Environmental varibales
 *
 * Return: 0 (sucess), otherwise -1
 */
int main(int ac, char **argv, char **env)
{
	ssize_t bytes_read;
	char *line = NULL;
	size_t length = 0;
	char **cmd = NULL;
	int token_count = 0;
	(void)ac;
	(void)env;

	while ((bytes_read = getline(&line, &length, stdin)) != -1)
	{
		/* TODO: Trim line for leading, double and tailing whitepaces*/
		line[bytes_read - 1] = '\0';

		/* Build command array */
		cmd = build_cmd_array(line, &token_count);

		/* TODO: get return value to exit if necessary */
		handle_cmd(argv[0], cmd, &token_count);
	}

	free(line);

	return (0);
}
